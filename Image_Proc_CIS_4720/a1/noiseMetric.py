import numpy
import scipy
import scipy.ndimage.filters as nd
import Image
import matplotlib.pyplot as plt

"""
Function to calculate Noise Amplification Index (NAI)

Input 
Im: Gray-scale Original (reference) image
Ie: Gray-scale enhanced image

Output 
nai: metric to estimate NAI

Description 
noiseNAI calculate Noise Amplification Index (NAI)

Ref(s):

Sakellaropoilos, P., Costaridou, L., Panayiotakis, G., "A wavelet-
based spatially adaptive method for mammographic contrast enhancement", 
Physics in Medicine and Biology, 2003, Vol.48, pp.787-803.

Rank, K., Landl, M., Unbehauen, R., "Estimation of image noise variance", 
IEE Proceedings Vision, Image and Signal Processing, 1999, Vol.146, pp.80-84.

Notes:
- Converted from MATLAB, January 2015
- Last Modified: Jan 29, 2015
"""

def noiseNAI(imgD,imgS):

    sdn_o = noiseRankNEI(imgD)
    sdn_e = noiseRankNEI(imgS)
    
    #print "Rank's NEI Original = ", sdn_o
    #print "Rank's NEI Enhanced = ", sdn_e
    
    nai = sdn_o / sdn_e

    #print "The noise amplification index = ", nai
    return nai

"""
Function to calculate Rank's Noise Estimation Index (NEI)

Input 
Im: Gray-scale (uint8)

Output 
rank: metric to estimate NEI

Description 
noiseRankNEI calculates Rank's Noise Estimation Index
A higher value symbolizes increased noise amplification.

Ref(s):
Rank, K., Landl, M., Unbehauen, R., "Estimation of image noise variance", 
IEE Proceedings Vision, Image and Signal Processing, 1999, Vol.146, pp.80-84.

Notes:
- Converted from MATLAB, January 2015
- Last Modified: Jan 29, 2015
"""

def noiseRankNEI(img, wsize=1):

    img = img.astype(float)
    dx,dy = img.shape
    
    # Step 1: Suppression
    coeff = 1.0/numpy.sqrt(2.0)
        
    # Vertical filter Y1 (Eq.2)
    Y1 = numpy.zeros([dx,dy])
    for i in range(0,dx-1):
        for j in range(0,dy):
            Y1[i,j] = coeff * (img[i+1,j] - img[i,j])
        
    # Horizontal filter Y2 (Eq.3)
    Y2 = numpy.zeros([dx,dy])
    for i in range(0,dx):
        for j in range(0,dy-1):
            Y2[i,j] = coeff * (Y1[i,j+1] - Y1[i,j])
 
    #print "Step 1 complete."
    
    # Step 2: Compute the histogram of local standard deviations
    
    L = (2*wsize) + 1  # Window size
    Npix = L**2        # Number of pixels in the window

    mu = numpy.zeros([dx,dy]);
    sigma = numpy.zeros([dx,dy]);

    for i in range(wsize,dx-wsize+1):
        for j in range(wsize,dy-wsize+1):
            tempMu = 0
            tempSigma = 0
            # Calculate the local mean (Eq.5)
            winL = Y2[i-wsize:i+wsize+1,j-wsize:j+wsize+1]
            mu[i,j] = numpy.mean(winL,dtype=numpy.float32)
            # Calculate an estimate of the local noise variance (Eq.4)
            sigma[i,j] = numpy.var(winL)

    #print "Step 2a complete : (Local Stdev)"

    sigmaSQ = numpy.sqrt(sigma)
    
    Hmax = numpy.uint16(numpy.ceil(sigmaSQ.max()))
    h = numpy.zeros(Hmax)

    # Create a "floating-point" histogram using range-based bins (Eq.7)
    alpha = 1

    h[0]= ((sigmaSQ >= 0) & (sigmaSQ <= 0.5)).sum()

    for k in range(1,Hmax):
        h[k] = ((sigmaSQ >= (k-0.5)) & (sigmaSQ < (k+0.5))).sum()

    #print "Step 2b complete : (Histogram creation)"

    # Step 3: Evaluation of the histogram
    # Calculate the mean square value of the histogram (Eq.8)
    sumK = 0.0

    for k in range(1,Hmax):
        sumK = sumK + k**2.0 * h[k]
        
    sumh = h.sum()
    nS = sumK / sumh;
    
    # Calculate an initial global estimate for noise variance
    
    GnS = nS / (alpha**2.0)
    
    #print "Step 3 complete: Histogram equaluation"
    
    # Step 4: Fade out
    
    gl = numpy.zeros(Hmax)
    beta = 2.15; # Adjustment parameter

    # Use a soft fade-out (cosine) function to reduce the influence of the original image
    
    lmax = 4
    for l in range(1,lmax+1):     # fade-out process is called iteratively (lmax = 4)
        for k in range(Hmax):
            sl = numpy.sqrt(nS)   # Initial sl from Eq.8
            if (k <= sl):         # (Eq.9)
                gl[k] = 1.0
            elif (k > sl and k <= (beta *sl)):
                T = ((beta-k/sl) / (1.0-beta)) * numpy.pi
                T1 = 1.0 - numpy.cos(T)
                T2 = 0.5 * T1
                gl[k] = T2
            elif (k > (beta*sl)):
                gl[k] = 0.0
        # Calculate an improved value of the mean square
        sumK = 0.0
        sumG = 0.0
        for k in range(Hmax):
            sumK = sumK + k**2.0 * gl[k]*h[k]
            sumG = sumG + gl[k] * h[k]
        nS = sumK/sumG
                
    #print "Step 4 complete: Soft fade-out"

    # Final estimate for the noise variance (Eq.11)
    
    rank = nS / (alpha**2.0);

    return rank

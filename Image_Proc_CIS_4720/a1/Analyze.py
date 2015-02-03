from imenh_lib import *;
from IPmetrics import *;
from noiseMetric import *;
import numpy
import math
import scipy.misc #.ndimage as nd
import scipy.ndimage as nd
import pylab
import os
import datetime as dt
import time
def AnalyzeNoise(str_Imagepath, imageName):
	improvedFolder = "Improved_Images/"

	image=nd.imread(str_Imagepath, flatten=False, mode=None)

	print("Analyzing:"+imageName);#+", using:Alpha-Trimmed-Mean Filter")


	time_Start= time.time()
	improvedImage=enh_alphaTMean(image,0.2,5)
	scipy.misc.imsave( (improvedFolder+"AlphaTrimmed-"+imageName),improvedImage)
	print("Alpha Trimmed analyses Calculation Time: %s seconds" % (time.time()-time_Start) )

	time_Start= time.time()
	improvedImage=enh_truncMedian(image,5)
	scipy.misc.imsave( (improvedFolder+"TruncateMedian-"+imageName),improvedImage)
	print("Truncated Median analyses Calculation Time: %s seconds" % (time.time()-time_Start) )

	time_Start= time.time()
	improvedImage=enh_Median(image,5)
	scipy.misc.imsave( (improvedFolder+"Median-"+imageName),improvedImage)
	print("Median analyses Calculation Time: %s seconds" % (time.time()-time_Start) )

	time_Start= time.time()
	improvedImage=enh_hybridMedian(image,5)
	scipy.misc.imsave( (improvedFolder+"HybridMedian-"+imageName),improvedImage)
	print("Hybrid Median analyses Calculation Time: %s seconds" % (time.time()-time_Start) )




def GetSSIM_Index(str_Imagepath1, str_Imagepath2):
	image1=nd.imread(str_Imagepath1, flatten=False, mode=None)
	image2=nd.imread(str_Imagepath2, flatten=False, mode=None)

	return SSIM(image1, image2)


def GetNAI_Index(str_Imagepath1, str_Imagepath2):
	image1=nd.imread(str_Imagepath1, flatten=False, mode=None)
	image2=nd.imread(str_Imagepath2, flatten=False, mode=None)

	return noiseNAI(image1, image2)	

#Get All Image Files in Noisy_Images
imageList=os.listdir("noisy_images")


image_folder = "noisy_images/"

#Uncomment this to Convert all Images from Noisy_Images to Improved Images
applyFilters 	=False;
calculateSSIM  	=True;
calculateNAI 	=False

if(applyFilters):
	for i in range(0, len(imageList)):
		if(imageList[i]!=".DS_Store"):
			print("IMG="+str(imageList[i]))
			AnalyzeNoise( 'noisy_images/'+imageList[i],imageList[i])



if(calculateSSIM):
	for i in range(0, len(imageList)):
		if(imageList[i]!=".DS_Store"):
			print("IMG="+str(imageList[i]))
			#AnalyzeNoise( 'noisy_images/'+imageList[i],imageList[i])
			#Original Image vs Alpha
			index=GetSSIM_Index('noisy_images/'+imageList[i], 'Improved_Images/AlphaTrimmed-'+imageList[i])
			print("AlphaTrim Index:"+str(index))

			index=GetSSIM_Index('noisy_images/'+imageList[i], 'Improved_Images/TruncateMedian-'+imageList[i])
			print("TruncateMedian Index:"+str(index))

			index=GetSSIM_Index('noisy_images/'+imageList[i], 'Improved_Images/Median-'+imageList[i])
			print("Median Index:"+str(index))

			index=GetSSIM_Index('noisy_images/'+imageList[i], 'Improved_Images/HybridMedian-'+imageList[i])
			print("HybridMedian Index:"+str(index))

if(calculateNAI):
	for i in range(0, len(imageList)):
		if(imageList[i]!=".DS_Store"):
			print("IMG="+str(imageList[i]))
			#AnalyzeNoise( 'noisy_images/'+imageList[i],imageList[i])
			#Original Image vs Alpha
			index=GetNAI_Index('noisy_images/'+imageList[i], 'Improved_Images/AlphaTrimmed-'+imageList[i])
			print("AlphaTrim Index:"+str(index))

			index=GetNAI_Index('noisy_images/'+imageList[i], 'Improved_Images/TruncateMedian-'+imageList[i])
			print("TruncateMedian Index:"+str(index))

			index=GetNAI_Index('noisy_images/'+imageList[i], 'Improved_Images/Median-'+imageList[i])
			print("Median Index:"+str(index))

			index=GetNAI_Index('noisy_images/'+imageList[i], 'Improved_Images/HybridMedian-'+imageList[i])
			print("HybridMedian Index:"+str(index))







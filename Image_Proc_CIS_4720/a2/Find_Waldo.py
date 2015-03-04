from pylab import imshow
from pylab import imsave
import numpy as np
import mahotas


def FindWaldo(imageSource):
	waldo = mahotas.imread("ww1.jpg")
	wfloat = waldo.astype(float)
	r,g,b = wfloat.transpose ( ( 2,0,1))
	w= wfloat.mean(2)

	num1=50#24
	num2=50#16
	pattern = np.ones((num1,num2),float)
	for i in xrange(2):
		pattern[i::4]= -1

	v = mahotas.convolve(r-w, pattern)

	mask = (v == v.max())
	mask = mahotas.dilate(mask,np.ones(( (num1*2),(num2*2) )))



	waldo -= .8*waldo * ~mask[:,:,None]
	#imshow(waldo)
	imsave( "Found_Ww1",waldo)


FindWaldo("lol")
from imthr_lib import *;
from pylab import imshow
from pylab import imsave
import numpy as np
import mahotas

import mahotas
import mahotas.demos
import numpy as np
from pylab import imshow, gray, show
from os import path


from PIL import Image
import pymeanshift as pms
import sys

#library used:https://code.google.com/p/pymeanshift/wiki/Install
#opencv
'''
def Method_1(imageSource):
	#Extract an Inverse of the Image
	#photo_gry= mahotas.imread("c3.jpg", as_grey=True)

	#The Image
	photo = mahotas.imread("c3.png")

	photo = photo.astype(np.uint8)
	T_otsu = mahotas.otsu(photo)



	#imshow(waldo)
	imsave( "Found_Ww1_Otsu", (photo > T_otsu))
	imsave( "Found_Ww1_inverse", (photo_gry))
'''
# Mean Shift Segmentation
def Method_2(imageSource):
	original_image = Image.open("s1.jpg")


	my_segmenter = pms.Segmenter()

	(segmented_image, labels_image, number_regions) = pms.segment(original_image, spatial_radius=6,range_radius=4.5, min_density=50)
	



	original_image = original_image.convert("RGBA")

#	imsave( "SegmentedImage",  ( img ) )
	img= Image.fromarray(segmented_image)
	img=img.convert("RGBA")
	img.save("Segmented_.jpg");
	#segmented_image = segmented_image.convert("RGBA")
	data = np.array(img)   # "data" is a height x width x 4 numpy array

	r1, g1, b1 = 255, 0, 0 # Target Value

	#Red

	#Knock out Colors outside range

	r2, g2, b2 = 0, 0, 0 # Value that we want to replace it with
	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask = (blue<100) | (green < 100) | (red <100)
	mask2= (blue>100) & (green > 100) & (red <100)
	mask3= blue> red
	data[:,:,:3][mask3] = [r2, g2, b2]
	
	img_M1= Image.fromarray(data)
	img_M1.save("Mask1.jpg");
	
	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= blue>green
	data[:,:,:3][mask3] = [r2, g2, b2]

	img_M2= Image.fromarray(data)
	img_M2.save("Mask2.jpg");

	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= (green>red) 
	data[:,:,:3][mask3] = [r2, g2, b2]

	img_M3= Image.fromarray(data)
	img_M3.save("Mask3.jpg");

	#No such thing as a Dark yellow fire
	data = np.array(img_M2) 
	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= (red-blue < 50)#(red == green) & (green==blue) & (red!=0)
	data[:,:,:3][mask3] = [0,0, 0]

	img= Image.fromarray(data)
	img.save("Mask4.jpg");

#For the final mask, Ideally a contour should be performed on whatever was near smoke.


	#imsave( "Final_Image", (img > T_otsu))


	#Rule 1 Blue is never higher than red
	#Rule 2 Blue is also never higher than Green
	#Rule 3 Green is never higher than red
	#Cull Outliers utilizing the Otsu Data

	#imsave( "SegmentedImage",  ( img ) )




Method_2("lol_")
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


#This is the method which results in creating the Masks images among others.
def Method_2(imageName, imageExt):
	original_image = Image.open("Fire_Original/"+imageName+"."+imageExt)


	my_segmenter = pms.Segmenter()

	(segmented_image, labels_image, number_regions) = pms.segment(original_image, spatial_radius=6,range_radius=4.5, min_density=50)
	

	original_image = original_image.convert("RGBA")
#	imsave( "SegmentedImage",  ( img ) )
	img= Image.fromarray(segmented_image)
	img=img.convert("RGBA")
	img.save("Fire_Converted/"+(imageName)+"_Segmented"+"."+imageExt);
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
	img_M1.save("Fire_Converted/"+(imageName)+"_Mask1"+"."+imageExt);
	
	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= blue>green
	data[:,:,:3][mask3] = [r2, g2, b2]

	img_M2= Image.fromarray(data)
	img_M1.save("Fire_Converted/"+(imageName)+"_Mask2"+"."+imageExt);

	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= (green>red) 
	data[:,:,:3][mask3] = [r2, g2, b2]

	img_M3= Image.fromarray(data)
	img_M1.save("Fire_Converted/"+(imageName)+"_Mask3"+"."+imageExt);

	#No such thing as a Dark yellow fire
	data = np.array(img_M2) 
	red, green, blue = data[:,:,0], data[:,:,1], data[:,:,2]
	mask3= (red-blue < 50)#(red == green) & (green==blue) & (red!=0)
	data[:,:,:3][mask3] = [0,0, 0]

	img= Image.fromarray(data)
	img_M1.save("Fire_Converted/"+(imageName)+"_Mask4"+"."+imageExt);



#Here we calculate our values
def Method_2(imageName, imageExt):
	masked_image  = Image.open ("Fire_Original/"+imageName+"_Mask4."+imageExt)
	grdTruth_image= Image.open("Fire_GrdTruths/"+imageName+"_flameB.tif")

	#Calculate CM

	masked_Img = masked_image.convert("RGBA")
	grdTruth_Img = grdTruth_image.convert("RGBA")




	m_Img= Image.fromarray(masked_Img)
	g_Img= Image.fromarray(grdTruth_Img)


	m_Img=m_Img.convert("RGBA")
	g_Img=g_Img.convert("RGBA")


	#segmented_image = segmented_image.convert("RGBA")
	m_data = np.array(m_Img)   # "data" is a height x width x 4 numpy array
	g_data = np.array(g_Img)   # "data" is a height x width x 4 numpy array

	#Red
	r1, g1, b1 = 255, 255, 255 # Target Value

	#Knock out Colors outside range

	m_red, m_green, m_blue 	= m_data[:,:,0], m_data[:,:,1], m_data[:,:,2]
	g_red, g_green, g_blue 	= g_data[:,:,0], g_data[:,:,1], g_data[:,:,2]

	#If the value at m_data is not black, and g_data
	mask3= blue> red
	data[:,:,:3][mask3] = [r2, g2, b2]

	#Count Remaining White in g_Data for CM
	#Count Remaining Non-Black in m_Data for CR

	#Do two initial counts of each to find the total, divide calc by total to get value
	#






#Get All Image Files in Noisy_Images
imageList=os.listdir("noisy_images")



#Create the Masks
for filename in imageList:
	basename  = os.path.splitext(filename)[0]
	extension = os.path.splitext(filename)[1]	
	Method_2(basename,extension)

#Test each result
from pylab import imshow
from pylab import imsave
import numpy as np
import mahotas

import mahotas
import mahotas.demos
import numpy as np
from pylab import imshow, gray, show
from os import path

import os
from PIL import Image
import pymeanshift as pms
import sys
import cv2
import numpy as np

from matplotlib import pyplot as plt
import cv2.cv as cv                 

import Image
import numpy
#import matplotlib.pyplot as plt
import scipy.ndimage.filters as nd
import colorsys
import cv2
import os
import scipy

# Gets the filename from the user
def getFilename():
    filename = raw_input('Enter a file name: ')
    return filename

# Reads in the file
def imread(fname):
    imgIN = Image.open(fname) 
    if imgIN.mode == 'RGB': #colour
        img = numpy.asarray(imgIN)
    else: #grayscale
        img = numpy.asarray(imgIN)
    return (img)
    
# Function to write an image from a 8-bit 2D array
def imwrite(fname,img,scaleF=1):
    if img.ndim == 3:
        rgbimg = numpy.zeros((img.shape[0],img.shape[1],3), 'uint8')
        rgbimg[..., 0] = img[..., 0]*scaleF
        rgbimg[..., 1] = img[..., 1]*scaleF
        rgbimg[..., 2] = img[..., 2]*scaleF
        imgSv = Image.fromarray(rgbimg)
        imgSv.save(fname)
    else:
        img_uint8 = numpy.uint8(img)
        imgSv = Image.fromarray(img_uint8,'L')
        imgSv.save(fname)
        
def compute_feature(array):
    """
    Resizes a cropped cell to feature_size and removes a border
    """
    feature_size = 30
    feature_size_no_border = feature_size - 6
    norm_im = scipy.misc.imresize(array, (feature_size,feature_size))
    # Border is 3 pixels wide all around - To eliminate any grid remains
    norm_im = norm_im[3:-3, 3:-3]
    # norm_im = norm_im.reshape((1, feature_size_no_border * feature_size_no_border))
    return numpy.float32(norm_im)

def loadOCRdata(path):
    """
    Loads all of the OCR classification data in order to train the
    digit recognizer.
    """
    feature_size = 30
    feature_size_no_border = feature_size - 6
    
    imlist = []
    # Look through all sub directories for pngs as well
    for dirlist in os.walk(path):
        base_dir = dirlist[0]
        for file_list in dirlist[1:]:
            for im in file_list:
                if im.endswith('.png'):
                    imlist.append(os.path.join(base_dir, im))

    # The first character of the file name is the digit label
    labels = [int(imfile.split('/')[-1][0]) for imfile in imlist]

    features = numpy.empty((0, feature_size_no_border * feature_size_no_border))
    for i, imname in enumerate(imlist):
        im = Image.open(imname).convert('L')
        im = compute_feature(im)
        im = im.reshape((1, feature_size_no_border * feature_size_no_border))
        im = numpy.float32(im)
        features = numpy.append(features, im, 0)

    labels = numpy.array(labels, numpy.float32)
    labels = labels.reshape((labels.size, 1))

    return numpy.float32(features), numpy.float32(labels)

class Sudoku:
	cells=[]
	origCells=[]
	idTag=0;
	timesCalled=0
	def __init__(self, cell_Arr, myid=0):
		self.cells=[]
		self.cells=cell_Arr;
		self.origCells=self.DuplicateBoard(cell_Arr);
		self.idTag=myid;
		return
	#Returns a new Board with the same contents as the board passed in
	def DuplicateBoard(self, board):
		#
		dupBoard= [ [ None for i in range(9) ] for j in range(9) ]

		for x in range (0,9):
			for y in range(0,9):
				dupBoard[x][y] = board[x][y]

		return dupBoard

		#Prints OG Contents
	def PrintContents(self, row, col):

		print("================================")
		print("Times Called:"+ str(self.timesCalled))

		for j in range(0,9):
			string = ""

			for i in range(0,9):
				if(i%3==0):
					string+="|"
				if(i==col and j == row):
					string+="["

				if (self.origCells[i][j]==0):
					string+=" . "
				else:
					string+=" "+str(self.origCells[i][j])+" "
				if(i==col and j == row):
					string+="]"

			if(i%3==0):
				string+="|"

			print(string)
			if(j==2 or j==5):
				print("________________________________")	
		print("================================")
		print("Times Called:"+ str(self.timesCalled))

	#Structure is ALMOST similar. The difference is the values used
	def AttemptSolve(self,row,col):
		# self.timesCalled+=1;
		# print("Row="+str(row))
		# print("Col="+str(col))
		# print("--------------")
		#Here we do something similar to solve only we alternate
		self.PrintContents(row,col);
		if (row == 9):
			return False;

		# if(not self.isValidToStart_Check(row,col)):
			# return False
		#Common confusions
		solution = False
		if (self.origCells[row][col] == 5 or self.origCells[row][col] == 6 or self.origCells[row][col] == 8):
			i = self.origCells[row][col]

			#######  i ################
			self.origCells[row][col] =i;

			if(col==8):
				solution =	self.AttemptSolve(row+1,(0))
			else:
				solution =	self.AttemptSolve((row),(col+1))

			if(solution):
				return True

			solution = (self.isValidToStart(row,col))
			if(solution):
				return True

			#######  3 ################
			# self.origCells[row][col] =3;

			# if(row==8):
			# 	solution =	self.AttemptSolve(0,(col+1))
			# else:
			# 	solution =	self.AttemptSolve((row+1),(col))

			# if(solution):
			# 	return True

			# solution = (self.Solve(0,0))
			# if(solution):
			# 	return True

			#######  5 ################
			self.origCells[row][col] =5;
			if(5!=i):
				if(col==8):
					solution =	self.AttemptSolve(row+1,(0))
				else:
					solution =	self.AttemptSolve((row),(col+1))

				if(solution):
					return True

				solution = (self.isValidToStart(row,col))
				if(solution):
					return True

			#######  6 ################
			self.origCells[row][col] =6;
			if(6!=i):
				if(col==8):
					solution =	self.AttemptSolve(row+1,(0))
				else:
					solution =	self.AttemptSolve((row),(col+1))

				if(solution):
					return True

				solution = (self.isValidToStart(row,col))
				if(solution):
					return True

			#######  8 ################
			self.origCells[row][col] =8;
			if(8!=i):
				if(col==8):
					solution =	self.AttemptSolve(row+1,(0))
				else:
					solution =	self.AttemptSolve((row),(col+1))

				if(solution):
					return True

				solution = (self.isValidToStart(row,col))
				if(solution):
					return True

			# #######  9 ################
			# self.origCells[row][col] =9;

			# if(row==8):
			# 	solution =	self.AttemptSolve(0,(col+1))
			# else:
			# 	solution =	self.AttemptSolve((row+1),(col))

			# if(solution):
			# 	return True

			# solution = (self.Solve(0,0))
			# if(solution):
			# 	return True

			self.origCells[row][col]= i;


		else:

			#Skip to next Character of interest
			exitLoop=False
			while (not exitLoop):

				if(row==9):
					return False;

				if(self.origCells[row][col]==5 or self.origCells[row][col]==6 or self.origCells[row][col]==8):
					exitLoop=True
					break
				col+=1;
				if(col==9):
					row+=1;
					col=0

			if(not exitLoop):
				return False
			else:
				print("Entering Attempt")
				solution=self.AttemptSolve(row,col)
		 # 	if(row==8):
		 # 		solution=self.AttemptSolve(0,(col+1))
		 # 	else:
		 # 		solution=self.AttemptSolve((row+1),(col))		

		 # 	if(solution):
		 # 		return True

			# solution = (self.isValidToStart(row,col))
		 		return solution;

		return False;




	def Solve(self, row, col):
		self.timesCalled+=1;
		# print("Row="+str(row))
		# print("Col="+str(col))
		# print("--------------")
		# If it has passed through all cells, start quitting
		if (row == 9):
			return True;
	 
		# If this cell is already set(fixed), skip to the next cell
		if (self.cells[row][col] != 0): 
			# if (solve(col == 8? (row + 1): row, (col + 1) % 9)):	
			if (col == 8):
				if(self.Solve((row+1),((col+1)%9))):
					# print(self.cells)
					# print("The puzzle is solved!")
					return True
			else: # Initialize the cell when backtracking (case when the value in the next cell was not valid)
				if(self.Solve((row),((col+1)%9))):
					# print(self.cells)
					# print("The puzzle is solved!")
					return True
		else:
			# Random numbers 1 - 9
			for i in range (1,10):
				# If no duplicates in this row, column, 3x3, assign the value and go to the next
				if (not self.containedInRowCol(row, col, i) and (not self.containedIn3x3Box(row, col, i))):
					self.cells[row][col] = i
					# fields[row][col].setText(String.valueOf(randoms[i]));

					# Move to the next cell left-to-right and top-to-bottom
					# if (solve(col == 8? (row + 1) : row, (col + 1) % 9)):
						# return true;
					if (col == 8):
						if(self.Solve((row+1),((col+1)%9))):
							# print(self.cells)
							# print("The puzzle is solved!")
							return True
						else:
							self.cells[row][col] = 0;
					else: # Initialize the cell when backtracking (case when the value in the next cell was not valid)
						if(self.Solve((row),((col+1)%9))):
							# print(self.cells)
							# print("The puzzle is solved!")
							return True
						else:
							self.cells[row][col] = 0;

		return False;


	def containedInRowCol(self,row,col,value): 
		for i in range(0,9):
			#Don't check the same cell
			if (i != col):
				if (self.cells[row][i] == value):
					return True

			if (i != row):
				if (self.cells[i][col] == value):
					return True

		return False;

 	def containedIn3x3Box(self,row,col,value):
		# Find the top left of its 3x3 box to start validating from
		startRow = row / 3 * 3;
		startCol = col / 3 * 3;
	 
		# Check within its 3x3 box except its cell
		for i in range(startRow, (startRow+3)):
			for j in range(startCol, (startCol+3)):
				if (not(i == row and j == col)): 
					if (self.cells[i][j] == value):
						return True;
	 
		return False;

	def isValidToStart_Check(self, row, col):
		#This only checks up to the row and col. Since everything beyond can be modified
		for i in range(0,row):
			for j in range(0,col):
				if (self.cells[i][j] != 0):
					if (self.containedIn3x3Box(i, j, self.cells[i][j]) or
							self.containedInRowCol(i, j, self.cells[i][j])):
						return False;
		#If Valid, just start
		return True;


	def isValidToStart(self, row, col):
		#This only checks up to the row and col. Since everything beyond can be modified
		for i in range(0,9):
			for j in range(0,9):
				if (self.cells[i][j] != 0):
					if (self.containedIn3x3Box(i, j, self.cells[i][j]) or
							self.containedInRowCol(i, j, self.cells[i][j])):
						return False;
		#If Valid, just start
		return self.Solve(0,0);


		#This function checks the entire board
	def isValidToStart_Global(self):
		for i in range(0,9):
			for j in range(0,9):
				if (self.cells[i][j] != 0):
					if (self.containedIn3x3Box(i, j, self.cells[i][j]) or
							self.containedInRowCol(i, j, self.cells[i][j])):
						return False;
		#If Valid, just start
		return self.Solve(0,0);
#opencv

def Prepare_DataSet():
	im = cv2.imread('Train_Ocr.png')
	im3 = im.copy()

	gray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
	blur = cv2.GaussianBlur(gray,(5,5),0)
	thresh = cv2.adaptiveThreshold(blur,255,1,1,11,2)

	#################      Now finding Contours         ###################

	# How it works is it shows you a number, and you are to press that number key
	contours,hierarchy = cv2.findContours(thresh,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)

	samples =  np.empty((0,100))
	responses = []
	keys = [i for i in range(48,58)]

	for cnt in contours:
	    if cv2.contourArea(cnt)>50:
	        [x,y,w,h] = cv2.boundingRect(cnt)

	        if  h>28:
	        	#Add blue outline to help user know what current value is
	        	#Rectangle Green
	            cv2.rectangle(im,(x,y),(x+w,y+h),(255,0,0),2)
	            roi = thresh[y:y+h,x:x+w]
	            roismall = cv2.resize(roi,(10,10))
	            cv2.imshow('norm',im)
	            key = cv2.waitKey(0)

	            cv2.rectangle(im,(x,y),(x+w,y+h),(0,0,255),2)
	            if key == 27:  # (escape to quit)
	                sys.exit()
	            elif key in keys:
	                responses.append(int(chr(key)))
	                sample = roismall.reshape((1,100))
	                samples = np.append(samples,sample,0)


	responses = np.array(responses,np.float32)
	responses = responses.reshape((responses.size,1))
	print "training complete"

	np.savetxt('generalsamples.data',samples)
	np.savetxt('generalresponses.data',responses)

def Prepare_DataSet_2():
	img = cv2.imread('digits.png')
	gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

	# Now we split the image to 5000 cells, each 20x20 size
	cells = [np.hsplit(row,100) for row in np.vsplit(gray,50)]

	# Make it into a Numpy array. It size will be (50,100,20,20)
	x = np.array(cells)

	# Now we prepare train_data and test_data.
	train = x[:,:50].reshape(-1,400).astype(np.float32) # Size = (2500,400)
	test = x[:,50:100].reshape(-1,400).astype(np.float32) # Size = (2500,400)

	# Create labels for train and test data
	k = np.arange(10)
	train_labels = np.repeat(k,250)[:,np.newaxis]
	test_labels = train_labels.copy()

	# Initiate kNN, train the data, then test it with test data for k=1
	knn = cv2.KNearest()
	knn.train(train,train_labels)
	ret,result,neighbours,dist = knn.find_nearest(test,k=5)
	np.savetxt('generalsamples.data',samples)
	np.savetxt('generalresponses.data',responses)

def OCR_Image(imageName, imageExt):
	imgLocation_src  = (imageName+imageExt) # the image we're processing
	imgLocation_data = 'generalsamples.data';   # The dataset to identify numbers  
	#######   training part    ############### 
	samples = np.loadtxt('generalsamples.data',np.float32)
	responses = np.loadtxt('generalresponses.data',np.float32)
	responses = responses.reshape((responses.size,1))




	model = cv2.KNearest()
	model.train(samples,responses)

	############################# testing part  #########################

	im = cv2.imread("Sudoku_Steps/"+imageName+"_Step7"+imageExt)
	out = np.zeros(im.shape,np.uint8)
	gray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
	thresh = cv2.adaptiveThreshold(gray,255,1,1,11,2)

	contours,hierarchy = cv2.findContours(thresh,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)

	for cnt in contours:
	    if cv2.contourArea(cnt)>50:
	        [x,y,w,h] = cv2.boundingRect(cnt)
	        if  h>28:
	            cv2.rectangle(im,(x,y),(x+w,y+h),(0,255,0),2)
	            roi = thresh[y:y+h,x:x+w]
	            roismall = cv2.resize(roi,(10,10))
	            roismall = roismall.reshape((1,100))
	            roismall = np.float32(roismall)
	            retval, results, neigh_resp, dists = model.find_nearest(roismall, k = 1)
	            string = str(int((results[0][0])))
	            cv2.putText(out,string,(x,y+h),0,1,(0,255,0))

	cv2.imshow('im',im)
	cv2.imshow('out',out)
	cv2.waitKey(0)




def Compute_Image(imageName, imageExt):

	# try:
	sudokuGrid= [[0 for x in range(9)] for x in range(9)] 
	#Step1: Image PreProcessing (Closing Operation)
	imgLocation = ("Sudoku_Puzzles/"+imageName+imageExt)
	print (imgLocation)
	print("")

	img = cv2.imread( imgLocation  )


	img = cv2.GaussianBlur(img,(5,5),0)
	# img = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,\cv2.THRESH_BINARY,11,2)
	# img = cv2.bilateralFilter(img,9,75,75)
	# img = cv2.medianBlur(img,5)

	# img = otsu
	#Otsu to increase sharpness!
	# ret, otsu = cv2.threshold(img, cv2.THRESH_OTSU)

	# img =otsu

	
	gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

	# ret, otsu = cv2.threshold(gray,220,255,cv2.THRESH_BINARY)
	# gray = otsu

	mask = np.zeros((gray.shape),np.uint8)
	kernel1 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(11,11))

	close = cv2.morphologyEx(gray,cv2.MORPH_CLOSE,kernel1)
	div = np.float32(gray)/(close)
	res = np.uint8(cv2.normalize(div,div,0,255,cv2.NORM_MINMAX))
	res2 = cv2.cvtColor(res,cv2.COLOR_GRAY2BGR)

	# saveImg=Image.fromarray(otsu)
	# # saveImg=img.convert("RGBA")
	# saveImg.save("Sudoku_Steps/"+(imageName)+"_DarkenLines"+imageExt);

	saveImg=Image.fromarray(img)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step1"+imageExt);

	#Step2: Finding the Main Sudoku Container, Create Mask Image
	thresh = cv2.adaptiveThreshold(res,255,0,1,19,2)
	contour,hier = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

	max_area = 0
	best_cnt = None
	for cnt in contour:
		area = cv2.contourArea(cnt)
		if area > 1000:
			if area > max_area:
				max_area = area
				best_cnt = cnt

	cv2.drawContours(mask,[best_cnt],0,255,-1)
	cv2.drawContours(mask,[best_cnt],0,0,2)

	res = cv2.bitwise_and(res,mask)


	saveImg=Image.fromarray(res)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step2"+imageExt);

	#Step3: Finding Vertical Lines
	kernelx = cv2.getStructuringElement(cv2.MORPH_RECT,(2,10))

	dx = cv2.Sobel(res,cv2.CV_16S,1,0)
	dx = cv2.convertScaleAbs(dx)
	cv2.normalize(dx,dx,0,255,cv2.NORM_MINMAX)
	ret,close = cv2.threshold(dx,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
	close = cv2.morphologyEx(close,cv2.MORPH_DILATE,kernelx,iterations = 1)

	saveImg=Image.fromarray(close)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step3p1"+imageExt);

	contour, hier = cv2.findContours(close,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
	for cnt in contour:
		x,y,w,h = cv2.boundingRect(cnt)
		if h/w > 6:
			cv2.drawContours(close,[cnt],0,255,-1)
		else:
			cv2.drawContours(close,[cnt],0,0,-1)

	close = cv2.morphologyEx(close,cv2.MORPH_CLOSE,None,iterations = 2)
	closex = close.copy()

	saveImg=Image.fromarray(closex)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step3"+imageExt);

	#Step4: Finding Horizontal Lines
	kernely = cv2.getStructuringElement(cv2.MORPH_RECT,(10,2))
	dy = cv2.Sobel(res,cv2.CV_16S,0,2)
	dy = cv2.convertScaleAbs(dy)
	cv2.normalize(dy,dy,0,255,cv2.NORM_MINMAX)
	ret,close = cv2.threshold(dy,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
	close = cv2.morphologyEx(close,cv2.MORPH_DILATE,kernely, iterations = 1)

	saveImg=Image.fromarray(close)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step4p1"+imageExt);

	contour, hier = cv2.findContours(close,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
	for cnt in contour:
	    x,y,w,h = cv2.boundingRect(cnt)
	    if w/h > 6:
	        cv2.drawContours(close,[cnt],0,255,-1)
	    else:
	        cv2.drawContours(close,[cnt],0,0,-1)

	close = cv2.morphologyEx(close,cv2.MORPH_DILATE,None,iterations = 2)
	closey = close.copy()

	saveImg=Image.fromarray(closey)
	# saveImg=img.convert("RGBA")
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step4"+imageExt);




	#Step5: Acquiring Grid Points
	res = cv2.bitwise_and(closex,closey)

	saveImg=Image.fromarray(res)
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step5"+imageExt);

	#Step6: Correcting Defects and draw gridpoints
	contour, hier = cv2.findContours(res,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
	centroids = []
	for cnt in contour:
	    mom = cv2.moments(cnt)
	    (x,y) = int(mom['m10']/mom['m00']), int(mom['m01']/mom['m00'])
	    cv2.circle(img,(x,y),4,(0,255,0),-1)
	    centroids.append((x,y))

	saveImg=Image.fromarray(img)
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step6"+imageExt);	   
	#Sort Centroids Left->Right, Top to Bottom
	centroids = np.array(centroids,dtype = np.float32)
	c = centroids.reshape((100,2))
	c2 = c[np.argsort(c[:,1])]

	b = np.vstack([c2[i*10:(i+1)*10][np.argsort(c2[i*10:(i+1)*10,0])] for i in xrange(10)])
	bm = b.reshape((10,10,2))

	#Step7: Apply Transformation to create new Image
	output = np.zeros((450,450,3),np.uint8)
	for i,j in enumerate(b):
	    ri = i/10 #Row I
	    ci = i%10 #Column I
	    if ci != 9 and ri!=9:
	        src = bm[ri:ri+2, ci:ci+2 , :].reshape((4,2))
	        dst = np.array( [ [ci*50,ri*50],[(ci+1)*50-1,ri*50],[ci*50,(ri+1)*50-1],[(ci+1)*50-1,(ri+1)*50-1] ], np.float32)
	        retval = cv2.getPerspectiveTransform(src,dst)
	        warp = cv2.warpPerspective(res2,retval,(450,450))
	        output[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1] = warp[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1].copy()


	# newG = cv2.GaussianBlur(cv2.cvtColor(output,cv2.COLOR_BGR2GRAY),(5,5),0)
	# output= cv2.adaptiveThreshold(newG,255,1,1,11,2)
	# output= cv2.cvtColor(output, cv2.COLOR_GRAY2BGR)
	saveImg=Image.fromarray(output)
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Step7"+imageExt);



# try:

	samples = np.loadtxt('mikes_samples.data',np.float32)
	responses = np.loadtxt('mikes_responses.data',np.float32)
	responses = responses.reshape((responses.size,1))
	#Wirths Samples
	# features, labels = loadOCRdata('ocr_test_data/')



	model = cv2.KNearest()
	model.train(samples,responses)
	# model.train(features, labels) #Wirth code

	final_Output = np.zeros((450,450,3),np.uint8)



	# out = np.zeros((450,450,3),np.uint8)
	# temp = np.zeros((450,450,3),np.uint8)
	# temp = (255 - temp)

	for i,j in enumerate(b):
		ri = i/10 #Row I
		ci = i%10 #Column I
		#Here we have the Image Split up into the Grids we want.
		if ci != 9 and ri!=9:
			# src = bm[ri:ri+2, ci:ci+2 , :].reshape((4,2))
			# im = np.zeros((450,450,3),np.uint8)

			# dst = np.array( [ [ci*50,ri*50],[(ci+1)*50-1,ri*50],[ci*50,(ri+1)*50-1],[(ci+1)*50-1,(ri+1)*50-1] ], np.float32)
			# retval = cv2.getPerspectiveTransform(src,dst)
			# warp = cv2.warpPerspective(res2,retval,(450,450))

			# im[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1] = output[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1].copy()

			#Invert the Image
			invert = np.ones((450,450,3),np.uint8)
			invert[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1] = (255-output[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1]).copy()
			# #Now Bitmask the inverse
			# invert = (255-invert)
			# temp[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1] = im[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1].copy()

			invert = (255- invert)

			#saveImg=Image.fromarray(invert)
			#saveImg.save("Sudoku_Steps/"+(imageName)+"__"+str(ci)+str(ri)+imageExt);
			gray = 	 cv2.cvtColor(invert,cv2.COLOR_BGR2GRAY)

			crop_img = invert[ri*50  :(ri+1)*50-1 , ci*50 :(ci+1)*50-1 ]

			thresh = cv2.adaptiveThreshold(gray,255,1,1,7,2)
		# ret, otsu = cv2.threshold(img, cv2.THRESH_OTSU)
			# if self.lvl >= 0:
			# 	morph = cv2.morphologyEx(thresh,cv2.MORPH_ERODE,None,iterations = self.lvl)
			# elif self.lvl == -1:
			# 	morph = cv2.morphologyEx(thresh,cv2.MORPH_DILATE,None,iterations = 1)
			morph = cv2.morphologyEx(thresh,cv2.MORPH_ERODE,None,iterations = 0)

			thresh_copy = morph.copy()
			#thresh2 changes after findContours
			contours,hierarchy = cv2.findContours(morph,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
			thresh = thresh_copy



			# puzzle.current = np.zeros((9,9),np.uint8)

			# testing section
			for cnt in contours:
				if cv2.contourArea(cnt)>20:
					[x,y,w,h] = cv2.boundingRect(cnt)
					locX = x % 50;
					# x-=1
					# w+=1
					# y-=1
					# h+=1
					if  h>10 and h<40 and w>8 and w<40:
						# if w<20:
							# diff = 20-w
							# x -= diff/2
							# w += diff

						
						#prepare region of interest for OCR kNearest model
						roi = thresh[y:y+h,x:x+w]
						roismall = cv2.resize(roi,(25,35))
						roismall = roismall.reshape((1,875))
						roismall = np.float32(roismall)
						# find result
						retval, results, neigh_resp, dists = model.find_nearest(roismall, k = 1)

						# feature_size = 30
						# feature_size_no_border = feature_size - 6
						# imFea = compute_feature(roi)
						# imJ = imFea.reshape((1, feature_size_no_border * feature_size_no_border))
						# retval, results, neigh_resp, _ = model.find_nearest(numpy.float32(imJ), k=1)

						int_Val= (int((results[0][0])))
						#Apply Correction
						if(int_Val==0):
							int_Val=6;

						sudokuGrid[ci][ri]=int_Val;
						string = str(int_Val)
						final_Output[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1] = output[ri*50:(ri+1)*50-1 , ci*50:(ci+1)*50-1].copy()

						cv2.rectangle(final_Output,(x,y),(x+w,y+h),(0,0,255),2)
						cv2.putText(final_Output,string,(x,y+h),0,1.4,(255,0,0),3)


	# print( sudokuGrid)
	saveImg=Image.fromarray(final_Output)
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Extracted_Numbers_"+str(ci)+str(ri)+imageExt); 
	
	puzzle = Sudoku(sudokuGrid)
	isSolved=puzzle.Solve(0,0);
	if(not isSolved):
		isSolved=puzzle.AttemptSolve(0,0); # Could've been a misread. Alter through combinations of 5-6-8
	#if its not solved cycle through all 6 values converting to 5's
	#and retry

	# curY=0;
	# while (not isSolved and curY!=8):
	# 	#Scan for a 6
	# 	for i in range(0,9):
	# 		if(puzzle.cells[i][curY]==6):
	# 			puzzle.cells[i][curY]=5
	# 			isSolved=puzzle.Solve(0,0)
	# 			if(not isSolved):
	# 				puzzle.cells[i][curY]=6 #revert
	# 			else:
	# 				break #It's Solved!
	# 	curY+=1

	print("Puzzle Solved="+str(isSolved))
	print("Times Called="+ str(puzzle.timesCalled))


	#now Place numbers in cell
	final_Output = output.copy()
	for x in range(0,9):
		for y in range(0,9):
			string = str(puzzle.cells[x][y])
			if(puzzle.origCells[x][y]==0):
				cv2.putText(final_Output,string,(x*50+10,y*50+40),0,1.4,(0,255,0),3)	

	#cv2.imshow('final_out',final_Output)
	# cv2.imshow('out',out)
	#cv2.waitKey(0)
	saveImg=Image.fromarray(final_Output)
	saveImg.save("Sudoku_Steps/"+(imageName)+"_Solved"+str(ci)+str(ri)+imageExt)

	# except Exception as e:
	# 	print("There was an Error Attempting to Solve:"+imageName)
	# except ValueError:
	# 	print("There was an Error Attempting to Solve:"+imageName)		
	# 	raise



# Prepare_DataSet()
#Compute_Image("DLMIA",".png")
# Compute_Image("sudoku15",".JPG")
#Compute_Image("Sudoku1",".jpg")
#OCR_Image("DLMIA",".png")

# #Get All Image Files in Noisy_Images
imageList=os.listdir("Sudoku_Puzzles")

# #Create the Masks
for filename in imageList:
	if(filename!=".DS_Store"):
		basename  = os.path.splitext(filename)[0]
		extension = os.path.splitext(filename)[1]	
		#Create the Masks
		print("BN:"+basename+" Ext:"+extension)
		Compute_Image(basename,extension)

# imageList=os.listdir("Fire_Original")
# for filename in imageList:
# 	if(filename!=".DS_Store"):
# 		basename  = os.path.splitext(filename)[0]
# 		extension = os.path.splitext(filename)[1]			
# 		CM_CR(basename,extension)



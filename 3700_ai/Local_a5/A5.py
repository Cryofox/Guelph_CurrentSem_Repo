
from os import path
import sys
import os
import re

class BayesAnalyzer:

	#Here we store words along with the frequency of their occurance
	myDictionary={}
	totalFrequencyCount=0
	myid=""
	def __init__( self, thisid="None"):
		self.myid=thisid;
		self.myDictionary={}; #Recreate dictionary
		return

	def Print_Freq(self):
		print(self.myid+":"+str(self.totalFrequencyCount))

	def Add_ToDictionary(self,filePath):
		line ="";
		linesRead = []
		with open( filePath, "r") as ins:
			for line in ins:
				linesRead.append(line)

		#Now we split each line into words
		for lineN in linesRead:
			words=[]
			# words= re.split('[, .;:\!./\(\)\'\|\?\*\-\>\<\n\t]',lineN)
			words= re.split('[^a-zA-Z]',lineN)
			# print("LN="+lineN)
			for word in words:
				#Check 			
				if word in self.myDictionary:
					#if the word is mapped, grab the value
					value = self.myDictionary[word]
					value+=1
					self.myDictionary[word]=value
					# self.totalFrequencyCount+=1;
				else:
					self.myDictionary[word]=1
					# self.totalFrequencyCount+=1;
					# print("Adding Key:"+word)

		#For every keyword that has less than 5 remove that from total freq count
		self.totalFrequencyCount=0;
		for key in self.myDictionary:
			if self.myDictionary[key]>5:
				self.totalFrequencyCount+=self.myDictionary[key]




	def Detect_Probability(self,filePath, kw=None):
		#Use a Temp Dictionary
		test_Dictionary={}

		line ="";
		linesRead = []
		emailWords= []
		with open( filePath, "r") as ins:
			for line in ins:
				linesRead.append(line)

		#Now we split each line into words
		for lineN in linesRead:
			words=[]
			# words= re.split('[, .;:\!./\(\)\'\|\?\*\-\>\<\n\t]',lineN)
			words= re.split('[^a-zA-Z]',lineN)
			
			# print("LN="+lineN)
			for word in words:
				#Check 			
				if word not in emailWords:
					#if the word is mapped, grab the value
					emailWords.append(word)


		#Now we calculate the probability
		probability=0.0000

		for word in emailWords:
			if word in self.myDictionary:
				if(len(word)>0): #Glitch with /0 Being treated as a key
					if self.myDictionary[word]>5:
						probability+= ((   (float)(self.myDictionary[word]) /self.totalFrequencyCount))
						
						# print(kw+"-Word="+word+"_")
						# print(kw+"-Word Freq="+str(self.myDictionary[word]))
						# print(kw+"-Tot Fre="+str(self.totalFrequencyCount))
						# print("P%="+str(probability))
						# print(str(kw)+"-"+word+"%="+str(((   (float)(self.myDictionary[word]) /self.totalFrequencyCount))))

		return probability;







#Get All Image Files in Noisy_Images
dataSet_Spam=os.listdir("Spam")
dataSet_Ham =os.listdir("Ham")

dataSet_NUSpam=os.listdir("NotUsed_Spam")
dataSet_NUHam =os.listdir("NotUsed_Ham")

spamBayes = BayesAnalyzer("Spam");
hamBayes = BayesAnalyzer("Ham");



#Add Ham Text Files to be stored
for filename in dataSet_Ham:
	hamBayes.Add_ToDictionary("Ham/"+filename)

#Add Spam Text Files to be stored
for filename in dataSet_Spam:
	spamBayes.Add_ToDictionary("Spam/"+filename)

#Print the Exact Results
# print("H TotF:"+str(hamBayes.totalFrequencyCount))
# print("S TotF:"+str(hamBayes.totalFrequencyCount))	

spamBayes.Print_Freq();
hamBayes.Print_Freq();
print("Spam Testing [Filters]...")
print("----------------------")
for filename in dataSet_Spam:
	basename  = os.path.splitext(filename)[0]
	extension = os.path.splitext(filename)[1]	
	
	probSpam = (spamBayes.Detect_Probability("Spam/"+filename,"spam"))
	probHam  = (hamBayes.Detect_Probability("Spam/"+filename,"Ham"))

	if probSpam>probHam:
		print("[Spam]:"+ filename)
	else:
		print("[Ham]:"+ filename)
	print("----------------------")
	print("\tHam%:"+str(probHam))
	
	print("\tSpam%:"+str(probSpam))
	print("----------------------")
	# print("Spam Probability is ["+str(spamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")
 	# print("Ham  Probability is ["+str(hamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")


print("Ham Testing [Filters]...")
print("----------------------")
for filename in dataSet_Ham:
	basename  = os.path.splitext(filename)[0]
	extension = os.path.splitext(filename)[1]	
	
	probSpam = (spamBayes.Detect_Probability("Ham/"+filename,"spam"))
	probHam  = (hamBayes.Detect_Probability("Ham/"+filename,"Ham"))

	if probSpam>probHam:
		print("[Spam]:"+ filename)
	else:
		print("[Ham]:"+ filename)
	print("----------------------")
	print("\tHam%:"+str(probHam))
	
	print("\tSpam%:"+str(probSpam))
	print("----------------------")
	# print("Spam Probability is ["+str(spamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")
 	# print("Ham  Probability is ["+str(hamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")




print("Spam Testing [Not Used Filters]...")
print("----------------------")
for filename in dataSet_NUSpam:
	basename  = os.path.splitext(filename)[0]
	extension = os.path.splitext(filename)[1]	
	
	probSpam = (spamBayes.Detect_Probability("NotUsed_Spam/"+filename,"spam"))
	probHam  = (hamBayes.Detect_Probability("NotUsed_Spam/"+filename,"Ham"))

	if probSpam>probHam:
		print("[Spam]:"+ filename)
	else:
		print("[Ham]:"+ filename)
	print("----------------------")
	print("\tHam%:"+str(probHam))
	
	print("\tSpam%:"+str(probSpam))
	print("----------------------")
	# print("Spam Probability is ["+str(spamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")
 	# print("Ham  Probability is ["+str(hamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")


print("Ham Testing [Not Used Filters]...")
print("----------------------")
for filename in dataSet_NUHam:
	basename  = os.path.splitext(filename)[0]
	extension = os.path.splitext(filename)[1]	
	
	probSpam = (spamBayes.Detect_Probability("NotUsed_Ham/"+filename,"spam"))
	probHam  = (hamBayes.Detect_Probability("NotUsed_Ham/"+filename,"Ham"))

	if probSpam>probHam:
		print("[Spam]:"+ filename)
	else:
		print("[Ham]:"+ filename)
	print("----------------------")
	print("\tHam%:"+str(probHam))
	
	print("\tSpam%:"+str(probSpam))
	print("----------------------")
	# print("Spam Probability is ["+str(spamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")
 	# print("Ham  Probability is ["+str(hamBayes.Detect_Probability("spam/"+filename))+"]\tfor :["+filename+"]")

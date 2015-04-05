from Pawn import *;
from PrinceJoey import *;
from King import *;
from Rook import *;
from Bishop import *;

from OldWoman import *;
from Catapult import *;
from Serpent import *;
from Beekeeper import *;
from Gorilla import *;

from Transporterpad import *;
from TimeMachine import *;
from JetPack import *;
from GolfCart import *;
from GrandEmpress import *;

import sys;
import random;

import threading

#Debugging for Tree

class WildaBeastSolver:
	#__slots__ = ['DEBUG_InitCount', 'targetDepth', 'currentDepth','betaValue','alphaValue','evaluationScore','chosen_NextMove','list_Children','list_Children_Strings','list_Children_Evals']

	#Debug
	DEBUG_InitCount=0;

	#Target Depth
	targetDepth=4;

	traversed_Nodes=0;
	#Node Traversal used for timing
	maxNodes=150;
	
	DEBUG_children=0;

	currentDepth=0;

	#-1 are used as flags to represent no score
	betaValue=-1;
	alphaValue=-1;
	evaluationScore=0;

	string_Representation="_";

	chosen_NextMove="";




	#List of Children Strings
	list_Children_Strings=[]
	list_Children_Evals  =[]


	#SpeedupHack- Eval
	lookup_Piece= {
	'p':1,
	'o':3,
	'j':3,
	't':4,
	'z':5,
	'x':6,
	'b':8,
	's':8,
	'r':10,
	'w':10,
	'c':10,
	'e':20,
	'g':15,
	'h':0,
	'k':1000
	}

	# Pass in a Chess GameBoard File with correct Format
	def __init__( self, filestring, depth=0, alpha=None, beta=None, turn=None):
		WildaBeastSolver.traversed_Nodes+=1
		WildaBeastSolver.DEBUG_InitCount+=1;
		self.string_Representation= ""
		self.string_Representation+=(filestring)

		self.currentDepth 			=depth;

		self.list_Children_Strings	=[]
		self.list_Children_Evals	=[]

		self.alphaValue 			=alpha
		self.betaValue 				=beta

		#Use depth to determine if we are max or min

		#0 = Max, 1 = Min, 2 = Max, 3 = Min, Odds= Min, Even = Max

		#print("MyDepth is:"+ str(depth))
		#print("FS="+filestring)
		linesRead = filestring.split('\n')
		currentPlayer=1

		#If its white set it to white, otherwise its black
		if(linesRead[0][0]=='W' or linesRead[0][0]=='w'):
			currentPlayer=0


		#Create an Array of Pieces
		board= [ [ None for i in range(8) ] for j in range(8) ]

		#These are in seperate ifs, for speed

		#if Inverse == False, White Pieces = Positive Scores, black negative
		#if true , the opposite
		inverseSigns= 1
		if((depth%2==1 and linesRead[0][0]=='W') or (depth%2==0 and linesRead[0][0]=='B')): #Even turns = same color. Therefore odd = Inverse
			inverseSigns=-1


		tempList=[]

		blackKing=False
		whiteKing=False
		for y in range(1, len(linesRead)):  #Row
			line = linesRead[y]
			for x in range (0, len(line)):	#Column
				if( line[x] =='P'):
					board[x][(y-1)]	= Pawn(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='p'):
					board[x][(y-1)]	= Pawn(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='J'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='j'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='K'):
					board[x][(y-1)]	= King(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])
					whiteKing=True

				elif( line[x] =='k'):
					board[x][(y-1)]	= King(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])
					blackKing=True

				elif( line[x] =='O'):
					board[x][(y-1)]	= OldWoman(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='o'):
					board[x][(y-1)]	= OldWoman(x,(y-1),0)
					board[x][(y-1)].wds =self					
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='R'):
					board[x][(y-1)]	= Rook(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;				
					tempList.append(board[x][(y-1)])

				elif( line[x] =='r'):
					board[x][(y-1)]	= Rook(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='B'):
					board[x][(y-1)]	= Bishop(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='b'):
					board[x][(y-1)]	= Bishop(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='C'):
					board[x][(y-1)]	= Catapult(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='c'):
					board[x][(y-1)]	= Catapult(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='S'):
					board[x][(y-1)]	= Serpent(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='s'):
					board[x][(y-1)]	= Serpent(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='Z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='G'):
					board[x][(y-1)]	= Gorilla(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='g'):
					board[x][(y-1)]	= Gorilla(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='E'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='e'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='W'):
					board[x][(y-1)]	= JetPack(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='w'):
					board[x][(y-1)]	= JetPack(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='T'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])	

				elif( line[x] =='t'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])


				elif( line[x] =='H'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='h'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),0)
					board[x][(y-1)].wds =self					
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;					
					tempList.append(board[x][(y-1)])

				elif( line[x] =='X'):
					board[x][(y-1)]	= GolfCart(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

				elif( line[x] =='x'):
					board[x][(y-1)]	= GolfCart(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])


		#Boards without kings are invalid, so we can stop the children here
		if(whiteKing==False or blackKing==False):
			return



		#Let Each Piece determine the Next Board State based on the Piece's Logic
		calcBoard_Num=0;


		#Traversal must occur post Setup...
		# #Iterate through the Entire Board calculating the Next Turn for Each Piece
		# for x in range (0, 8):
		# 	for y in range (0,8):
		# 	#Calculate the next BoardState while return
		# 		if(board[x][y]!=None):           
		# 			calcBoard_Num+= board[x][y].Calc_PotentialMoves(board,currentPlayer,calcBoard_Num)


		#Optimized For Loop, traverse through pieces not squares
		if(self.currentDepth!=WildaBeastSolver.targetDepth):
			for piece in tempList:
				piece.Calc_PotentialMoves(board,currentPlayer,0)
			del(tempList)





		#For Speed, for the first turn rng a move from index


		#Turn 1 white or black

		#Indexes are used as even if I miscalculated and theres a move that effs up
		#this routine, these values will still have (A) valid move

		#My Harcoded moveset because eff the cheesers.
		if(turn!=None and turn<=1):
			#Rng a Move from our list of children strings if turn 1 or 2. Because these
			#moves don't equate to anything.
			llen = len(self.list_Children_Strings)


			index =15# random.randrange(llen-17, llen,1)
			if( index >= llen):
				index=(llen-1)
			#print("Index="+str(index))
			
			self.chosen_NextMove= self.list_Children_Strings[index]
			return
		if(turn!=None and turn<=3):
			#Rng a Move from our list of children strings if turn 1 or 2. Because these
			#moves don't equate to anything.
			llen = len(self.list_Children_Strings)
			if(turn==2):
				index =3

			#black has diff index for some reason
			else:
				index =20


			if( index >= llen):
				index=(llen-1)
			#print("Index="+str(index))
			
			self.chosen_NextMove= self.list_Children_Strings[index]
			return
		if(turn!=None and turn<=5):
			#Rng a Move from our list of children strings if turn 1 or 2. Because these
			#moves don't equate to anything.
			llen = len(self.list_Children_Strings)

			index =25
			# random.randrange(llen-17, llen,1)
			if( index >=llen):
				index=(llen-1)

			self.chosen_NextMove= self.list_Children_Strings[index]
			return

		#After the gorilla is in position, we don't need to tell braniac here,
		#what to do with it. He's smart enough to see 4 moves ahead :)


		if(self.currentDepth<WildaBeastSolver.targetDepth):
			self.evaluationScore=None
		

			#This is where Threads have fun
			if(self.currentDepth==0):
				#threads=[]
				# numThreads=1;
				self.Thread_Setup_Children(1,0,True)

				# for i in range(0,(numThreads-1)):
				# 	thread_N= threading.Thread(target = self.Thread_Setup_Children(numThreads,i))
				# 	thread_N.start()
				# #This Thread requires a bit more than an even amount
				# thread_N= threading.Thread(target = self.Thread_Setup_Children(numThreads,(numThreads-1),True))
				# thread_N.start()	
			else:
				self.Setup_Children()





	#Here we Iterate through the files and create our children as we go
	#Alpha Beta Pruning occurs here. We replace the actual value of the nodes current board with that of its children
	#otherwise why do we have a tree? lol

	# Children Strings are generated before this function is called, they are also ordered from min to max in Piece.py
	# [ Min ---------- Max]
	def Setup_Children(self):

		depth =(self.currentDepth+1)

		listLen =len(self.list_Children_Strings)
		WildaBeastSolver.DEBUG_children+= listLen
		index =0;
		targetVal=None

		isMinNode=False;


		#if(depth==1):
		#	print("Root Nodes="+str(listLen))



		if(self.currentDepth%2==1):	#Odd is always a Min node, 0=Even=Max
			isMinNode=True;


		llen =( listLen - 0*listLen/2)
		for i in range(0,(llen)):

			#It's better to make a bad move then throw the match due to overthinking.
			#This is done to limit the amount of nodes we can look in a turn
			if(WildaBeastSolver.traversed_Nodes>=WildaBeastSolver.maxNodes):
				return
			#Save time By ignoring branches if both AlphaBeta are set. Don't even create the child
			if(self.betaValue!=None and self.alphaValue!=None):
				if(isMinNode):
					self.evaluationScore	= 	self.betaValue;
				else:
					self.evaluationScore	= 	self.alphaValue;
				return;


			#MinNode Cares about smallest Beta Value
			if(isMinNode):
				wdb= WildaBeastSolver(self.list_Children_Strings[i], (depth), self.alphaValue, self.betaValue)
				#Minus depending on depth
				#self.Debug(wdb,i);

				if(self.betaValue==None):
					self.betaValue		=	wdb.evaluationScore;
					self.evaluationScore= 	self.betaValue;
					self.chosen_NextMove=	wdb.string_Representation

				else:
					if(	wdb.evaluationScore  	<   self.betaValue):
						self.betaValue			=   wdb.evaluationScore;
						self.evaluationScore	= 	self.betaValue;	
						self.chosen_NextMove	=	wdb.string_Representation
						#print("SCORE LESS THAN!")

					#elif(wdb.evaluationScore	==	self.betaValue):
					#	self.evaluationScore	= 	self.betaValue;
						#return
					else:
						# if(threshold<=0):
						# 	self.evaluationScore	= 	self.betaValue;
						# 	return	
						# threshold-=1;
						self.evaluationScore	= 	self.betaValue;
						return			

			#Max Node cares about biggest Alpha Value
			else:
				wdb= WildaBeastSolver(self.list_Children_Strings[ (listLen-i-1)], (depth), self.alphaValue, self.betaValue)
				#self.Debug(wdb,i);

				if(self.alphaValue==None):
					self.alphaValue 			= 	wdb.evaluationScore;
					self.evaluationScore		= 	self.alphaValue;
					self.chosen_NextMove		=	wdb.string_Representation
				#Need to determine when to stop evaluating nodes.
				#Should allow for some room of continuation, to catch moves which may put us in CM
				else:
					if(wdb.evaluationScore		>	self.alphaValue):
						self.alphaValue			=	wdb.evaluationScore;
						self.evaluationScore	= 	self.alphaValue;
						self.chosen_NextMove	=	wdb.string_Representation

					#elif(wdb.evaluationScore	==	self.alphaValue):
						#self.evaluationScore	= 	self.alphaValue;					
					else:
						self.evaluationScore	= 	self.alphaValue;
						return

	def Debug(self,wds,id=0):
		#Debug for Turn 2
		# if(wds.currentDepth==1):
		print("Board:"+str(id))
		print("Node:"+str(wds.currentDepth))
		print("Move Value:"+ str(wds.evaluationScore))
		print("Move Alpha(Max):"+ str(wds.alphaValue))		
		print("Move Beta(Min):"+ str(wds.betaValue))	
		print( wds.string_Representation)

		return


#Should only be called by root
#Num of Divisions to split the for loop in, 
#And which section to take for the thread

#no longer using threads. this is just an entrance for the root node
	def Thread_Setup_Children(self, division, section, isLastThread=False):

		depth =(self.currentDepth+1)

		listLen =len(self.list_Children_Strings)

		WildaBeastSolver.DEBUG_children+= listLen
		index =0;
		targetVal=None

		isMinNode=False;



		# sectionStart=  listLen/division*section

		# if(isLastThread==True):
		# 	sectionEnd= listLen
		# else:
		# 	sectionEnd=  sectionStart+ listLen/division
		


		# print("Children="+str(listLen))
		# print("SECT_START="+str(sectionStart))	
		# print("SECT_END="+str(sectionEnd))
		# for i in range(sectionStart,sectionEnd):


		llen =( listLen - listLen/3)
		for i in range(0,llen):

			#It's better to make a bad move then throw the match due to overthinking.
			#This is done to limit the amount of nodes we can look in a turn

			if(WildaBeastSolver.traversed_Nodes>=WildaBeastSolver.maxNodes):
				return
			#Save time By ignoring branches if both AlphaBeta are set. Don't even create the child
			if(self.betaValue!=None and self.alphaValue!=None):
				if(isMinNode):
					self.evaluationScore	= 	self.betaValue;
				else:
					self.evaluationScore	= 	self.alphaValue;
				return;

			wdb= WildaBeastSolver(self.list_Children_Strings[ (listLen-i-1)], (depth), self.alphaValue, self.betaValue)
			

			if(self.alphaValue==None):
				self.alphaValue 			= 	wdb.evaluationScore;
				self.evaluationScore		= 	self.alphaValue;
				self.chosen_NextMove		=	wdb.string_Representation
			#Need to determine when to stop evaluating nodes.
			#Should allow for some room of continuation, to catch moves which may put us in CM
			else:

				if(wdb.evaluationScore		>	self.alphaValue):
					self.alphaValue			=	wdb.evaluationScore;
					self.evaluationScore	= 	self.alphaValue;
					self.chosen_NextMove	=	wdb.string_Representation

				#elif(wdb.evaluationScore	==	self.alphaValue):
				#	self.evaluationScore	= 	self.alphaValue;
				#	return
				else:
					self.evaluationScore	= 	self.alphaValue;
					#return

			# self.Debug(wdb,i);





#FINALLY!
						

#The problem can be avoided by improving the Evaluation of the pieces

	#Can add Positional Information, where if the Piece is past a certain line
	#Add a + modifier to it's value

	def Eval_Piece(self,char_Piece, x=-1, y=-1):
		#Here this will take some Time in deriving the Score

		#To calculate score we need to know if we are white or black

		#Higher Score = Best Move

		#Lower Score = Worst Move
		modifier=0;
		# + 7 is added to remove equality from taking a piece vs moving one
		#7 is max you can get from pure movement, thus this is sufficient to offset 
		#pure movement moves

		modifier=(WildaBeastSolver.lookup_Piece[ char_Piece.lower()]+7)

		#Add Whatever the Max Positional Data is to the above score 
		#to keep things consistent. Taking pieces > moving a piece


		#Positional Data
		if((x>-1 and x<8) and (y>-1 and y<8)):
			if(char_Piece.islower()):
				#Black should get an increase modifier dependent on how close they are to reaching the end
				modifier+= (7-y)
			else:
				modifier+= (y)


		return (modifier)










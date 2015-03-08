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

#Debugging for Tree

class WildaBeastSolver:
	#Target Depth
	targetDepth=3;

	currentDepth=0;

	#-1 are used as flags to represent no score
	betaValue=-1;
	alphaValue=-1;
	evaluationScore=0;

	string_Representation="_";


	chosen_NextMove="";

	#The List of Children
	list_Children=[]

	#List of Children Strings
	list_Children_Strings=[]
	list_Children_Evals  =[]

	str_TreeDrawer="";




	# Pass in a Chess GameBoard File with correct Format
	def __init__( self, filestring, depth=0, alpha=None, beta=None):
 		'''
		line ="";
		with open( filePath, "r") as ins:
			linesRead = []
			for line in ins:
				linesRead.append(line)

		#At this point the Lines are all read into the program
		#Chess Board Calculated from Top Left to Bot Right 0,0   7,7
		'''
		self.string_Representation= ""
		self.string_Representation+=(filestring)

		self.currentDepth 			=depth;
		self.list_Children 			=[]
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


		for y in range(1, len(linesRead)):  #Row
			line = linesRead[y]
			for x in range (0, len(line)):	#Column
				if( line[x] =='P'):
					board[x][(y-1)]	= Pawn(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='p'):
					board[x][(y-1)]	= Pawn(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='J'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='j'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='K'):
					board[x][(y-1)]	= King(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='k'):
					board[x][(y-1)]	= King(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='O'):
					board[x][(y-1)]	= OldWoman(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='o'):
					board[x][(y-1)]	= OldWoman(x,(y-1),0)
					board[x][(y-1)].wds =self					
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='R'):
					board[x][(y-1)]	= Rook(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;				

				elif( line[x] =='r'):
					board[x][(y-1)]	= Rook(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='B'):
					board[x][(y-1)]	= Bishop(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='b'):
					board[x][(y-1)]	= Bishop(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='C'):
					board[x][(y-1)]	= Catapult(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='c'):
					board[x][(y-1)]	= Catapult(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='S'):
					board[x][(y-1)]	= Serpent(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='s'):
					board[x][(y-1)]	= Serpent(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='Z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
				elif( line[x] =='z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
				elif( line[x] =='G'):
					board[x][(y-1)]	= Gorilla(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;					
				elif( line[x] =='g'):

					board[x][(y-1)]	= Gorilla(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
				elif( line[x] =='E'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='e'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='W'):
					board[x][(y-1)]	= JetPack(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='w'):
					board[x][(y-1)]	= JetPack(x,(y-1),0)
					board[x][(y-1)].wds =self	
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='T'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
				elif( line[x] =='t'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='H'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;
				elif( line[x] =='h'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),0)
					board[x][(y-1)].wds =self					
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;					

				elif( line[x] =='X'):
					board[x][(y-1)]	= GolfCart(x,(y-1),1)
					board[x][(y-1)].wds =self
					self.evaluationScore+= self.Eval_Piece(line[x])* inverseSigns;

				elif( line[x] =='x'):
					board[x][(y-1)]	= GolfCart(x,(y-1),0)	
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;


		#Let Each Piece determine the Next Board State based on the Piece's Logic

		calcBoard_Num=0;
		#Iterate through the Entire Board calculating the Next Turn for Each Piece
		for x in range (0, 8):
			for y in range (0,8):
			#Calculate the next BoardState while return
				if(board[x][y]!=None):
					# board[x][y].wds = self
					# print("["+str(x)+"]["+str(y)+"]")
					# print("Board="+filestring)
					calcBoard_Num+= board[x][y].Calc_PotentialMoves(board,currentPlayer,calcBoard_Num)

				#Can be modified by passing in a Node class, and when _printboard is called.
				# A child node is instead created


		# At this point we have a list of Strings which can be used to Create out Children for AlphaBeta Pruning
		print("Depth:"+str(self.currentDepth)+" My Children:"+ str(len(self.list_Children_Strings)))

		if(self.currentDepth<WildaBeastSolver.targetDepth):
			self.evaluationScore=None



		if(self.currentDepth<WildaBeastSolver.targetDepth):
			#print("Setting up kids")
			self.Setup_Children()


		print("Depth:"+str(self.currentDepth)+" Evaled Children:"+ str(len(self.list_Children)))
		isMinNode=False;
		if(depth%2==1):	#Odd is always a Min node, 0=Even=Max
			isMinNode=True;

		# if(isMinNode):
		# 	print("MIN-Depth["+str(self.currentDepth)+"]\tValue="+str(self.evaluationScore)+("\tAlpha="+ str(self.alphaValue)+" Beta="+ str(self.betaValue)))
		# else:
		# 	print("MAX-Depth["+str(self.currentDepth)+"]\tValue="+str(self.evaluationScore)+("\tAlpha="+ str(self.alphaValue)+" Beta="+ str(self.betaValue)))



	#Here we Iterate through the files and create our children
	def Setup_Children(self):
		depth =(self.currentDepth+1)

		index =0;
		targetVal=None

		isMinNode=False;
		if(self.currentDepth%2==1):	#Odd is always a Min node, 0=Even=Max
			isMinNode=True;

		curVal=0

		#print(str(halfChildren))

		for childString in self.list_Children_Strings:

			#Save time By ignoring branches if both AlphaBeta are set. Don't even create the child
			if(self.betaValue!=None and self.alphaValue!=None):
				#print("\nNEWDepth:"+str(self.currentDepth)+"Alpha="+str(self.alphaValue)+",Beta="+ str(self.betaValue) )
				return;

			#print("CN="+str(i))
			#wdb = WildaBeastSolver 	#.__new__()
			wdb= WildaBeastSolver(childString, (depth), self.alphaValue, self.betaValue)

			#This line is for Debugging only, careful it slows down the program
			self.list_Children.append(wdb) 


			#MinNode Cares about smallest Beta Value
			if(isMinNode):
				if(self.betaValue==None):
					self.betaValue		=	wdb.evaluationScore;
					self.evaluationScore= 	self.betaValue;
					self.chosen_NextMove=	wdb.string_Representation

				else:
					#Due to Sorting, we CAN'T do better anymore its IMPOSSIBLE, only equal or
					if(wdb.evaluationScore<self.betaValue):
						self.betaValue=wdb.evaluationScore;
						self.evaluationScore= 	self.betaValue;	
						self.chosen_NextMove=	wdb.string_Representation

					else:
						#No need to check more, prune other branches. Alpha Beta Pruning
						self.evaluationScore= self.betaValue;
						# if(curVal< halfChildren):
						# 	return

			#Max Node cares about biggest Alpha Value
			else:
				if(self.alphaValue==None):
					self.alphaValue=wdb.evaluationScore;
					self.evaluationScore= 	self.alphaValue;
					self.chosen_NextMove=	wdb.string_Representation

				else:
					if(wdb.evaluationScore>self.alphaValue):
						self.alphaValue=wdb.evaluationScore;
						self.evaluationScore= 	self.alphaValue;
						self.chosen_NextMove=	wdb.string_Representation

					else:
						#No need to check more, prune other branches. Alpha Beta Pruning
						self.evaluationScore= self.alphaValue;
						# if(curVal< halfChildren):
						# 	return

			curVal+=1;





	def Eval_Piece(self,char_Piece):
		#Here this will take some Time in deriving the Score

		#To calculate score we need to know if we are white or black

		#Higher Score = Best Move

		#Lower Score = Worst Move

		#Pawns are worth 1
		if(char_Piece=='P' or char_Piece=='p'):
			return 1;
		#King Like Pieces Worth 2
		if(char_Piece=='O' or char_Piece=='o'):
			return 3;
		if(char_Piece=='J' or char_Piece=='j'):
			return 3;

		#TPad= Kinda useful, but setup is bs
		if(char_Piece=='T' or char_Piece=='t'):
			return 4;

		if(char_Piece=='Z' or char_Piece=='z'):
			return 5;

		#Golf Cart captures enemy pieces if charged.
		if(char_Piece=='X' or char_Piece=='x'):
			return 6;

		#Rook weighs more than bishop
		if(char_Piece=='B' or char_Piece=='b'):
			return 8;


		#Serpent is slightly less broken than GE due to movement
		if(char_Piece=='S' or char_Piece=='s'):
			return 8;

		#Rook weighs more than bishop
		if(char_Piece=='R' or char_Piece=='r'):
			return 10;		


		#Serpent is slightly less broken than GE due to movement
		if(char_Piece=='W' or char_Piece=='w'):
			return 10;

		#Catapult is broken
		if(char_Piece=='C' or char_Piece=='c'):
			return 10;

		#Grand Empress is BS = Highest Weight
		if(char_Piece=='E' or char_Piece=='e'):
			return 20;

		#King = Highest Value piece
		if(char_Piece=='K' or char_Piece=='k'):
			return 100;

		#Can't kill gorillas, so they're score value is omitted
		return 0;









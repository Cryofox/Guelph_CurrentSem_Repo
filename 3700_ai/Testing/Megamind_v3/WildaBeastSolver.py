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

	#Debug
	DEBUG_InitCount=0;

	#Target Depth
	targetDepth=4;

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
		WildaBeastSolver.DEBUG_InitCount+=1;
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


		tempList=[]

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

				elif( line[x] =='k'):
					board[x][(y-1)]	= King(x,(y-1),0)
					board[x][(y-1)].wds =self
					self.evaluationScore-= self.Eval_Piece(line[x])* inverseSigns;
					tempList.append(board[x][(y-1)])

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



		#Let Each Piece determine the Next Board State based on the Piece's Logic

		calcBoard_Num=0;


		#Traversal must occur post Setup...
		# #Iterate through the Entire Board calculating the Next Turn for Each Piece
		# for x in range (0, 8):
		# 	for y in range (0,8):
		# 	#Calculate the next BoardState while return
		# 		if(board[x][y]!=None):           
		# 			calcBoard_Num+= board[x][y].Calc_PotentialMoves(board,currentPlayer,calcBoard_Num)


		for piece in tempList:
			piece.Calc_PotentialMoves(board,currentPlayer,0)



		del(tempList)
		# #ForLoopSpeedup
		# iX=0;

		# maxVal =( 8*8);

		# for iX in range(0,maxVal):
		# 	y= (int)(iX/8)
		# 	x= iX-(y*8);
		# 	if(board[x][y]!=None):           
		# 		calcBoard_Num+= board[x][y].Calc_PotentialMoves(board,currentPlayer,calcBoard_Num)
		if(self.currentDepth<WildaBeastSolver.targetDepth):
			self.evaluationScore=None
			self.Setup_Children()


	#Here we Iterate through the files and create our children
	def Setup_Children(self):
		depth =(self.currentDepth+1)

		index =0;
		targetVal=None

		isMinNode=False;
		if(self.currentDepth%2==1):	#Odd is always a Min node, 0=Even=Max
			isMinNode=True;

		listLen =len(self.list_Children_Strings)

		#Use a Buffered Length to limit the amount of checking we can do
		#with similar types
		#maxSimilar = (int)(listLen/(3.5))

		maxSimilar = (int)(listLen/(3.5))
		for i in range(0,listLen):
			#Save time By ignoring branches if both AlphaBeta are set. Don't even create the child
			if(self.betaValue!=None and self.alphaValue!=None):
				return;

			#MinNode Cares about smallest Beta Value
			if(isMinNode):
				wdb= WildaBeastSolver(self.list_Children_Strings[i], (depth), self.alphaValue, self.betaValue)

				if(self.betaValue==None):
					self.betaValue		=	wdb.evaluationScore;
					self.evaluationScore= 	self.betaValue;
					self.chosen_NextMove=	wdb.string_Representation

				else:
					if(wdb.evaluationScore  	<   self.betaValue):
						self.betaValue			=   wdb.evaluationScore;
						self.evaluationScore	= 	self.betaValue;	
						self.chosen_NextMove	=	wdb.string_Representation

					else:
						self.evaluationScore	= self.betaValue;
						return

			#Max Node cares about biggest Alpha Value
			else:
				wdb= WildaBeastSolver(self.list_Children_Strings[ (listLen-i-1)], (depth), self.alphaValue, self.betaValue)

				if(self.alphaValue==None):
					self.alphaValue 			= 	wdb.evaluationScore;
					self.evaluationScore		= 	self.alphaValue;
					self.chosen_NextMove		=	wdb.string_Representation
				#Need to determine when to stop evaluating nodes.
				else:
					if(wdb.evaluationScore		>	self.alphaValue):
						self.alphaValue			=	wdb.evaluationScore;
						self.evaluationScore	= 	self.alphaValue;
						self.chosen_NextMove	=	wdb.string_Representation

					elif(wdb.evaluationScore  	==  self.alphaValue):

						if(maxSimilar<=0):
							self.evaluationScore	= 	self.alphaValue;
							return	

						maxSimilar-=1;

					elif(wdb.evaluationScore  	<  	self.alphaValue):
					#else:
						self.evaluationScore	= 	self.alphaValue;
						return


						



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

		#Pawns are worth 1
		if(char_Piece=='P' or char_Piece=='p'):
			modifier= 1;
			modifier+=7
		#King Like Pieces Worth 2
		elif(char_Piece=='O' or char_Piece=='o'):
			modifier= 3;
			modifier+=7
		elif(char_Piece=='J' or char_Piece=='j'):
			modifier= 3;
			modifier+=7
		#TPad= Kinda useful, but setup is bs
		elif(char_Piece=='T' or char_Piece=='t'):
			modifier= 4;
			modifier+=7
		elif(char_Piece=='Z' or char_Piece=='z'):
			modifier= 5;
			modifier+=7
		#Golf Cart captures enemy pieces if charged.
		elif(char_Piece=='X' or char_Piece=='x'):
			modifier= 6;
			modifier+=7
		#Rook weighs more than bishop
		elif(char_Piece=='B' or char_Piece=='b'):
			modifier= 8;
			modifier+=7
		#Serpent is slightly less broken than GE due to movement
		elif(char_Piece=='S' or char_Piece=='s'):
			modifier= 8;
			modifier+=7
		#Rook weighs more than bishop
		elif(char_Piece=='R' or char_Piece=='r'):
			modifier= 10;		
			modifier+=7
		#Serpent is slightly less broken than GE due to movement
		elif(char_Piece=='W' or char_Piece=='w'):
			modifier= 10;
			modifier+=7
		#Catapult is broken
		elif(char_Piece=='C' or char_Piece=='c'):
			modifier= 10;
			modifier+=7
		#Grand Empress is BS = Highest Weight
		elif(char_Piece=='E' or char_Piece=='e'):
			modifier= 20;
			modifier+=7

		#King = Highest Value piece
		elif(char_Piece=='K' or char_Piece=='k'):
			modifier= 100;
			modifier+=7

		#Add Whatever the Max Positional Data is to the above score 
		#to keep things consistent. Taking pieces > moving a piece


		#Positional Data
		if((x>-1 and x<8) and (y>-1 and y<8)):
			if(char_Piece.islower()):
				#Black should get an increase modifier dependent on how close they are to reaching the end
				modifier+= (7-y)
			else:
				modifier+= (y)

		return modifier











#from OldWomanNegation import *
import os
import sys
import bisect

class Piece:
	_isWhite=False
	_posX	=0
	_posY	=0
	_pieceLetter='+'

	timePrinted=0

	depthLevel=0
	wds = None
	def __init__( self, posX, posY, isWhite):
		return

	#Returns a List of Positions this Piece can move onto
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):
		raise NotImplementedError("Calc_PotentialMoves");
		return 0;






		#this is the function called from all pieces
	def PrintBoard(self,board, currentPlayer,boardNum, capturedPiece):
		#print("PrintBoard Called")
		#Kill Joeys, if they're supposed to be dead
		self.KillJoey(board)

		#Kill Enemies Adjacent to Snake
		self.PoisonUnits(board)

		#Pawn Upgrade Logic


		pawnsModified=False
		incrementCount =0 

		for x in range(0,8):
			if(board[x][7]!=None and board[x][7].Get_Piece()=='P'):
				board[x][7].UpgradePawn(board,x,7,currentPlayer, capturedPiece,boardNum)
				pawnsModified=True
				incrementCount+=1
			if(board[x][0]!=None and board[x][0].Get_Piece()=='p'):
				board[x][0].UpgradePawn(board,x,0,currentPlayer, capturedPiece,boardNum)
				pawnsModified=True
				incrementCount+=1



		#Check for TransportPad
		if(not pawnsModified):
			if( capturedPiece!= None and ((capturedPiece.Get_Piece()=='T' and currentPlayer==0) or (capturedPiece.Get_Piece()=='t' and currentPlayer==1))):
				#Transport the Piece at capt Piece _X, _Y
				incrementCount+= self.Apply_Transport(board, capturedPiece._posX, capturedPiece._posY, currentPlayer, (boardNum+incrementCount))


		#If Pawns were not upgraded then we update the board here, otherwise the board has already been updated via the
		#Negate Boards that Result in capturing a Gorilla - Illegal Move
		if(not pawnsModified):
			if (not( capturedPiece!= None and (capturedPiece.Get_Piece()=='g' or capturedPiece.Get_Piece()=='G'))):
				self._PrintBoard(board,currentPlayer,(boardNum+incrementCount))
				incrementCount+=1

		return incrementCount




	def Apply_Transport(self, board, ogX, ogY, currentPlayer, boardNum):
		thePiece = board[ogX][ogY]

		inc =0
		for x in range(0,8):
			for y in range(0,8):
				if( board[x][y]==None):
					newBoard= self.DuplicateBoard(board)
					newBoard[x][y]=thePiece
					newBoard[ogX][ogY]=None;
					self.PrintBoard(newBoard,currentPlayer,(boardNum+inc),None);
					inc+=1

		return inc








	#CHeck if this piece at this position is floating based on an adjacent JetPack
	def IsFloating(self, board, posX, posY):
		#Gorillas Can't Fly...but golfcarts can *Shrug*
		if(board[posX][posY].Get_Piece() == 'g' or board[posX][posY].Get_Piece() == 'G'):
			return False

		if(board[posX][posY].Get_Piece() == 'w' or board[posX][posY].Get_Piece() == 'W'):
			return True

		listAdjacent=self.Get_AdjacentUnits(posX, posY, board)
 		for i in range(0, len(listAdjacent)):
 			#If its a jetpack of the same team as the piece at posX/Y, its floating
 			if((listAdjacent[i].Get_Piece()=='w' or listAdjacent[i].Get_Piece()=='W') and
 			(( listAdjacent[i]._isWhite == board[posX][posY]._isWhite) or 
 			( listAdjacent[i]._isWhite == board[posX][posY]._isWhite + 2))):
 				#print("done")
				return True


		#print("done")
		return False

	def IsParalyzed(self, board, posX,posY):
		#Check if it's Floating
		pieceIsFloating = self.IsFloating(board, posX,posY)
		beekeeperFloating = False

		#print("PreList")
		#Check if Enemy BeeKeeper is near us
		listAdjacent=self.Get_AdjacentUnits(posX, posY, board)
		#print("Post List")
 		for i in range(0, len(listAdjacent)):
 			#If its a beekeepr of the enemy team as the piece at posX/Y, its floating
 			if((listAdjacent[i].Get_Piece()=='z' or listAdjacent[i].Get_Piece()=='Z') and
	 			(not listAdjacent[i]._isWhite == board[posX][posY]._isWhite)):

 				#Now to Check if Beekeeper is floating
 				for x in range (0,8):
 					for y in range(0,8):
 						if(board[x][y]== listAdjacent[i]):
 							beekeeperFloating = self.IsFloating(board, x,y)

		 		if( pieceIsFloating and not beekeeperFloating):
		 			#print( self.Get_Piece()+ "Not Paralyzed 1")
		 			return False
		 		else: 
		 			#print( self.Get_Piece()+" True at"+ str(posX)+","+str(posY))
		 			#print( "Because:"+ str(listAdjacent[i]._posX)  +","+ str(listAdjacent[i]._posY) )
		 			#print( "List Contents: Size/Count "+ str(len(listAdjacent)) +","+ str(i))
		 			return True

		#no Beekeeper present
		#print( self.Get_Piece()+ "Not Paralyzed 2")
		return False


# Before a Board can be Printed the State of the board needs to be evaluated
# for additional possibilities such as poison, paralyses,
	
	#This is the actual board print code, it is placed here and marked with a _
	#to symbolize it should only be called from within this Class
	def _PrintBoard(self,board, currentPlayer,boardNum):
		# return
		formatedCount= ""

		if(Piece.timePrinted<10):
			formatedCount+="00"
		elif(Piece.timePrinted<100):
			formatedCount+="0"
		formatedCount+= str(Piece.timePrinted)

		#fileName=  str(self.depthLevel)+"/board."+formatedCount
		#boardFile = open(fileName,'w')
		boardFile="";
		if(currentPlayer==0):
			boardFile+=("B\n");
		else:
			boardFile+=("W\n");		

		# For each Row construct the String
		for y in range(0,8):
			rowString=""
			for x in range(0,8):
				if(board[x][y]==None):
					rowString+="."
				else:
					rowString+= board[x][y].Get_Piece()
			boardFile+=(rowString+"\n");




		index=1;


		#Store Moves in Evaluation Order
		#bisect.
		index= bisect.bisect(self.wds.list_Children_Evals,self.wds.evaluationScore)

		self.wds.list_Children_Evals.insert(index, self.wds.evaluationScore)

		self.wds.list_Children_Strings.insert(index, boardFile)
		

		#print("Index="+str(index))
		#print("Val="+str(self.wds.evaluationScore))
		
		#Check Folder Name for Last Used Number



	def UpgradePawn( self, board, x,y, currentPlayer, capturedPiece, boardNum):
		return False


	def KillJoey( self, board):
		whiteJoeyDead =False
		blackJoeyDead =False		
		#Check if a White Pawn is in Kill Joey Position

		for x in range(0,8):
			for y in range(0,8):
				#Check Black Pawns
				if(y <=1 ):
					if((board[x][y]!= None and board[x][y].Get_Piece()=='p')):
						blackJoeyDead=True
				if(y >=6 ):
					if((board[x][y]!= None and board[x][y].Get_Piece()=='P')):
						whiteJoeyDead=True				

		if(blackJoeyDead):
			for x in range(0,8):
				for y in range(0,8):
					#Find Enemy Joeys and Kill em all
					if( board[x][y]!= None and board[x][y].Get_Piece()=='j'):
						board[x][y] = None
		if(whiteJoeyDead):
			for x in range(0,8):
				for y in range(0,8):
					#Find Enemy Joeys and Kill em all
					if( board[x][y]!= None and board[x][y].Get_Piece()=='J'):
						board[x][y] = None

	def PoisonUnits( self, board):
		#Check for Snakes
		snakeList=[]
		for x in range (0,8):
			for y in range(0,8):
				if(board[x][y]!= None and (board[x][y].Get_Piece()=='S' or board[x][y].Get_Piece()=='s')):
					#Create new Snake Class since this could potentially be a MOVED snake
					snakeList.append( board[x][y])		

		#For Every Snake in the List check if it has units adjacent to Poison


		for i in range (0, len(snakeList)):
			try:
				for sX in range(0,8):
					for sY in range(0,8):
						if( board[sX][sY]== snakeList[i]):

							listPoisonedUnits = self.Get_AdjacentUnits(  sX, sY,board)

							#For Every Snake Check if the adjacent Poisoned units are adjacent to an old woman, and if they are
							#Kill the snake, and upgrade the old woman

							#For each of the Units check if any are Adjacent to an Old Woman
							for j in range (0, len(listPoisonedUnits)):
								#Since we can not poll their posX or posY due to that being used by the Original Board
								for x in range(0,8):
									for y in range(0,8):
										if(board[x][y]== listPoisonedUnits[j] and listPoisonedUnits[j]._isWhite != snakeList[i]._isWhite):
											list_potentialOldWoman = self.Get_AdjacentUnits(x,y,board)

											for p in range(0, len(list_potentialOldWoman)):
												for x2 in range(0,8):
													for y2 in range(0,8):
														if(board[x2][y2] == list_potentialOldWoman[p]):
															if(list_potentialOldWoman[p].Get_Piece() =='o' or list_potentialOldWoman[p].Get_Piece() =='O'):
																if(list_potentialOldWoman[p]._isWhite != snakeList[i]._isWhite):
																	#Kill the Snake
																	board[sX][sY]=None;
																	snakeList.pop(i)
																	#Insert None Object to reAlign List
																	snakeList.insert(i,None)
																	#Upgrade the Old Woman
																	board[x2][y2].Upgrade(board,x2,y2)
																	#print("OLD WOMAN YAY at="+ str(x2)+","+str(y2))
																	raise CustomException('Old Woman Saved the day!')

							# at this point if an old lady existed she would've saved the unit, therefore its safe to presume
							#these units must die
							isSnakeHovering = self.IsFloating(board, sX,sY)

							for j in range (0, len(listPoisonedUnits)):
								#Since we can not poll their posX or posY due to that being used by the Original Board
								for x in range(0,8):
									for y in range(0,8):
										if(board[x][y]== listPoisonedUnits[j] and listPoisonedUnits[j]._isWhite != snakeList[i]._isWhite and listPoisonedUnits[j]._isWhite != (snakeList[i]._isWhite+2)):
											if(board[x][y].Get_Piece() != 'g' and board[x][y].Get_Piece() != 'G'):

												#If the snake is hovering everythings poisoned, otherwise, if the snake is not hovering
												#and neithor is the piece
												if((isSnakeHovering) or (not self.IsFloating(board,x,y))):
													board[x][y]=None
													#print("Poison At:"+ str(x)+","+str(y))
							#raise CustomException('Old Woman Saved the day!')
			except Exception, e:
				#print("Exception was called")
				pass


		#Poison Grand Empress Units
		for eX in range(0,8):
			for eY in range(0,8):
				if( board[eX][eY]!= None and (board[eX][eY].Get_Piece()=='E' or board[eX][eY].Get_Piece()=='e')):
					listAdjacent = self.Get_AdjacentUnits(eX, eY, board)

					#Empress
					isEmpressHovering = self.IsFloating(board, eX,eY)
					for j in range (0, len(listAdjacent)):
						#Since we can not poll their posX or posY due to that being used by the Original Board
						for x in range(0,8):
							for y in range(0,8):
								if(board[x][y]== listAdjacent[j] and listAdjacent[j]._isWhite != board[eX][eY]._isWhite and  listAdjacent[j]._isWhite != (board[eX][eY]._isWhite+2)):
									if(board[x][y].Get_Piece() != 'g' and board[x][y].Get_Piece() != 'G'):

										if((isEmpressHovering) or (not self.IsFloating(board,x,y))):
											board[x][y]=None
											#print("Poison At:"+ str(x)+","+str(y))


		return






	def Get_AdjacentUnits(self, posX, posY, board):
		neighbourUnitList = []
		#right
		if( posX +1 < 8 and board[posX+1][posY] != None):
			neighbourUnitList.append(board[posX+1][posY])
			#print("1")

		#left
		if( posX -1 > -1 and board[posX-1][posY] != None):
			neighbourUnitList.append(board[posX-1][posY])
			#print("2")

		#up
		if( posY +1 < 8 and board[posX][posY+1] != None):
			neighbourUnitList.append(board[posX][posY+1])
			#print("3")

		#down
		if( posY -1 > -1 and board[posX][posY-1] != None):
			neighbourUnitList.append(board[posX][posY-1])
			#print("4")

		#Up right
		if( posX +1 < 8 and posY +1 <8 and board[posX+1][posY+1] != None):
			neighbourUnitList.append(board[posX+1][posY+1])
			#print("5")

		#Up left
		if( posX -1 > -1 and posY +1 <8 and board[posX-1][posY+1] != None):
			neighbourUnitList.append(board[posX-1][posY+1])
			#print("6")

		#down right
		if( posX +1 < 8 and posY -1 >-1 and board[posX+1][posY-1] != None):
			neighbourUnitList.append(board[posX+1][posY-1])
			#print("7")

		#down left
		if( posX -1 >-1 and posY -1 >-1 and board[posX-1][posY-1] != None):
			neighbourUnitList.append(board[posX-1][posY-1])
			#print("8")

		return neighbourUnitList




	#This is Where general board states get called. Such as Serpent Poison,
	#thiscan occur on any pieces turn and eithor player, so this should be called prior to updating the final board
	
	# Check if captured piece is a GORILLA

	def Get_Piece(self):
		return self._pieceLetter;


	#Returns a new Board with the same contents as the board passed in
	def DuplicateBoard(self, board):
		#
		dupBoard= [ [ None for i in range(8) ] for j in range(8) ]

		for x in range (0,8):
			for y in range(0,8):
				dupBoard[x][y] = board[x][y]

		return dupBoard;

	def Upgrade( self, board, x,y):
		return

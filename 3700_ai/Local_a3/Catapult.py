from Piece import *;

class Catapult(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='c'		
		if(isWhite):
			self._pieceLetter='C'

	#Returns a List of Positions this Piece can move onto

	# CurrentPlayerTurn :0 = White, 1= Black
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):



		#Store the Global Positions locally for Readability
		posX= self._posX
		posY= self._posY


		tempCount=0

		if( self.IsParalyzed(board, posX,posY)):
			return 0

		if(currentPlayer==0 and self._isWhite==1) or (currentPlayer==1 and self._isWhite==0):

		#The Catapult can fling units in the opposite direction they are to the Catapult

			#Check if a Friendly Unit is to the Right of a Catapult!
			if(posX+1<8):
				if(board[(posX+1)][posY] != None and board[(posX+1)][posY]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posX-i >-1) and (board[(posX-i)] [posY]== None or (board[(posX-i)] [posY]._isWhite != self._isWhite))):

							capturedPiece= board[(posX-i)][posY]
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break
							if( board[posX+1][posY].Get_Piece()=='h' or board[posX+1][posY].Get_Piece()=='H'):
								break
							if( board[posX+1][posY].Get_Piece()=='t' or board[posX+1][posY].Get_Piece()=='T'):
								break			

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX-i)][(posY)]= newBoard[(posX+1)][(posY)]	
							newBoard[(posX+1)][(posY)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
							

		#Check if a Friendly Unit is to the Left of a Catapult!
			if(posX-1>-1):
				if(board[(posX-1)][posY] != None and board[(posX-1)][posY]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posX+i <8) and (board[(posX+i)] [posY]== None or (board[(posX+i)] [posY]._isWhite != self._isWhite))):
							capturedPiece= board[(posX+i)][posY]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break
							if( board[posX-1][posY].Get_Piece()=='h' or board[posX-1][posY].Get_Piece()=='H'):
								break
							if( board[posX-1][posY].Get_Piece()=='t' or board[posX-1][posY].Get_Piece()=='T'):
								break		

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX+i)][(posY)]= newBoard[(posX-1)][(posY)]	
							newBoard[(posX-1)][(posY)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
							

		#Now for Vertical
		#Check if a Friendly Unit is Above of a Catapult!
			if(posY-1>-1):
				if(board[(posX)][posY-1] != None and board[(posX)][posY-1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posY+i <8) and (board[(posX)] [(posY+i)]== None or (board[(posX)] [(posY+i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX)][posY+i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break
							if( board[posX][posY-1].Get_Piece()=='h' or board[posX][posY-1].Get_Piece()=='H'):
								break
							if( board[posX][posY-1].Get_Piece()=='t' or board[posX][posY-1].Get_Piece()=='T'):
								break		

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX)][(posY+i)]= newBoard[(posX)][(posY-1)]	
							newBoard[(posX)][(posY-1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
						

		#Check if a Friendly Unit is Below of a Catapult!
			if(posY+1<8):
				if(board[(posX)][posY+1] != None and board[(posX)][posY+1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posY-i >-1) and (board[(posX)] [(posY-i)]== None or (board[(posX)] [(posY-i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX)][posY-i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break	
							if( board[posX][posY+1].Get_Piece()=='h' or board[posX][posY+1].Get_Piece()=='H'):
								break
							if( board[posX][posY+1].Get_Piece()=='t' or board[posX][posY+1].Get_Piece()=='T'):
								break	
							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX)][(posY-i)]= newBoard[(posX)][(posY+1)]	
							newBoard[(posX)][(posY+1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					


		#Check if a Friendly Unit is Up Right of a Catapult!
		#DIAGONAL
			if( posX +1 <8 and posY+1 <8):
				if(board[(posX+1)][(posY+1)] != None and board[(posX+1)][posY+1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posY-i >-1 and posX -i >-1) and (board[(posX-i)] [(posY-i)]== None or (board[(posX-i)] [(posY-i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX-i)][posY-i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break	
							if( board[posX+1][posY+1].Get_Piece()=='h' or board[posX+1][posY+1].Get_Piece()=='H'):
								break
							if( board[posX+1][posY+1].Get_Piece()=='t' or board[posX+1][posY+1].Get_Piece()=='T'):
								break	

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX-i)][(posY-i)]= newBoard[(posX+1)][(posY+1)]	
							newBoard[(posX+1)][(posY+1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					

		#Check if a Friendly Unit is Up Left of a Catapult!
		#DIAGONAL
			if(posX -1 >-1 and posY+1 <8 ):
				if(board[(posX-1)][posY+1] != None and board[(posX-1)][posY+1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posY-i >-1 and posX +i <8) and (board[(posX+i)] [(posY-i)]== None or (board[(posX+i)] [(posY-i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX+i)][posY-i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break	
							if( board[posX-1][posY+1].Get_Piece()=='h' or board[posX-1][posY+1].Get_Piece()=='H'):
								break
							if( board[posX-1][posY+1].Get_Piece()=='t' or board[posX-1][posY+1].Get_Piece()=='T'):
								break	

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX+i)][(posY-i)]= newBoard[(posX-1)][(posY+1)]	
							newBoard[(posX-1)][(posY+1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
						

		#Check if a Friendly Unit is Up Left of a Catapult!
		#DIAGONAL
			if(posX +1 <8 and posY-1 >-1 ):
				if(board[(posX+1)][posY-1] != None and board[(posX+1)][posY-1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if((posX -i >-1 and posY+i <8) and (board[(posX-i)] [(posY+i)]== None or (board[(posX-i)] [(posY+i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX-i)][posY+i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break		
							if( board[posX+1][posY-1].Get_Piece()=='h' or board[posX+1][posY-1].Get_Piece()=='H'):
								break
							if( board[posX+1][posY-1].Get_Piece()=='t' or board[posX+1][posY-1].Get_Piece()=='T'):
								break	

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX-i)][(posY+i)]= newBoard[(posX+1)][(posY-1)]	
							newBoard[(posX+1)][(posY-1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					

		#Check if a Friendly Unit is Up Right of a Catapult!
		#DIAGONAL
			if(posX -1 >-1 and posY-1 >-1 ):
				if(board[(posX-1)][posY-1] != None and board[(posX-1)][posY-1]._isWhite == self._isWhite):
					#Set the units position to Null

					#Fling on any non Friendly Positioned Tile (EXcluding Teleport Pad)
					for i in range( 1, 8):
						#If its not a Friendly Piece     ( Remember to Modify to Allow Teleport Pad)
						if(( posY+i <8 and posX +i <8) and (board[(posX+i)] [(posY+i)]== None or (board[(posX+i)] [(posY+i)]._isWhite != self._isWhite))):
							capturedPiece= board[(posX+i)][posY+i]	
							if(capturedPiece!=None and (capturedPiece.Get_Piece()=='k' or capturedPiece.Get_Piece()=='K')):
								break		
							if( board[posX-1][posY-1].Get_Piece()=='h' or board[posX-1][posY-1].Get_Piece()=='H'):
								break
							if( board[posX-1][posY-1].Get_Piece()=='t' or board[posX-1][posY-1].Get_Piece()=='T'):
								break	

							#Duplicate the Board to not affect the original
							newBoard = self.DuplicateBoard(board)
							newBoard[(posX+i)][(posY+i)]= newBoard[(posX-1)][(posY-1)]	
							newBoard[(posX-1)][(posY-1)]= None
							#print("GOGO CATA PULT GOOOOOOOOO")
							#Print Board
							tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
						

		#Serpent Code
			#Move Right
			if (posX +1 < 8):
				if(board[ (posX+1)][posY] == None ):
	 				capturedPiece= board[(posX+1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					

			#Move Left
			if (posX -1 > -1):
				if(board[ (posX-1)][posY] == None ): 			
					capturedPiece= board[(posX-1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Up
			if (posY +1 < 8):
				if(board[ (posX)][(posY+1)] == None ): 
					capturedPiece= board[(posX)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][(posY+1)]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down
			if (posY -1 > -1):
				if(board[ (posX)][(posY -1)] == None ): 
					capturedPiece= board[(posX)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][(posY -1)]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				


			##Diagonal Movement

			#Move Up Right
			if (posX +1 < 8) and (posY+1 < 8):
				if(board[ (posX+1)][(posY+1)] == None ):
					capturedPiece= board[(posX+1)][(posY+1)]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][(posY+1)]	= newBoard [posX][posY]
					newBoard[posX][posY]			= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Up Left
			if (posX -1 > -1) and (posY+1 < 8):
				if(board[ (posX-1)][(posY+1)] == None ):
					capturedPiece= board[(posX-1)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][(posY+1)]	= newBoard [posX][posY]
					newBoard[posX][posY]			= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down Right
			if (posX +1 < 8) and (posY-1 >-1):
				if(board[ (posX+1)][(posY-1)] == None ):
					capturedPiece= board[(posX+1)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][(posY-1)]	= newBoard [posX][posY]
					newBoard[posX][posY]			= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down Left
			if (posX -1 > -1) and (posY-1 >-1):
				if(board[ (posX-1)][(posY-1)] == None ):
					capturedPiece= board[(posX-1)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][(posY-1)]	= newBoard [posX][posY]
					newBoard[posX][posY]			= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)





		return tempCount


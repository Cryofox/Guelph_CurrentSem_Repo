from Piece import *;

class JetPack(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='w'		
		if(isWhite):
			self._pieceLetter='W'

	#Returns a List of Positions this Piece can move onto

	# CurrentPlayerTurn :0 = White, 1= Black
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):



		#Store the Global Positions locally for Readability
		posX= self._posX
		posY= self._posY


		tempCount=0
		
		if( self.IsParalyzed(board, posX,posY)):
			return 0
		##################################
		#White Player
		##################################

		if(currentPlayer==0 and self._isWhite==1) or (currentPlayer==1 and self._isWhite==0):
			#Move Up Right
			if (posX +1 < 8 and posY +2 <8):
				if(board[ (posX+1)][posY+2] == None ):
					capturedPiece= board[(posX+1)][posY+2]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY+2]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Up Left
			if (posX -1 >-1 and posY +2 <8):
				if(board[ (posX-1)][posY+2] == None ):
					capturedPiece= board[(posX-1)][posY+2]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY+2]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Down Right
			if (posX +1 < 8 and posY -2 >-1):
				if(board[ (posX+1)][posY-2] == None ):
					capturedPiece= board[(posX+1)][posY-2]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY-2]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Down Left
			if (posX -1 >-1 and posY -2 >-1):
				if(board[ (posX-1)][posY-2] == None ):
					capturedPiece= board[(posX-1)][posY-2]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY-2]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1



			#Move Right Up
			if (posX +2 < 8 and posY +1 <8):
				if(board[ (posX+2)][posY+1] == None ):
					capturedPiece= board[(posX+2)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+2)][posY+1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Right Down
			if (posX +2 < 8 and posY -1 >-1):
				if(board[ (posX+2)][posY-1] == None ):
					capturedPiece= board[(posX+2)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+2)][posY-1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Left Up
			if (posX -2 >-1 and posY +1 <8):
				if(board[ (posX-2)][posY+1] == None ):
					capturedPiece= board[(posX-2)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-2)][posY+1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Left Down
			if (posX -2 >-1 and posY -1 >-1):
				if(board[ (posX-2)][posY-1] == None ):
					capturedPiece= board[(posX-2)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-2)][posY-1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

		return tempCount


from Piece import *;

class PrinceJoey(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='j'		
		if(isWhite):
			self._pieceLetter='J'

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
			#Move Right
			if (posX +1 < 8):
				if(board[ (posX+1)][posY] == None or not board[ (posX+1)][posY]._isWhite == self._isWhite):
					capturedPiece= board[(posX+1)][posY]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX+1)][posY]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					

			#Move Left
			if (posX -1 > -1):
				if(board[ (posX-1)][posY] == None or not board[ (posX-1)][posY]._isWhite == self._isWhite):
					capturedPiece= board[(posX-1)][posY]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX-1)][posY]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Up
			if (posY +1 < 8):
				if(board[ (posX)][(posY+1)] == None or not board[ (posX)][(posY+1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX)][posY+1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX)][(posY+1)]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down
			if (posY -1 > -1):
				if(board[ (posX)][(posY -1)] == None or not board[ (posX)][(posY -1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX)][posY-1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX)][(posY -1)]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				


			##Diagonal Movement

			#Move Up Right
			if (posX +1 < 8) and (posY+1 < 8):
				if(board[ (posX+1)][(posY+1)] == None or not board[ (posX+1)][(posY+1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX+1)][(posY+1)]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX+1)][(posY+1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Up Left
			if (posX -1 > -1) and (posY+1 < 8):
				if(board[ (posX-1)][(posY+1)] == None or not board[ (posX-1)][(posY+1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX-1)][posY+1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX-1)][(posY+1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down Right
			if (posX +1 < 8) and (posY-1 >-1):
				if(board[ (posX+1)][(posY-1)] == None or not board[ (posX+1)][(posY-1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX+1)][posY-1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX+1)][(posY-1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				

			#Move Down Left
			if (posX -1 > -1) and (posY-1 >-1):
				if(board[ (posX-1)][(posY-1)] == None or not board[ (posX-1)][(posY-1)]._isWhite == self._isWhite):
					capturedPiece= board[(posX-1)][posY-1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)
						
						newBoard[(posX-1)][(posY-1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
				


		return tempCount


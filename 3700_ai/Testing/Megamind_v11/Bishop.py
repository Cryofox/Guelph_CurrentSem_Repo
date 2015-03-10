from Piece import *;

class Bishop(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='b'		
		if(isWhite):
			self._pieceLetter='B'

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
			#Bishop Movement
			for x in range(1,8):
				if( (posX+x) <8  and (posY+x) <8):
					collision=False
					for i in range(1, x):
						if(board[ (posX+i)][posY+i] != None):
							collision=True
							break

					if(not collision):
						if(board[ (posX+x)][posY+x] == None or not board[ (posX+x)][posY+x]._isWhite == self._isWhite):
							capturedPiece= board[(posX+x)][posY+x]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):		
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX+x)][posY+x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Board
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1

				if( (posX-x) >-1  and (posY-x) >-1):
					collision=False
					for i in range(1, x):
						if(board[ (posX-i)][posY-i] != None):
							collision=True
							break

					if(not collision):
						if(board[ (posX-x)][posY-x] == None or not board[ (posX-x)][posY-x]._isWhite == self._isWhite):
							capturedPiece= board[(posX-x)][posY-x]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX-x)][posY-x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Board
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1
		
				if( (posX+x) <8  and (posY-x) >-1):
					collision=False
					for i in range(1, x):
						if(board[ (posX+i)][posY-i] != None):
							collision=True
							break

					if(not collision):
						if(board[ (posX+x)][posY-x] == None or not board[ (posX+x)][posY-x]._isWhite == self._isWhite):
							capturedPiece= board[(posX+x)][posY-x]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX+x)][posY-x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Board
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1
				
				if( (posX-x) >-1  and (posY+x) <8):
					collision=False
					for i in range(1, x):
						if(board[ (posX-i)][posY+i] != None):
							collision=True
							break

					if(not collision):
						if(board[ (posX-x)][posY+x] == None or not board[ (posX-x)][posY+x]._isWhite == self._isWhite):
							capturedPiece= board[(posX-x)][(posY+x)]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)
 
								newBoard[(posX-x)][posY+x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Board
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1					
				

		return tempCount


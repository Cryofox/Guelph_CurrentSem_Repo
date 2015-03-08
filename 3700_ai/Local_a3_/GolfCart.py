from Piece import *;

class GolfCart(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='x'		
		if(isWhite):
			self._pieceLetter='X'

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
			if (posX +1 < 8 and (posY==7 or posY==0)):
				if(board[ (posX+1)][posY] == None or board[(posX+1)][posY]._isWhite!= self._isWhite):
					capturedPiece= board[(posX+1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Left
			if (posX -1 > -1 and (posY==7 or posY==0)):
				if(board[ (posX-1)][posY] == None or board[(posX-1)][posY]._isWhite!= self._isWhite):
					capturedPiece= board[(posX-1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Up
			if (posY +1 < 8):
				if(self.AmICharged(board) and not self.IsThereaGorilla(board,True)):
					capturedPiece= board[(posX)][7]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][7] = newBoard [posX][posY]

					for y in range(0,7):
						newBoard[posX][y]=None

					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1

			#Move Donw
			if (posY -1 >-1):
				if(self.AmICharged(board) and not self.IsThereaGorilla(board,False)):
					capturedPiece= board[(posX)][0]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][0] = newBoard [posX][posY]

					for y in range(1,8):
						newBoard[posX][y]=None

					#Print Board
					self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
					tempCount+=1			

		
		return tempCount



	def AmICharged(self,board):
		if(self._isWhite==1):
			#If Pawn has crossed the line
			for x in range(0,8):
				for y in range(0,2):
					if(board[x][y]!=None and board[x][y].Get_Piece()=='p'):
						return True
			#IF Time Machine Exists
			for x in range(0,8):
				for y in range(0,8):
					if(board[x][y]!=None and board[x][y].Get_Piece()=='H'):
						return True	

		if(self._isWhite==0):
			#If Pawn has crossed the line
			for x in range(0,8):
				for y in range(6,8):
					if(board[x][y]!=None and board[x][y].Get_Piece()=='P'):
						return True
			#IF Time Machine Exists
			for x in range(0,8):
				for y in range(0,8):
					if(board[x][y]!=None and board[x][y].Get_Piece()=='h'):
						return True									


		return False


	def IsThereaGorilla(self,board, isUP):
		posX= self._posX;
		posY= self._posY

		if( isUP):
			for y in range(0, (8-posY)):
				if(board[posX][y+posY]!=None and (board[posX][y+posY].Get_Piece()=='g' or board[posX][y+posY].Get_Piece()=='G')):
					return True

		else:
			for y in range(0, (8-(8-posY))):
				if(board[posX][posY-y]!=None and (board[posX][posY-y].Get_Piece()=='g' or board[posX][posY-y].Get_Piece()=='G')):
					return True			
		return False
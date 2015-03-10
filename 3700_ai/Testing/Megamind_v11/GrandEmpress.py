from Piece import *;

class GrandEmpress(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='e'		
		if(isWhite):
			self._pieceLetter='E'

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
			#Cycle through all Vertical and Horizontal positions
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
			#Rook Movement
			for x in range(1,8):
				if( (posX+x) <8 ):
					collision=False
					for i in range(1, x):
						if(board[ (posX+i)][posY] != None):
							collision=True
							break

					if(not collision):
						if(board[ (posX+x)][posY] == None or not board[ (posX+x)][posY]._isWhite == self._isWhite):
							capturedPiece= board[(posX+x)][posY]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX+x)][posY]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;	
								#Print B	oard
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1

				if( (posX-x) >-1 ):
					collision=False
					for i in range(1, x):
						if(board[ (posX-i)][posY] != None):
							collision=True
							break

					if(not collision):									
						if(board[ (posX-x)][posY] == None or not board[ (posX-x)][posY]._isWhite == self._isWhite):
							capturedPiece= board[(posX-x)][posY]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX-x)][posY]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Boa	rd
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1

				if( (posY+x <8) ):	
					collision=False
					for i in range(1, x):
						if(board[ (posX)][posY+i] != None):
							collision=True
							break

					if(not collision):					
						if(board[ (posX)][posY+x] == None or not board[ (posX)][posY+x]._isWhite == self._isWhite):
							capturedPiece= board[(posX)][posY+x]	
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):							
								#Duplicate the Board to not affect the original
								newBoard = self.DuplicateBoard(board)

								newBoard[(posX)][posY+x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;	
								#Print B	oard
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1

				if( (posY-x) >-1 ):
					collision=False
					for i in range(1, x):
						if(board[ (posX)][posY-i] != None):
							collision=True
							break

					if(not collision):							
						if(board[ (posX)][posY-x] == None or not board[ (posX)][posY-x]._isWhite == self._isWhite):
							capturedPiece= board[(posX)][posY-x]
							if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):									
	
								#Duplica	te the Board to not affect the original
								newBoard	 = self.DuplicateBoard(board)

								newBoard[(posX)][posY-x]	= newBoard [posX][posY]
								newBoard[posX][posY]		= None;
								#Print Board
								self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
								tempCount+=1	

			#Modified JetPack 

			#Move Up Right
			if (posX +1 < 8 and posY +2 <8):
				if(board[ (posX+1)][posY+2] == None or not board[ (posX+1)][posY+2]._isWhite == self._isWhite):
					capturedPiece= board[(posX+1)][posY+2]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+1)][posY+2]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Up Left
			if (posX -1 >-1 and posY +2 <8):
				if(board[ (posX-1)][posY+2] == None or not board[ (posX-1)][posY+2]._isWhite == self._isWhite):
					capturedPiece= board[(posX-1)][posY+2]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-1)][posY+2]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Down Right
			if (posX +1 < 8 and posY -2 >-1):
				if(board[ (posX+1)][posY-2] == None or not board[ (posX+1)][posY-2]._isWhite == self._isWhite):
					capturedPiece= board[(posX+1)][posY-2]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+1)][posY-2]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Down Left
			if (posX -1 >-1 and posY -2 >-1):
				if(board[ (posX-1)][posY-2] == None or not board[ (posX-1)][posY-2]._isWhite == self._isWhite):
					capturedPiece= board[(posX-1)][posY-2]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-1)][posY-2]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1



			#Move Right Up
			if (posX +2 < 8 and posY +1 <8):
				if(board[ (posX+2)][posY+1] == None or not board[ (posX+2)][posY+1]._isWhite == self._isWhite):
					capturedPiece= board[(posX+2)][posY+1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+2)][posY+1]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Right Down
			if (posX +2 < 8 and posY -1 >-1):
				if(board[ (posX+2)][posY-1] == None or not board[ (posX+2)][posY-1]._isWhite == self._isWhite):
					capturedPiece= board[(posX+2)][posY-1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+2)][posY-1]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Left Up
			if (posX -2 >-1 and posY +1 <8):
				if(board[ (posX-2)][posY+1] == None or not board[ (posX-2)][posY+1]._isWhite == self._isWhite):
					capturedPiece= board[(posX-2)][posY+1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-2)][posY+1]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

			#Move Left Down
			if (posX -2 >-1 and posY -1 >-1):
				if(board[ (posX-2)][posY-1] == None or not board[ (posX-2)][posY-1]._isWhite == self._isWhite):
					capturedPiece= board[(posX-2)][posY-1]
					if(capturedPiece == None or not(capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY))):	
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-2)][posY-1]	= newBoard [posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board
						self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount), capturedPiece)
						tempCount+=1

		return tempCount


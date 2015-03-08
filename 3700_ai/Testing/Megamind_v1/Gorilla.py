
from Piece import *;
from Rook import *;
from Bishop import *;

from Serpent import *;
from Transporterpad import *;
from TimeMachine import *;
from JetPack import *;
class Gorilla(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='g'		
		if(isWhite):
			self._pieceLetter='G'

	#Returns a List of Positions this Piece can move onto

	# CurrentPlayerTurn :0 = White, 1= Black
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):



		#Store the Global Positions locally for Readability
		posX= self._posX
		posY= self._posY


		tempCount=0

		if( self.IsParalyzed(board, posX,posY)):
			return 0
		#Edge Case
		######################################################+
		if(currentPlayer==0 and self._isWhite==1) or (currentPlayer==1 and self._isWhite==0):
			#Move Right
			if (posX +1 ==7):
				if(board[ (posX+1)][posY] == None ):
					#print("Here We GO:"+ str((posX+1))+","+str((posY)))
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)


			#Move Left
			if (posX -1 == 0):
				if(board[ (posX-1)][posY] == None ):
					#print("Here We GO:"+ str((posX-1))+","+str((posY)))
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
		

			#Move Up
			if (posY +1 == 7):
				if(board[ (posX)][(posY+1)] == None ):
					#print("Here We GO:"+ str((posX))+","+str((posY+1)))
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][(posY+1)]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
	
			#Move Down
			if (posY -1 == 0):
				if(board[ (posX)][(posY -1)] == None ):
					#print("Here We GO:"+ str((posX))+","+str((posY-1)))
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][(posY -1)]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
			


			##Diagonal Movement

			#Move Up Right
			if ((posX +1 == 7) or (posY+1 == 7)):
				if( posX +1 <8 and posY+1 < 8):
					if(board[ (posX+1)][(posY+1)] == None ):

						#print("Here We GO:"+ str((posX+1))+","+str((posY+1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+1)][(posY+1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
			

			#Move Up Left
			if (posX -1 == 0) or (posY+1 == 7):
				if( posX -1 >-1 and posY+1 < 8):
					if(board[ (posX-1)][(posY+1)] == None ):

						#print("Here We GO:"+ str((posX-1))+","+str((posY+1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-1)][(posY+1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
					

			#Move Down Right
			if (posX +1 == 7) or  (posY-1 ==0):
				if( posX +1 <8 and posY-1 >-1):
					if(board[ (posX+1)][(posY-1)] == None ):
						#print("Here We GO:"+ str((posX+1))+","+str((posY-1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+1)][(posY-1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
		

			#Move Down Left
			if (posX -1 == 0) or (posY-1 ==0):
				if( posX -1 >-1 and posY-1 >-1):
					if(board[ (posX-1)][(posY-1)] == None ):
						#print("Here We GO:"+ str((posX-1))+","+str((posY-1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-1)][(posY-1)]	= newBoard [posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)

		######################################################
			#Move Right
			if (posX +1 <7):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX+1)][posY] != None) and  not(board[ (posX+1)][posY].Get_Piece()=='g' or board[ (posX+1)][posY].Get_Piece()=='G')  ):

					if(not board[ (posX+1)][posY].IsFloating(board, (posX+1), posY) and not self.IsFloating(board, posX,posY)):	
						capturedPiece= board[(posX+2)][posY]

						#print("Here We GO:"+ str((posX+1))+","+str((posY)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+2)][posY]	= newBoard [posX+1][posY]
						newBoard [posX+1][posY]		= newBoard[posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					capturedPiece= board[(posX+1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
				
			#Move Left
			if (posX -1 >0):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX-1)][posY] != None) and not (board[ (posX-1)][posY].Get_Piece()=='g' or board[ (posX-1)][posY].Get_Piece()=='G')  ):


					if(not board[ (posX-1)][posY].IsFloating(board, (posX-1), posY) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX-2)][posY]
						#print("Here We GO:"+ str((posX-1))+","+str((posY)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-2)][posY]	= newBoard [posX-1][posY]
						newBoard [posX-1][posY]		= newBoard[posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					#print("Here We GO:"+ str((posX-1))+","+str((posY)))
					capturedPiece= board[(posX-1)][posY]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

			#Move Down
			if (posY -1 >0):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX)][posY-1] != None)  and  not(board[ (posX)][posY-1].Get_Piece()=='g' or board[ (posX)][posY-1].Get_Piece()=='G')  ):

					if(not board[ (posX)][(posY-1)].IsFloating(board, (posX), (posY-1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX)][posY-2]
						#print("Here We GO:"+ str((posX))+","+str((posY-1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX)][posY-2]	= newBoard [posX][posY-1]
						newBoard [posX][posY-1]		= newBoard[posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					#print("Here We GO:"+ str((posX))+","+str((posY-1)))
					capturedPiece= board[(posX)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][posY-1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

			#Move Up
			if (posY +1 <7):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX)][posY+1] != None) and  not(board[ (posX)][posY+1].Get_Piece()=='g' or board[ (posX)][posY+1].Get_Piece()=='G')  ):
					
					if(not board[ (posX)][(posY+1)].IsFloating(board, (posX), (posY+1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX)][posY+2]
						#print("Here We GO:"+ str((posX))+","+str((posY+1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX)][posY+2]	= newBoard [posX][posY+1]
						newBoard [posX][posY+1]		= newBoard[posX][posY]
						newBoard[posX][posY]		= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					#print("Here We GO:"+ str((posX))+","+str((posY+1)))
					capturedPiece= board[(posX)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX)][posY+1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

			#Move Up Right
			if ( posX +1 <7 and posY +1 <7):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX+1)][posY+1] != None) and  not(board[ (posX+1)][posY+1].Get_Piece()=='g' or board[ (posX+1)][posY+1].Get_Piece()=='G')  ):

					if(not board[ (posX+1)][(posY+1)].IsFloating(board, (posX+1), (posY+1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX+2)][posY+2]
						#print("Here We GO:"+ str((posX+1))+","+str((posY+1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+2)][posY+2]		= newBoard [posX+1][posY+1]
						newBoard [posX+1][posY+1]		= newBoard[posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					#print("Here We GO:"+ str((posX+1))+","+str((posY+1)))
					capturedPiece= board[(posX+1)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY+1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

			#Move Up Left
			if (posX -1 >0 and posY +1 <7 ):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX-1)][posY+1] != None) and  not(board[ (posX-1)][posY+1].Get_Piece()=='g' or board[ (posX-1)][posY+1].Get_Piece()=='G')  ):

					if(not board[ (posX-1)][(posY+1)].IsFloating(board, (posX-1), (posY+1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX-2)][posY+2]
						#print("Here We GO:"+ str((posX-1))+","+str((posY+1)))
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-2)][posY+2]		= newBoard [posX-1][posY+1]
						newBoard [posX-1][posY+1]		= newBoard[posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

				else:
					#print("Here We GO:"+ str((posX-1))+","+str((posY+1)))
					capturedPiece= board[(posX-1)][posY+1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY+1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

			#Move Down Left
			if (posX -1 >-1 and posY -1 >0 ):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX-1)][posY-1] != None) and  not(board[ (posX-1)][posY-1].Get_Piece()=='g' or board[ (posX-1)][posY-1].Get_Piece()=='G')  ):
					if(not board[ (posX-1)][(posY-1)].IsFloating(board, (posX-1), (posY-1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX-2)][posY-2]
				
						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX-2)][posY-2]		= newBoard [posX-1][posY-1]
						newBoard [posX-1][posY-1]		= newBoard[posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					
				else:
					
					capturedPiece= board[(posX-1)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][posY-1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
										

			#Move Down Right
			if (posX +1 <7 and posY -1 >0 ):
				#If 2 spaces ahead we are not facing a GORILLA and we are pushing a piece
				if((board[ (posX+1)][posY-1] != None) and  not(board[ (posX+1)][posY-1].Get_Piece()=='g' or board[ (posX+1)][posY-1].Get_Piece()=='G')  ):
					if(not board[ (posX+1)][(posY-1)].IsFloating(board, (posX+1), (posY-1)) and not self.IsFloating(board, posX,posY)):	

						capturedPiece= board[(posX+2)][posY-2]

						#Duplicate the Board to not affect the original
						newBoard = self.DuplicateBoard(board)

						newBoard[(posX+2)][posY-2]		= newBoard [posX+1][posY-1]
						newBoard [posX+1][posY-1]		= newBoard[posX][posY]
						newBoard[posX][posY]			= None;
						#Print Board

						#Place Capture Pushed Piece Logic Here
						tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					
				else:
					capturedPiece= board[(posX+1)][posY-1]
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX+1)][posY-1]	= newBoard [posX][posY]
					newBoard[posX][posY]		= None;
					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
					
		return tempCount






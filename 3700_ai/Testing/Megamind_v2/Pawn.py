from Piece import *;


from Rook import *;
from Bishop import *;

from Serpent import *;
from Transporterpad import *;
from TimeMachine import *;
from JetPack import *;

class Pawn(Piece):

	def __init__( self, posX, posY, isWhite):
		self._isWhite= isWhite
		self._posX= posX
		self._posY= posY

		self._pieceLetter='p'		
		if(isWhite):
			self._pieceLetter='P'

	#Returns a List of Positions this Piece can move onto

	# CurrentPlayerTurn :0 = White, 1= Black
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):



		#Store the Global Positions locally for Readability
		posX= self._posX
		posY= self._posY


		tempCount=0
		#print("Pawn Movement Engaged")
		if( self.IsParalyzed(board, posX,posY)):
			return 0


		##################################
		#White Player
		##################################

		#Only perform if its white players turn and this piece belongs to White
		if(currentPlayer==0 and self._isWhite==1) :

			#Pawn Can move 1 Forward if there is no enemy directly in front
			if(posY+1 < 8):
				if( board [posX][ (posY+1)] == None):

					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][(posY+1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)



			#Pawn Can move 2 Forward if there is no enemy blocking the way, and the pawn is in the starting row
			if(posY+2 < 8):
				if(( board [posX][ (posY+1)] == None) and 
				   ( board [posX][ (posY+2)] == None) and 
					posY==1   ) :

					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][(posY+2)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)




			#Pawn Can Capture Diagonally only if an enemy piece exists at that location
			#Diag Left
			if((posY+1 < 8 and posX+1 <8) and
			board[(posX+1)][ (posY+1)] != None and 
			(not (board[(posX+1)][ (posY+1)]._isWhite==1)  ) ):

				capturedPiece= board[(posX+1)][posY+1]
				#Check if Piece is Not Hovering along with yourself
				if(not capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY)):	
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)
					
					newBoard[(posX+1)][ (posY+1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)


			#Pawn Can Capture Diagonally only if an enemy piece exists at that location
			#Diag Left
			if((posY+1 < 8 and posX-1 >-1) and
			board[(posX-1)][ (posY+1)] != None and  
			not (board[(posX-1)][ (posY+1)]._isWhite==1)):

				capturedPiece= board[(posX-1)][posY+1]	
				if(not capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY)):	
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][ (posY+1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;

					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)


		##################################
		#Black Player
		##################################


		#Only perform if its black players turn and this piece belongs to Black
		if(currentPlayer==1 and self._isWhite==0):

			#Pawn Can move 1 Forward if there is no enemy directly in front
			if(posY-1 >-1):
				if( board [posX][ (posY-1)] == None):

					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][(posY-1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)



			#Pawn Can move 2 Forward if there is no enemy blocking the way, and the pawn is in the starting row
			if(posY-2 > -1):
				if(( board [posX][ (posY-1)] == None) and 
				   ( board [posX][ (posY-2)] == None) and 
					posY==6   ) :

					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[posX][(posY-2)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),None)
				



			#Pawn Can Capture Diagonally only if an enemy piece exists at that location
			#Diag Left
			if((posY-1 >-1 and posX+1 <8) and
			board[(posX+1)][ (posY-1)] != None and  
			not(board[(posX+1)][ (posY-1)]._isWhite==0)):
				capturedPiece= board[(posX+1)][posY-1]	
				if(not capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY)):	
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)
					
					newBoard[(posX+1)][ (posY-1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;


					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)


			#Pawn Can Capture Diagonally only if an enemy piece exists at that location
			#Diag Left
			if((posY-1 > -1 and posX-1 >-1) and
			board[(posX-1)][ (posY-1)] != None and  
			not(board[(posX-1)][ (posY-1)]._isWhite==0)):
				capturedPiece= board[(posX-1)][posY-1]	
				if(not capturedPiece.IsFloating(board, capturedPiece._posX, capturedPiece._posY) and not self.IsFloating(board, posX,posY)):	
					#Duplicate the Board to not affect the original
					newBoard = self.DuplicateBoard(board)

					newBoard[(posX-1)][ (posY-1)]= newBoard [posX][posY]
					newBoard[posX][posY] = None;

					#Print Board
					tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)



		return tempCount





	#Placed here incase the Pawn is moved by other piece
	def UpgradePawn( self, board, x,y, currentPlayer, capturedPiece, boardNum):
		modifiedBoard= False
		tempCount=0
		#White Pawns


		#Replace and recall the PrintBoard Option
		

		newBoard = self.DuplicateBoard(board)
		newBoard[x][y] = Serpent(x,y, self._isWhite)
		tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)

		#Replace and recall the PrintBoard Option
		
		newBoard = self.DuplicateBoard(board)
		newBoard[x][y] = JetPack(x,y, self._isWhite)
		tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
		#tempCount+=1
		#Replace and recall the PrintBoard Option
		
		
		newBoard = self.DuplicateBoard(board)
		newBoard[x][y] = Transporterpad(x,y, self._isWhite)
		tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
		#tempCount+=1
		#Replace and recall the PrintBoard Option
		
		
		newBoard = self.DuplicateBoard(board)
		newBoard[x][y] = TimeMachine(x,y, self._isWhite)
		tempCount+=self.PrintBoard(newBoard, currentPlayer,(boardNum+tempCount),capturedPiece)
		#tempCount+=1


		#print("Pawn Code Called, I Should have Temped:"+ str(tempCount))
		modifiedBoard=True
		#This is called to prevent the board where a Pawn is placed from occuring
		return modifiedBoard
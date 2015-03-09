from Piece import *;

class Transporterpad(Piece):

	def __init__( self, posX, posY, isWhite):
	#Transport Pad Must no equal 0 or 1, but rather 2 and 3 to in
		self._isWhite= isWhite +2;
		self._posX= posX
		self._posY= posY

		self._pieceLetter='t'		
		if(isWhite):
			self._pieceLetter='T'

	#Returns a List of Positions this Piece can move onto

	# CurrentPlayerTurn :0 = White, 1= Black
	def Calc_PotentialMoves( self, board, currentPlayer, boardNum):
		
		return 0


from Pawn import *;
from PrinceJoey import *;
from King import *;
from Rook import *;
from Bishop import *;

from OldWoman import *;
from Catapult import *;
from Serpent import *;
from Beekeeper import *;
from Gorilla import *;

from Transporterpad import *;
from TimeMachine import *;
from JetPack import *;
from GolfCart import *;
from GrandEmpress import *;

import sys;

class WildaBeastSolver:
	# Pass in a Chess GameBoard File with correct Format
	def __init__( self, filePath):
		line ="";
		with open( filePath, "r") as ins:
			linesRead = []
			for line in ins:
				linesRead.append(line)

		#At this point the Lines are all read into the program
		#Chess Board Calculated from Top Left to Bot Right 0,0   7,7

		currentPlayer=1

		#If its white set it to white, otherwise its black
		if(linesRead[0][0]=='W' or linesRead[0][0]=='w'):
			currentPlayer=0


		#Create an Array of Pieces
		board= [ [ None for i in range(8) ] for j in range(8) ]

		for y in range(1, len(linesRead)):  #Row
			line = linesRead[y]
			for x in range (0, len(line)):	#Column
				if( line[x] =='P'):
					board[x][(y-1)]	= Pawn(x,(y-1),1)
				elif( line[x] =='p'):
					board[x][(y-1)]	= Pawn(x,(y-1),0)

				elif( line[x] =='J'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),1)
				elif( line[x] =='j'):
					board[x][(y-1)]	= PrinceJoey(x,(y-1),0)

				elif( line[x] =='K'):
					board[x][(y-1)]	= King(x,(y-1),1)
				elif( line[x] =='k'):
					board[x][(y-1)]	= King(x,(y-1),0)

				elif( line[x] =='O'):
					board[x][(y-1)]	= OldWoman(x,(y-1),1)
				elif( line[x] =='o'):
					board[x][(y-1)]	= OldWoman(x,(y-1),0)					

				elif( line[x] =='R'):
					board[x][(y-1)]	= Rook(x,(y-1),1)
				elif( line[x] =='r'):
					board[x][(y-1)]	= Rook(x,(y-1),0)

				elif( line[x] =='B'):
					board[x][(y-1)]	= Bishop(x,(y-1),1)
				elif( line[x] =='b'):
					board[x][(y-1)]	= Bishop(x,(y-1),0)	

				elif( line[x] =='C'):
					board[x][(y-1)]	= Catapult(x,(y-1),1)
				elif( line[x] =='c'):
					board[x][(y-1)]	= Catapult(x,(y-1),0)	


				elif( line[x] =='S'):
					board[x][(y-1)]	= Serpent(x,(y-1),1)
				elif( line[x] =='s'):
					board[x][(y-1)]	= Serpent(x,(y-1),0)	

				elif( line[x] =='Z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),1)
				elif( line[x] =='z'):
					board[x][(y-1)]	= Beekeeper(x,(y-1),0)	

				elif( line[x] =='G'):
					board[x][(y-1)]	= Gorilla(x,(y-1),1)
				elif( line[x] =='g'):
					board[x][(y-1)]	= Gorilla(x,(y-1),0)	

				elif( line[x] =='E'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),1)
				elif( line[x] =='e'):
					board[x][(y-1)]	= GrandEmpress(x,(y-1),0)		

				elif( line[x] =='W'):
					board[x][(y-1)]	= JetPack(x,(y-1),1)
				elif( line[x] =='w'):
					board[x][(y-1)]	= JetPack(x,(y-1),0)	

				elif( line[x] =='T'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),1)
				elif( line[x] =='t'):
					board[x][(y-1)]	= Transporterpad(x,(y-1),0)	

				elif( line[x] =='H'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),1)
				elif( line[x] =='h'):
					board[x][(y-1)]	= TimeMachine(x,(y-1),0)										

				elif( line[x] =='X'):
					board[x][(y-1)]	= GolfCart(x,(y-1),1)
				elif( line[x] =='x'):
					board[x][(y-1)]	= GolfCart(x,(y-1),0)	
		#Let Each Piece determine the Next Board State based on the Piece's Logic

		calcBoard_Num=0;
		#Iterate through the Entire Board calculating the Next Turn for Each Piece
		for x in range (0, 8):
			for y in range (0,8):
			#Calculate the next BoardState while return
				if(board[x][y]!=None):
					calcBoard_Num+= board[x][y].Calc_PotentialMoves(board,currentPlayer,calcBoard_Num)


				#Can be modified by passing in a Node class, and when _printboard is called.
				# A child node is instead created


if __name__ == "__main__":
	#WildaBeastSolver("BoardSetups/A3_TestBoards/GrandEmpress2/Board.txt")
	#WildaBeastSolver("BoardSetups/BoardSetup11.txt")

	#print 'Number of arguments:', len(sys.argv), 'arguments.'
	#print 'Argument List:', str(sys.argv)
	WildaBeastSolver(sys.argv[1])
	print("Boards have been Created.")
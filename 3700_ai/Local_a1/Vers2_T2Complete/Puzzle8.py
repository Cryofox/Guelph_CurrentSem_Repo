from SearchProblem import *;
from random import randint
import datetime
import time
import random
def remove_letter( input_string):
	return ""+input_string[:len(input_string)-1]

def replace_letter( input_string, letter ):
  return input_string.replace( letter, "" );


def ReplaceChar( indexofChar, replaceWith, theString):
	convertedString=""
	for i in range(0, len(theString)):
		if(i==indexofChar):
			convertedString= convertedString+replaceWith
		else:
			convertedString= convertedString+theString[i]

	return convertedString


class Puzzle8( SearchProblem ):
# The states needed, the current state (0->9), the current state string representation, the amount of X's left, and the previous action for
# redundant loop checking
	def __init__( self, state= ( 0, "_12345678", "XXXXXXXXX", "_" ), root=False ):
		self.state = state;
		#self.om_nom_nom();
		self.path = "";


		if root:
			self.visited = set( [ repr(self.state) ] );


	def edges( self ):
		my_edges = [];

		index=self.state[0]

		#Ensure index is mod 9, for proper setup
		if(self.state[0]==9	):
			index=0


		#Execute only if rightside has remaining X's
		if( len(self.state[2])>0):	

			#Use this to prevent infinite recursion while still creating edge nodes as needed
			statesCovered = remove_letter( self.state[2]);
			


			#If the previous state was not one that came from the opposite direction
			if(not (self.state[3]=='>')):
				#If not the LeftMost Tiles
				if(index!=0 and index!=3 and index!=6):
					#Perform Left Slide Move
					snapShotState=self.state[1]		

					slide_Char= snapShotState[index-1]

					snapShotState=ReplaceChar(index,slide_Char, snapShotState)
					snapShotState=ReplaceChar(index-1,'_', snapShotState)		

					#print("2ConvStr="+ snapShotState)					
					label = "<"
					#print(str(index)+"< "+snapShotState)
					my_edges.append( Edge( self, label, Puzzle8( ( index-1, snapShotState, statesCovered,label ) ) ) )
			#If the previous state was not one that came from the opposite direction
			if(not (self.state[3]=='<')):
				#If not the RightMost Tiles
				if(index!=2 and index!=5 and index!=8):
					#Perform Right Slide Move
					snapShotState=self.state[1]				
					slide_Char= snapShotState[index+1]

					snapShotState=ReplaceChar(index,slide_Char, snapShotState)
					snapShotState=ReplaceChar(index+1,'_', snapShotState)		
					
					label = ">"
					#print(str(index)+"> "+snapShotState)
					my_edges.append( Edge( self, label, Puzzle8( (index+1, snapShotState,statesCovered,label ))))

			#If the previous state was not one that came from the opposite direction
			if(not (self.state[3]=='v')):
				#If not the BottomMost Tiles
				if(index<=5):
					#Perform Upward Slide Move
					snapShotState=self.state[1]				
					slide_Char= snapShotState[index+3]

					snapShotState=ReplaceChar(index+3,'_', snapShotState)
					snapShotState=ReplaceChar(index,slide_Char, snapShotState)		
					
					label = "^"
					#print(str(index)+"^ "+snapShotState)
					my_edges.append( Edge( self, label, Puzzle8( (index+3, snapShotState,statesCovered,label ))))

			#If the previous state was not one that came from the opposite direction
			if(not (self.state[3]=='^')):
				#If not the TopMost Tiles
				if(index>=3):
					#Perform Downward Slide Move
					snapShotState=self.state[1]				
					slide_Char= snapShotState[index-3]

					snapShotState=ReplaceChar(index-3,'_', snapShotState)
					snapShotState=ReplaceChar(index,slide_Char, snapShotState)		
					
					label = "v"
					#print(str(index)+"v "+snapShotState)
					my_edges.append( Edge( self, label, Puzzle8( (index-3, snapShotState,statesCovered,label ))))

		return my_edges;

				
	def is_target( self ):
		return self.state[1] == "12345678_";

	def continue_search( self ):
		"""
		This method should return True if the search algorithm is to continue
		to search for more solutions after it has found one, or False if it
		should not.
		"""
		return False;
















#This creates a state tuple to be fed to Puzzle8
def RandomTuple():
	#Choose a value between -1, and 9

	randString=RandomString()

	index = randString.index('_')

	randTuple =(index,randString,"X"*30, "_")  # This is why its slow, the construction takes into account creating a 30 Depth Graph. Changing to 25 reduces this but will
											   # introduce the possibility of incorrectly stating some puzzles as unsolvable
	return randTuple


#This creates a random string to use for 8Puzzle
def RandomString():
	pool='12345678_'
	randString=""

	

	while(len(pool)>0):
		index= random.randint(0, len(pool)-1)
		randString= randString+ pool[index]
		pool= replace_letter(pool, pool[index])


	return randString


#This Function Prints the Timestamp along with a message provided
def PrintTimeStamp(message):
		ts = time.time()
		st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')		
		print (message + st)	




if __name__ == "__main__":
	#Assign a Depth of 40


	#Puzzle8( state=(4,"1234_5678","X"*30, "_"),root=True ).dfs();

	#12345678_ = solution
	#States = 0->8
	print("")
	PrintTimeStamp("Time Stamp PROGRAM Start: ")
	print("")
	random.seed(42)
	for i in range(1,51):
		currentTuple=RandomTuple()


		#This needs to be called so that future Runs of DFS do not also end pre-emptively
		SearchProblem.stop=False
		SearchProblem.stateVisited=0		

		print("Puzzle #"+str(i)+":"+ currentTuple[1])
		print("-----------------------------")
		PrintTimeStamp("Puzzle Start: ")
		pz=Puzzle8(currentTuple,root=True)
		pz.dfs();
		print("States Visited="+ str(SearchProblem.stateVisited))
		PrintTimeStamp("Puzzle End: ")
		print("=============================")


	PrintTimeStamp("Time Stamp PROGRAM End: ")		


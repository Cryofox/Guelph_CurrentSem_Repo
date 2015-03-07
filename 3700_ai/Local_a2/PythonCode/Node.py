
#Class RushHour and other Puzzles Should Inherit from
class Node:
	myState=None
	isValid=False
	solutionSteps=[]

	#so its not calculated every node
	h2_possibleAnswer=""

	def __init__(self,state=None, solutionPath=None,resetH2=False):
		return

	#This function just checks whether or not a State configuration is Valid.
	#True if yes, False if illegal
	def IsValidSetup(self):
		return False

	#Returns true if this is the Goal/Answer State
	def IsAnswer(self):
		return False

	#This function should return a list of "Nodes" which
	#are neighbouring/adjacent to the current State
	def GetNeighbours(self):
		return 


	#Create a Random Puzzle if applicable, to Allow for more varied results
	def CreateRandomPuzzle():
		return

	#Calculates the heuristic score of this state in
	#regards to the Goal state
	#Higher H = higher probability of being a BAD state
	#Lower H = higher prob of being a Good state. Good/Bad in reference to closeness to solution
	def Calc_HeuristicScore_1(self):	
		return 1
	def Calc_HeuristicScore_2(self):	
		return 1
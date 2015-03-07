'''
Cheat Sheet:

Vehicles:
x- Red Car (The Goal Car)
A-K Different Colored Cars 	 - 2Spaces
O-R Different Colored Trucks - 3Spaces

Coordinates:
 0,0	 - TL corner
 5,5 	 - BR corner
 0,5 	 - BL corner
 5,0 	 - TR corner

Orientation:
 H - Horizontal
 V - vertical


 Vehicles are ALWAYS orientated on their Top Leftmost corner.
 Meaning: if V cars always point down, if H cars always point Right



------------------------------------------------------
State: The State of the board is a series of car/truck locations seperated by a '-'
	if a State is ever invalid, it does not get created.

'''
from Node import *;
from bruteforce import *;
from bestfirst import *;
import time
import datetime
class RushHour (Node):





	#State = The current Puzzle setup in X02H-B22V style
	#solutionPath= The current List of Steps taken to reach a solution
	#resetH2 = Whether or not h2_possibleAnswer needs to be configured, unless Heuristic 2 is used it wont be.
	def __init__(self,state=None, solutionPath=None,resetH2=False):
		self.myState=state
		if(solutionPath==None):
			self.solutionSteps=[]
		else:
			self.solutionSteps=solutionPath;

		if(state!=None):
			isValid=self.IsValidSetup()

		# This is only called the initial time due to spawned Neighbours not setting this flag
		if(resetH2 == True):
			#optimization so Heuristic2's dependenant answer only needs to be computed once
			
			#Create the initial board
			occupiedBoard= [ [ False for i in range(6) ] for j in range(6) ]
			#set the start position of the red car
			occupiedBoard[4][2]=True
			occupiedBoard[5][2]=True
			placedCars=[]
			placedCars.append("X42H-")

			#Set Recursive LoopBreaker to False
			self.answerFoundBreak=False
			self.Calc_PotentialAnswer(occupiedBoard,placedCars);
			#results= self.Calc_PotentialAnswer(occupiedBoard,placedCars);
			#RushHour.h2_possibleAnswer=results
			print("H2 Target Answer="+ str(Node.h2_possibleAnswer))
			#print("--------------------------------------------")
		return 




	#This function just checks whether or not a State configuration is Valid.
	#True if yes, False if illegal
	def IsValidSetup(self, setupState=None):
		if(setupState==None):
			setupState=self.myState

		if(self.myState==None):
			print("No State")
			return False
		#Quick Check, Check if X exists in the state
		vehicles =setupState.split('-')



		#Puzzles with Multiple Cars are not possible

		#Create a Letter List
		list_AlphaLetters =[]
		for i in range(0, len(setupState)):
			if(setupState[i][0].isalpha()):
				if((setupState[i] in list_AlphaLetters) and (not setupState[i] == 'V') and (not setupState[i] == 'H')):
					print("Duplicate Entry:"+setupState[i])
					return False # Duplicate Entry
				else:
					list_AlphaLetters.append(setupState[i])



		#Clear List
		del(list_AlphaLetters)


		#Check if Red Car exists and if it is in 3rd row from Top (ie vehicle[i][2]==2)
		#Out of Bounds are checked for all cars after, so only need to check corner Y location here
		invalidStartLocation= True
		#print("V="+str(vehicles))
		for i in range(0, len(vehicles)):
			if( vehicles[i][0]=='X'):
				if(vehicles[i][2]=='2' and vehicles[i][3]=='H'):
					invalidStartLocation =False
		if(invalidStartLocation):
			print("Invalid Start Location and/or Orientation")
			return False

		#Create an empty Board to Test for Overlap 
		occupiedBoard= [ [ False for i in range(6) ] for j in range(6) ]	



		#For Every vehicle check if it's positioning is valid
		for i in range(0,len(vehicles)):



			#For Every Car check if it's coordinates are on the board		
			if((( int(vehicles[i][1])>=0 and int(vehicles[i][1]) < 6) and ( int(vehicles[i][2])>=0 and int(vehicles[i][2]) < 6))):
				if(occupiedBoard [ int(vehicles[i][1]) ] [ int(vehicles[i][2]) ] ==False ):
					#If H
					if(vehicles[i][3]=='H'):


						#Check Overlaps for Cars
						if((vehicles[i][0] >='A' and vehicles[i][0] <='K') or (vehicles[i][0]=='X')):

							#Check if the vehicles next position exits board before checking index
							if((int(vehicles[i][1])) + 1 <6) and ( occupiedBoard [ (int(vehicles[i][1])) + 1]  [ int(vehicles[i][2]) ] == False):

								occupiedBoard [  int(vehicles[i][1])	 ]  [ int(vehicles[i][2]) ]=True
								occupiedBoard [ (int(vehicles[i][1])) + 1]  [ int(vehicles[i][2]) ]=True
							else:
								#print("OverLapping Vehicles H")
								return False
						#Check Overlaps for Trucks
						elif(vehicles[i][0] >='O' and vehicles[i][0] <='R'):

							#Check if the vehicles next position exits board before checking index
							if(((int(vehicles[i][1])) + 2 <6) and 
							(occupiedBoard [ (int(vehicles[i][1])) + 1]  [ int(vehicles[i][2]) ] == False) and
							(occupiedBoard [ (int(vehicles[i][1])) + 2]  [ int(vehicles[i][2]) ] == False)):

								occupiedBoard [  int(vehicles[i][1])	 ]  [ int(vehicles[i][2])]=True
								occupiedBoard [ (int(vehicles[i][1])) + 1]  [ int(vehicles[i][2]) ]=True
								occupiedBoard [ (int(vehicles[i][1])) + 2]  [ int(vehicles[i][2]) ]=True
							else:
								#print("OverLapping Vehicles H")
								return False
						#No other Vehicles exist, parse error bad Alpha value given
						else:
							print("Non-Car/Truck Letter given")
							return False

					#If V
					elif(vehicles[i][3]=='V'):


						#Check Overlaps for Cars
						if((vehicles[i][0] >='A' and vehicles[i][0] <='K') or (vehicles[i][0]=='X')):

							#Check if the vehicles next position exits board before checking index
							if((int(vehicles[i][2])) + 1 <6) and ( occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) + 1] == False):
								occupiedBoard [  int(vehicles[i][1])	 ]  [ int(vehicles[i][2])]=True
								occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) + 1]=True
							else:
								#print("OverLapping Vehicles")
								return False
						#Check Overlaps for Trucks
						elif(vehicles[i][0] >='O' and vehicles[i][0] <='R'):

							#Check if the vehicles next position exits board before checking index
							if(((int(vehicles[i][2])) + 2 <6) and 
							(occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) +1] == False) and
							(occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) +2] == False)):

								occupiedBoard [  int(vehicles[i][1])	 ]  [ int(vehicles[i][2])]=True
								occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) +1]=True
								occupiedBoard [ (int(vehicles[i][1])) ]  [ int(vehicles[i][2]) +2]=True
							else:
								#print("OverLapping Vehicles V")
								return False
						#No other Vehicles exist, parse error bad Alpha value given
						else:
							#print("Non-Car/Truck Letter given")
							return False

					else:
						#print("Non-HV direction given.")
						return False					

				else:
					#print("OverLapping Vehicles")
					return False

			else:
				#print("Vehicle placed out of Bounds")
				return False





		self.isValid=True
		return True


	#Returns true if this is the Goal/Answer State
	def IsAnswer(self, testState=None):
		if(testState==None):
			testState=self.myState

		#Do a Double Check to see if the state is valid
		#print("State="+ testState)
		#if(self.IsValidSetup(testState)):
			#check if the X car is in position 42H, as thats the solution state.
			#Grab List of Cars
		vehicles = testState.split('-')
		for i in range (0, len(vehicles)):
			if (vehicles[i][0]=='X' and vehicles[i][1]=='4'  and vehicles[i][2]=='2' and vehicles[i][3]=='H'):
				return True


		return False

	#Returns a list of nodes representing this node's neighbours
	def GetNeighbours(self):
		#Construct a List of Possible moves for Each Car, and if it's move is valid store it

		#Grab List of Cars
		vehicles = self.myState.split('-')

		list_myNeighbours =[]
		#Check if its H or V
		for i in range (0, len(vehicles)):
			if(vehicles[i][3]=='H'):
				#Cycle through all HORIZONTAL positions. IE +- 1,2,3,  all the way to 6
				curX = int( vehicles[i][1])
				j=1
				if((curX+j)<6):
					#Create new neighbour State 
					currentCar=vehicles[i][0]+ str((curX+j)) +vehicles[i][2]+vehicles[i][3]

					newState=""
					#Cycle through all cars to reconstruct State
					for q in range (0, len(vehicles)):
						if(q!=i):
							newState+= vehicles[q] + "-"
						else:
							newState+=currentCar+ "-"

					#Trim off Excess - char
					newState = newState[:-1]

					#Creates a duplicate of the list
					solSteps= list(self.solutionSteps)
					solSteps.append( (currentCar[0]+"R"))

					#Create new Puzzle with this state, and if it's valid add it to the list
					newPuzzle_Node = RushHour(newState,solSteps)
					if(newPuzzle_Node.isValid==True):
						list_myNeighbours.append(newPuzzle_Node)

				if((curX-j)>-1):
					#Create new neighbour State 
					currentCar=vehicles[i][0]+ str((curX-j)) +vehicles[i][2]+vehicles[i][3]

					newState=""
					for q in range (0, len(vehicles)):
						if(q!=i):
							newState+= vehicles[q] + "-"
						else:
							newState+=currentCar+ "-"

					#Trim off Excess - char
					newState = newState[:-1]

					#Creates a duplicate of the list
					solSteps= list(self.solutionSteps)
					solSteps.append( (currentCar[0]+"L"))
					
					#Create new Puzzle with this state, and if it's valid add it to the list
					newPuzzle_Node = RushHour(newState,solSteps)
					if(newPuzzle_Node.isValid==True):
						list_myNeighbours.append(newPuzzle_Node)

			elif(vehicles[i][3]=='V'):
				#Cycle through all VERTICAL positions. IE +- 1,2,3,  all the way to 6
				curY = int( vehicles[i][2])

				j=1
				if((curY+j)<6):
					#Create new neighbour State 
					currentCar=vehicles[i][0]+ vehicles[i][1] + str((curY+j)) +vehicles[i][3]

					newState=""
					for q in range (0, len(vehicles)):
						if(q!=i):
							newState+= vehicles[q] + "-"
						else:
							newState+=currentCar+ "-"

					#Trim off Excess - char
					newState = newState[:-1]

					#Creates a duplicate of the list
					solSteps= list(self.solutionSteps)
					solSteps.append( (currentCar[0]+"D"))
					
					#Create new Puzzle with this state, and if it's valid add it to the list
					newPuzzle_Node = RushHour(newState,solSteps)
					if(newPuzzle_Node.isValid==True):
						list_myNeighbours.append(newPuzzle_Node)

				if((curY-j)>-1):
					#Create new neighbour State 
					currentCar=vehicles[i][0]+ vehicles[i][1] + str((curY-j)) +vehicles[i][3]

					newState=""
					for q in range (0, len(vehicles)):
						if(q!=i):
							newState+= vehicles[q] + "-"
						else:
							newState+=currentCar+ "-"

					#Trim off Excess - char
					newState = newState[:-1]

					#Creates a duplicate of the list
					solSteps= list(self.solutionSteps)
					solSteps.append( (currentCar[0]+"U"))
					
					#Create new Puzzle with this state, and if it's valid add it to the list
					newPuzzle_Node = RushHour(newState,solSteps)
					if(newPuzzle_Node.isValid==True):
						list_myNeighbours.append(newPuzzle_Node)

		#Return our list of Neighbouring States

		return list_myNeighbours
		#in the Neighbours List
		
	
	#Calculates the heuristic score of this state in
	#regards to the Goal state

	#This heuristic does a Manhattan distance of only the Red car. The reason is
	#given any puzzle its difficult to determine what the solution state will look like,
	#all thats given is the red cars position, the remaining cars
	def Calc_HeuristicScore_1(self):	
		#Grab List of Cars
		vehicles = self.myState.split('-')

		#Find the Red Car		
		for i in range (0, len(vehicles)):
			if(vehicles[i][0]=='X'):
				#Calculate the Distance of This car to the Goal State
				redXposition= int (vehicles[i][1])
				h = (4- redXposition)  
				return h



	# This one is more Complex as it requires deriving a POSSIBLE solution state
	# It works as this, assuming cars CAN move over one another, does a configuration exist
	# where all cars can be positioned on the board without violating their Directions
	# Calc the heuristic by determining the distance each car is from its current position to the goals version
	# position. If a goal configuration does not exist (Such as by filling the grid with cars) then a value of 
	# 0 is returned. This is due to the heuristic evaluation that there are no moves to bring you to the solution state
	# as such if it can not determine an answer the algorithm deteriorates to a BFS search while still not overshooting the 
	# solution
	def Calc_HeuristicScore_2(self):	
		#Calculate a potential Configuration


		if(Node.h2_possibleAnswer==None):
			#print("None was Returnd :(")
			return 0
		else:
			#Grab the Cars from this answer
			answerCars=RushHour.h2_possibleAnswer.split('-')

			#Grab our Cars 
			currentCars=self.myState.split('-')

			hValue=0
			#print("AnswerCars="+ str(answerCars))
			for i in range (0,len(answerCars)):
				#Calculate based on MATCHING cars
				#print("Carx="+ answerCars[i]+"H="+str(hValue))
				for j in range(0,len(currentCars)):
					#print("J Index="+ str(j))
					#print("CC="+ str(currentCars))
					#print("I index="+ str(i))
					#print("AC="+ str(answerCars))

					if( currentCars[j][0]== answerCars[i][0]):
						#Calculate the Distance based on offset
						#print("ACars="+str(answerCars))
						if (answerCars[i][3]=='V'):
							hValue+= abs(int(answerCars[i][2]) - int(currentCars[j][2]))
						elif (answerCars[i][3]=='H'):
							hValue+= abs(int(answerCars[i][1]) - int(currentCars[j][1]))

						break


			#To avoid the pitfall of ignoring an answer to reach the "possible configuration"
			#First check if the current state is the answer, if it is return 0.
			if( self.IsAnswer()):
				hValue=0

			#print( "State="+ self.myState +" HValue="+ str(hValue))
			return hValue



	#This function calculates a possible configuration based on the cars currently given
	#it must be fed a grid, with the list of cars who have been placed on it

	# Utilizing this with a red car placed on the answer state a possible solution is calculated

	answerFoundBreak=False


	#This is used as a helper function for the presetup stage if heuristic 2 was intended to be used.
	def Calc_PotentialAnswer(self, grid,placedCars):
		ansState=""
		for q in range (0, len(placedCars)):
			ansState+= placedCars[q]

		ansState= ansState[:-1]
		print("AS="+ansState)
		#All cars are placed if string sizes match
		if( len(ansState) == len(self.myState)) :
			self.answerFoundBreak=True;
			Node.h2_possibleAnswer= ansState
			#print("Answer State= "+ ansState)
			return ansState

		#else:
			#print("AState="+ ansState)
			#print("CState="+ self.myState)



		cars=self.myState.split('-')
		#Given the Redcar starts in the center find a possible configuration
		#such that nothing overlaps

		#isInvalid



		for i in range (0, len(cars)):
			#For Each vehicle not already placed
			isPlaced=False
			for p in range (0, len(placedCars)):
				if(cars[i][0] == placedCars[p][0]):
					isPlaced=True
					break


			if( not(isPlaced)):
				#print("Placing:"+cars[i])
				#Check if it's an H or a V
				for j in range(0,5):
					if( cars[i][3]=='H'):
						newGrid = list(grid)
						newGrid[ j ][ int(cars[i][2]) ] = True
						newGrid[ j + 1 ][ int(cars[i][2]) ] = True	

						#if Truck	
						if((cars[i][0]>='O' and cars[i][0]<='K') and j<=3):
							newGrid[ j + 2 ][ int(cars[i][2]) ] = True									

						newPlacedCars= list(placedCars)
						newPlacedCars.append( (cars[i][0]+str(j)+cars[i][2])+"H-" )
						#Create State
						curState=""
						for q in range (0, len(newPlacedCars)):
							curState+= newPlacedCars[q]

						if(self.IsValidSetup(curState[:-1])):
							self.Calc_PotentialAnswer(newGrid,newPlacedCars);

					elif( cars[i][3]=='V'):
						newGrid = list(grid)
						newGrid[ int(cars[i][1]) ][ j ] = True
						newGrid[ int(cars[i][1]) ][ j + 1 ] = True	
						
						#if Truck	
						if((cars[i][0]>='O' and cars[i][0]<='K') and j<=3):
							newGrid[ int(cars[i][1]) ][ j + 2 ] = True									

						newPlacedCars= list(placedCars)
						newPlacedCars.append( (cars[i][0]+cars[i][1])+str(j)+"V-" )
						#Create State
						curState=""
						for q in range (0, len(newPlacedCars)):
							curState+= newPlacedCars[q]

						#print("IVS="+ curState[:-1])
						if(self.IsValidSetup(curState[:-1])):
							self.Calc_PotentialAnswer(newGrid,newPlacedCars);						

					if( self.answerFoundBreak==True):
						return
		#If this is Reached, than no answer was found return ""
		return None







#This Function Prints the Timestamp along with a message provided
def PrintTimeStamp(message):
		ts = time.time()
		st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')		
		print (message + st)

# Performs all three search operations on a given puzzle, and outputs the results to the logfile
# named based on the logname paramaeter, the results are a series of instructions on how to complete the puzzle
def PerformSearchFunctions(puzzle, logname):

	#Search BFS
	bfs =BruteForce_Search()
	PrintTimeStamp("\nSearch (BruteForce) Start:")
	print("---------------------------------------")
	bfs.Search(rh_Puzzle, logname+"_BruteForce",False)
	PrintTimeStamp("Search (BruteForce) End:")
	print("=======================================")

	#Search BestFS Heuristic 1
	bfs =BestFirst_Search()

	PrintTimeStamp("\nSearch (BestFirst Heuristic 1) Start:")
	print("---------------------------------------")
	bfs.Search(rh_Puzzle, logname+"_BestFirst_H1",False)
	PrintTimeStamp("Search (BestFirst Heuristic 1) End:")
	print("=======================================")


	#Search BestFS Heuristic 2
	bfs =BestFirst_Search()
	PrintTimeStamp("\nSearch (BestFirst Heuristic 2) Start:")
	print("---------------------------------------")
	bfs.Search(rh_Puzzle, logname+"_BestFirst_H2",False,2)
	PrintTimeStamp("Search (BestFirst Heuristic 1) End:")
	print("=======================================")


#RH is a puzzle which utilizes 6x6 Matrix

#Passing None into the State will cause it to randomly generate a puzzle
#Pass in True if Heuristic 2 is going to be used for Searching
#rh_Puzzle=RushHour("X12H-O50V-", None,True)

#Jam #40 - http://www.puzzles.com/products/rushhour/rhfrommarkriedel/Jam.html?40
#rh_Puzzle=RushHour("O00V-F10H-B40V-C11V-D21V-P51V-X32H-Q03H-E33V-K24V-G44H-H05H-I35H", None,True)



#Search BFS
'''
bfs =BruteForce_Search()
bfs.Search(rh_Puzzle,False)
'''

#Search BestFS Heuristic 1
'''
bfs =BestFirst_Search()
bfs.Search(rh_Puzzle,False)
'''
#Search BestFS Heuristic 2
'''
bfs =BestFirst_Search()
bfs.Search(rh_Puzzle,False,2)
'''






if __name__ == "__main__":
	
	#Easy 13
	print("Puzzle = Easy 13:")
	PrintTimeStamp("H2_Goal Setup Start:")
	print("")
	rh_Puzzle=RushHour("O20V-P30V-X02H-F14H-B34H-C54V-D15H-E35H", None,True)
	print("")
	PrintTimeStamp("H2_Goal Setup End:")

	PerformSearchFunctions(rh_Puzzle,"Easy_13")


	#Medium 13 

	print("Puzzle = Medium 13:")
	PrintTimeStamp("H2_Goal Setup Start:")
	print("")
	rh_Puzzle=RushHour("A20H-B40H-C51V-X22H-O42V-P03H-D53V-E24V-K05H-G45H", None,True)
	print("")
	PrintTimeStamp("H2_Goal Setup End:")

	PerformSearchFunctions(rh_Puzzle,"Medium_13")

	#Hard 13 

	print("Puzzle = Hard 13:")
	PrintTimeStamp("H2_Goal Setup Start:")
	print("")
	rh_Puzzle=RushHour("O00H-F50V-P21V-B31H-X02H-C52V-Q33V-D43V-E04V-K14H-G15H-H45H", None,True)
	print("")
	PrintTimeStamp("H2_Goal Setup End:")

	PerformSearchFunctions(rh_Puzzle,"Hard_13")

	
	#Expert 21 

	print("Puzzle = Expert 21:")
	PrintTimeStamp("H2_Goal Setup Start:")
	print("")
	rh_Puzzle=RushHour("A00V-B10H-C30H-D50V-O21V-X02H-E52V-K33H-G04V-H34V-I44H-J15H", None,True)
	print("")
	PrintTimeStamp("H2_Goal Setup End:")
	PerformSearchFunctions(rh_Puzzle,"Expert_21")  
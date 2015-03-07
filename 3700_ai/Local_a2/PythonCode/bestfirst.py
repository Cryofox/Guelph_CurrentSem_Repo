

'''
How it works.
Create a list of Unique States
This list only acts to prevent Loops
If a state is to be added to our next Search List, check if it
exists in the Unique States list, if so don't add.
This adds a way for the Program to end, and at the same time calculate search space.


Req: Each Node must have a CalculateNeighbours Function. 
 	 This is so the Search program can calculate edges as needed as opposed to pre-calculate

 	 Each Node must also have a GetCurrentState to be referenced as needed
 	 Each Node must also have a Set/Get Parent which sets/gets another Node as the Parent


^ The above is the exact same for BruteForce. The difference between the two is
best first will scan the list of current nodes before choosing, where bruteforce just takes the first 
node everytime.
'''
from Node import *;
class BestFirst_Search:




	def __init__( self):
		#Just for Python to be happy
		return



	#Given a Start Node, and a boolean to determine whether search should continue after finding an answer
	#Pass in a heuristic value of 2 if heuristic 2 is wished to be calculated.
	#Due to scalability, the heuristic scores are all derived on the puzzle itself, as the search program only requires
	#a heuristic index to compare thus by lettting each puzzle calculate the heuristics this search can be extended easily
	#Pass none for logfileName if you do not want to output the solution instructions on a logfile.
	def Search(self,node=None, logFileName=None, haltOnAnswer=False, heuristicChosen=1):
		if(node==None):
			return


		print("Bestfirst Search Started.")

		#add the current Node to the list of nodestovisit
		list_UniqueNodesVisited=[];
		list_CurrentNodesToVisit=[];

		list_CurrentNodesToVisit.append(node);


		#Loop while our list has values
		while( len(list_CurrentNodesToVisit)>0):
			
			index=0
			#Heuristic 1
			if(heuristicChosen==1):
				index=self.GetBestIndex_Heuristic1(list_CurrentNodesToVisit)
			#Heuristic 2
			elif(heuristicChosen==2):
				index=self.GetBestIndex_Heuristic2(list_CurrentNodesToVisit)

			#Choose the Node with the best heuristic
			currentNode = list_CurrentNodesToVisit[index]

			#print current State
			#print ("CUR_SP="+str(currentNode.myState)  +str(currentNode.solutionSteps))

			#Pop the element we are using as an index
			list_CurrentNodesToVisit.pop(index)




			#Check if our state is the answer
			if((currentNode.IsAnswer()) and (haltOnAnswer==False)):
				print ("Solution Found! Printing Path:")
				print (str(currentNode.solutionSteps))
				print ("States Visited="+ str(len(list_UniqueNodesVisited)))

				#Output to Logfile
				if(not logFileName==None):
					self.OutputAnswer(logFileName,currentNode.solutionSteps)

				return





			#Check if the Current node exists in the list of already visited nodes, this is to reduce search space, and prevent loops
			alreadyVisited=False
			for i in range(0, len(list_UniqueNodesVisited)):
				if(list_UniqueNodesVisited[i].myState == currentNode.myState):
					alreadyVisited=True
					break;
			#If we have not already visited our current Node perform the Calculations
			#Otherwise just Loop
			if(not alreadyVisited):
				#print("Not Visited Adding Neighbours")
				list_UniqueNodesVisited.append(currentNode)

				#Get currentNodes Neighbours and add to our current Nodes to Visit
				list_CurrentNodesToVisit += currentNode.GetNeighbours()


		print ("States Visited="+ str(len(list_UniqueNodesVisited)))




	# In order to make this More Generalizable. 
	#Place the Calling Code inside the Puzzle itself, that way it can be expanded to any puzzle inheriting from Node
	def GetBestIndex_Heuristic1(self,list1):
		index=0
		#Set H to an unrealistically high value
		lowestH=9* 1000000000
		for i in range(0, len(list1)):
			if(list1[i].Calc_HeuristicScore_1() < lowestH):
				lowestH=list1[i].Calc_HeuristicScore_1()
				index=i

		return index


	# In order to make this More Generalizable. 
	#Place the Calling Code inside the Puzzle itself, that way it can be expanded to any puzzle inheriting from Node
	def GetBestIndex_Heuristic2(self,list1):
		index=0
		#Set H to an unrealistically high value
		lowestH=9* 1000000000
		for i in range(0, len(list1)):
			if(list1[i].Calc_HeuristicScore_2() < lowestH):

				lowestH=list1[i].Calc_HeuristicScore_2()
				index=i

		return index

	#Prints the solution into a .txt file if a logname was provided to do so
	def OutputAnswer(self, logName, solutionSteps):
		text_file = open(  logName+".txt", "w")
		for i in range(0, len(solutionSteps)):
			text_file.write( solutionSteps[i] +"\n")
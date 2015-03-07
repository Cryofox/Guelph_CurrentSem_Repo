

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
'''
from Node import *;
class BruteForce_Search:


	statesVisited=0
	answersFound=0
	shortestDepth=0
	def __init__( self):
		#Just for Python to be happy
		return



	#Given a Start Node, and a boolean to determine whether search should continue after finding an answer
	#Pass none for logfileName if you do not want to output the solution instructions on a logfile.
	def Search(self,node=None, logFileName=None, haltOnAnswer=False):
		if(node==None):
			return


		print("Bruteforce Search Started.")

		#add the current Node to the list of nodestovisit
		list_UniqueNodesVisited=[];
		list_CurrentNodesToVisit=[];

		list_CurrentNodesToVisit.append(node);


		#Loop while our list has values
		while( len(list_CurrentNodesToVisit)>0):
			currentNode = list_CurrentNodesToVisit[0]
			#print ("CUR_SP="+str(currentNode.myState)  +str(currentNode.solutionSteps))

			#Pop the first element in the list
			list_CurrentNodesToVisit.pop(0)




			#Check if our state is the answer
			if(currentNode.IsAnswer()):

				if(self.answersFound==0):
					self.shortestDepth = len(currentNode.solutionSteps)
				if(not alreadyVisited):
					self.answersFound+=1;

				


				print ("Solution Found! Printing Path:")

				#Uncomment this line V if you want to see all solution states + directions seperately on console
				print (str(currentNode.solutionSteps))
				print ("States Visited="+ str(len(list_UniqueNodesVisited)))
				if(haltOnAnswer==False):
					#Output to Logfile
					if(not logFileName==None):
						self.OutputAnswer(logFileName,currentNode.solutionSteps)

					return





			#Check if the Current node exists in the list, this is to reduce search space, and prevent loops
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
		self.statesVisited = len(list_UniqueNodesVisited)

	#Prints the solution into a .txt file if a logname was provided to do so
	def OutputAnswer(self, logName, solutionSteps):
		text_file = open(  logName+".txt", "w")
		for i in range(0, len(solutionSteps)):
			text_file.write( solutionSteps[i] +"\n")



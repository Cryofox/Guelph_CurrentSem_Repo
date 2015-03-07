class SearchProblem:
	"""
	This class represents the superclass for a search problem.

	Programmers should subclass this superclass filling in specific
	versions of the methods that are stubbed below.
	"""

	stop = False; # class variable to end search - single variable accessible to
	# all instances of the class
	stateVisited= 0
	nodesAtDepth= 0
	def __init__( self, state=None ):
		"""
		Stub
		Constructor function for a search problem.

		Each subclass should supply a constructor method that can operate with
		no arguments other than the implicit "self" argument to create the
		start state of a problem.

		It should also supply a constructor method that accepts a "state"
		argument containing a string that represents an arbitrary state in
		the given search problem.

		It should also initialize the "path" member variable to a string.
		"""

		raise NotImplementedError("__init__");

	def edges( self ):
		"""
		Stub
		This method must supply a list or iterator for the Edges leading out 
		of the current state.
		"""
		raise NotImplementedError("edges");

	def is_target( self ):
		"""
		Stub
		This method must return True if the current state is a goal state and
		False otherwise.
		"""

		raise NotImplementedError("is_target");

	def __repr__( self ):
		"""
		This method must return a string representation of the current state
		which can be "eval"ed to generate an instance of the current state.
		"""

		return self.__class__.__name__ + "( " + repr(self.state) + ")";

	def target_found( self ):
		"""
		This method is called when the target is found.

		By default it prints out the path that was followed to get to the 
		current state.
		"""
		print( "Solution: " + self.path );


	def continue_search( self ):
		"""
		This method should return True if the search algorithm is to continue
		to search for more solutions after it has found one, or False if it
		should not.
		"""
		return True;


	def bfs(self):
		SearchProblem.stateVisited=0


		#At depth 23 (o based index) 24 moves are made, offset by 1 for root node and this is
		#depth level 25. 1 + 24 moves = Depth 25.
		for increment in range(0,25):
			#print("Inc="+str(increment))
			SearchProblem.nodesAtDepth=0
			self.SearchtoDepth(increment)
			print ("Nodes at Depth["+str(increment+1)+"]:"+ str(SearchProblem.nodesAtDepth) )

	#This is a helper function for BFS and should not be called from outside
	'''
	def performBFS_atDepth( self, targetDepth ):
		
		#print self.state; 
		#print self.visited;

		#SearchProblem.stateVisited= SearchProblem.stateVisited+1 

		#This is needed to ensure we are only using nodes at this Depth level
		#and for this instance of the program
		del SearchProblem.nodesAtDepth [:]

		#Call SearchtoDepth to populate list with all nodes at this depth level
		self.SearchtoDepth(targetDepth)



		#Do a BFS search at the Target Depth

		#DEBUG - Print nodes at depth to ensure program is performing as intended
		print ("Nodes at Depth:"+ str(targetDepth) +" = " + str(len(SearchProblem.nodesAtDepth) ))


		#This is a simple check algorithm if any of the edges at this depth provide the answer
		currentNodeLength=len(SearchProblem.nodesAtDepth)

		#XRange is used due to Memory Error of attempting to populate the entire 
		#for loop List in memory when using range. Python Language issue

		for i in xrange (0,currentNodeLength):
			if SearchProblem.nodesAtDepth[i].destination.is_target(): 
				# check if destination of edge is target node
				SearchProblem.nodesAtDepth[i].destination.target_found();  # perform target found action
				if not self.continue_search():  # stop searching if not required
					SearchProblem.stop = True;    # set class variable to record that we
					break;                        # are done




		#For Each Node at this target Depth
		for action in self.edges(): # consider each edge leading out of this node
		action.destination.path = self.path + str(action.label);  
		action.destination.visited = self.visited.copy();
	'''
		#This performs a DFS styled search towards the target depth, once that depth is reached it utilizes
		#BFS to search all nodes at current depth
	def SearchtoDepth( self, targetDepth ):
		"""
		Since the spec does not say how to get to the target spec, I have chosen to reuse the DFS implementation
		with a minor edit to reach the targetDepth before utilizing the bfs algorithm
		"""
		if self.stop: # check class variable and stop searching...
			return;
		#print self.state; 
		#print self.visited;
		

		SearchProblem.stateVisited=SearchProblem.stateVisited+ 1
		#Do a BFS search at the Target Depth

		#For Each Node at this target Depth
		for action in self.edges(): # consider each edge leading out of this node
			action.destination.path = self.path + str(action.label);  
			# get the label associated with the
			# action and append it to the path
			# string

			action.destination.visited = self.visited.copy();
			# make copy of source node's visited set
			# and use it as destination node's
			# visited set

			action.destination.visited.add( repr(action.destination.state) );

			#This is the tweak, if the node is less than targetDepth, keep scanning
			#otherwise, add it to the class node's list
			if (len(action.destination.path)-1<targetDepth):	
				if repr(action.destination.state) in self.visited:
					continue;   # skip if we've visited this one before
				action.destination.SearchtoDepth(targetDepth);     # resume recursive search 



			#This is what causes the BFS once the target depth has been reached
			if(len(action.destination.path)-1==targetDepth):
				if not repr(action.destination.state) in self.visited:
					#SearchProblem.nodesAtDepth.append(action) #Add if we have not visited before
					SearchProblem.nodesAtDepth+=1
					#Instead of Adding to a List, instead check the Node itself
					if action.destination.is_target(): 
						# check if destination of edge is target node
						action.destination.target_found();  # perform target found action
						if not self.continue_search():  # stop searching if not required
							SearchProblem.stop = True;    # set class variable to record that we
							break;                        # are done

					#Should Test to see if ^ is the problem



	def dfs( self ):
		"""
		Perform a depth first search originating from the node, "self".
		Recursive method.
		"""

		#print self.state; 
		#print self.visited;
		SearchProblem.stateVisited= SearchProblem.stateVisited+1 

		if self.stop: # check class variable and stop searching...
			return;

		for action in self.edges(): # consider each edge leading out of this node

			action.destination.path = self.path + str(action.label);  
			# get the label associated with the
			# action and append it to the path
			# string

			action.destination.visited = self.visited.copy();
			# make copy of source node's visited set
			# and use it as destination node's
			# visited set

			action.destination.visited.add( repr(action.destination.state) );

			if action.destination.is_target(): 
				# check if destination of edge is target node
				action.destination.target_found();  # perform target found action
				if not self.continue_search():  # stop searching if not required
					SearchProblem.stop = True;    # set class variable to record that we
					break;                        # are done

			if repr(action.destination.state) in self.visited:
				continue;   # skip if we've visited this one before

			action.destination.dfs();     # resume recursive search 

class Edge:
	"""
	This class represents an edge between two nodes in a SearchProblem.
	Each edge has a "source" (which is a subclass of SearchProblem), a
	"destination" (also a subclass of SearchProblem) and a text "label".
	"""

	def __init__( self, source, label, destination ):
		"""
		Constructor function assigns member variables "source", "label" and
		"destination" as specified.
		"""
		self.source = source;
		self.label = label;
		self.destination = destination;

	def __repr__( self ):
		return "Edge(" + repr( self.source ) + "," + \
		repr( self.label ) + "," + \
		repr( self.destination ) + ")";

exitRecursion=False
class SearchProblem:
  """
  This class represents the superclass for a search problem.

  Programmers should subclass this superclass filling in specific
  versions of the methods that are stubbed below.
  """
  
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
    return False;

  def start_DFS(self):
    global exitRecursion
    exitRecursion=False
    self.dfs();

  def dfs( self ):
    """
    Perform a depth first search originating from the node, "self".
    Recursive method.
    """
    #print self.state; 
    #print self.visited;
    global exitRecursion
    
    for action in self.edges(): # consider each edge leading out of this node
      if(exitRecursion):
        print("Exiting Screen")
        return
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
        action.destination.target_found();	# perform target found action
        if not self.continue_search():	# stop searching if not required
          print ("Exiting Loop")
          exitRecursion=True
          #sys.exit(0)
          #return;
          break

      if repr(action.destination.state) in self.visited:
        continue;		# skip if we've visited this one before

      action.destination.dfs();			# resume recursive search 

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

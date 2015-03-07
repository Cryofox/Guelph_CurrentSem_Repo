from SearchProblem import *;

def remove_letter( input_string, letter ):
  return input_string.replace( letter, "" );


def add_letter( input_string, letter ):
  return "".join( sorted( input_string+letter ) );

class CGW( SearchProblem ):

  def __init__( self, state=( 1, "CGW", "" ), root=False ):
    self.state = state;
    self.om_nom_nom();
    self.path = "";
    self.inc=0;
    if root:
      self.visited = set( [ repr(self.state) ] );

  def om_nom_nom( self ):
    if self.state[0] == 1:	# if human is on left side
      right = self.state[2];

      if "G" in right:
        right = remove_letter( right, "C" );

      if "W" in right:
        right = remove_letter( right, "G" );

      self.state = ( self.state[0], self.state[1], right );

    elif self.state[0] == 2:	# if human is on right side

      left = self.state[1];

      if "G" in left:
        left = remove_letter( left, "C" );

      if "W" in left:
        left = remove_letter( left, "G" );

      self.state = ( self.state[0], left, self.state[2] );

    else:
      raise IndexError( "Side must be 1 or 2" );

  def edges( self ):
    my_edges = [];

    if self.state[0]==1:	# human on left-side
      new_human_location = 2;

      for animal in self.state[1]:
        new_left_side = remove_letter( self.state[1], animal );
        new_right_side = add_letter( self.state[2], animal );

        my_edges.append( Edge( self, animal, CGW( ( new_human_location, 
                                                    new_left_side, 
                                                    new_right_side ) ) ) );

    elif self.state[0]==2:	# human on right-side
      new_human_location = 1;

      for animal in self.state[2]:
        new_right_side = remove_letter( self.state[2], animal );
        new_left_side = add_letter( self.state[1], animal );

        my_edges.append( Edge( self, animal, CGW( ( new_human_location, 
                                                    new_left_side, 
                                                    new_right_side ) ) ) );

    else:
      raise IndexError( "Side must be 1 or 2" );

    # finally add one more edge for the human crossing the river alone
    my_edges.append( Edge( self, "-", CGW( ( new_human_location,
                                             self.state[1],
                                             self.state[2] ) ) ) );
    return my_edges;

	
  def continue_search( self ):
    """
    This method should return True if the search algorithm is to continue
    to search for more solutions after it has found one, or False if it
    should not.
    """
    print("This has been edited")
    return False;

  def is_target( self ):
    return self.state[0]==2 and self.state[2] == "CGW";

if __name__ == "__main__":
  CGW( state=(1,"CGW",""), root=True ).start_DFS();



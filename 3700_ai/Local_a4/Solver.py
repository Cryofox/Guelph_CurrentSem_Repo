#!/usr/bin/python
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

from WildaBeastSolver import *;

import sys;













if __name__ == "__main__":
	print("Hey Good job")
	#This program will work in stages to allow for optimizing areas.

	#Stage 1: Read the Input File


	#Stage 2: Alpha beta Prune
		#Stage 2.1: Calculate Depth 

		#Stage 2.2: For a board State Calculate Children Nodes

		#Stage 3.3: Search Space for Best Answer using Heuristics
			#MIN MAX dependent on heuristic values.


		#Stage 2.3: Find Answer



	#Stage 3: Print Result.






#Steps modify Wildabeast to parse NODES not textfiles

# modify RUN to parse from stdin and create a ROOT node
# nodes are passed into wildabeast solver for getting children.
# children are evaluated 1 by 1. If a child contains a worse answer than the parent already has
# exit the child and continue.


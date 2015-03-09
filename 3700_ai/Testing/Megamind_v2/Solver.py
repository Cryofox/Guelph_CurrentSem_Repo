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

import fileinput

import time









if __name__ == "__main__":
	#print("Hey Good job")
	#This program will work in stages to allow for optimizing areas.

	#Stage 1: Read the Input File


	#Stage 2: Alpha beta Prune
		#Stage 2.1: Calculate Depth 

		#Stage 2.2: For a board State Calculate Children Nodes

		#Stage 3.3: Search Space for Best Answer using Heuristics
			#MIN MAX dependent on heuristic values.


		#Stage 2.3: Find Answer


 	#Stage 3: Print Result.


	# Reads in lines from STDIN

	entryString="";

	i =0
	turn=0;
	for line in fileinput.input():
		entryString+=line;
		if(i==11):
			turn=(int)(line)
		i+=1

	start_Time = time.clock();
	#print(entryString)
	wd = WildaBeastSolver(entryString)

	#Add preset Moves to speed up initial turn decisions


	end_Time = time.clock();





	#print("TE:"+str( (end_Time-start_Time)))

	#Now to analyze the 3rd last and last values
	print(wd.chosen_NextMove+(str( (int)((end_Time-start_Time)*1000)))+"\n60000\n"+str((turn+1))+"\n")
	#print("Turn="+str(turn+1))




#Steps modify Wildabeast to parse NODES not textfiles

# modify RUN to parse from stdin and create a ROOT node
# nodes are passed into wildabeast solver for getting children.
# children are evaluated 1 by 1. If a child contains a worse answer than the parent already has
# exit the child and continue.


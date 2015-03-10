Megamind v1: Board_CM.txt (Takes rook)
	Speed: ~1002
	Depth:3

Megamind v2: Board_CM.txt (Is about to CM King)
	Speed: ~1300
	Depth:3

Megamind v3: Board_CM.txt (Is about to CM King)
	Speed: ~850
	Depth:4


MM8: Dumbed down the analytics to increase time accuracy. 
     Uses threading to. :3



MM9: 
Profiled, 
Removed repetitive function calls to GetPiece
Converted Kill Joey from two, to a single for loop iteration
Add Snake and Empress Flags in Joey to check against in PoisonUnits function
Nodes at Target Depth do not Get their children nodes created.

MM11:
Fixed:
	Gorilla now gets poisoned.
	Constructs (Excluding Catapult) No longer get poisoned.

Megamind must play like a human.
 Opening move is entirely random


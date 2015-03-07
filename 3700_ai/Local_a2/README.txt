Horia "Ryder" Stancescu
hstances - 0721385

Program Info:

All solutions to problems are labelled in puzzlename_(SearchAlgorithm)  format.


The Entry point to test the search algorithms is: RushHour.py
The Entry point to test difficulty of said search algorithms is: Difficulty Analyzer.py


Due to the spec the way Difficulty Analyzer is setup is to show (in the code) how the 4 different types of puzzles
are created and analyzed. You'll notice the setup is identical to that of RushHour.py.

Step 1: Create Puzzle 
First param is the board setup, Second is whether any steps have been calculated thus far, and the third
is a paramaeter used for calculating Heuristic 2, as the algorithm runs through all three search
procedures per setup toggle this to true. It is placed here in the event you wish to test out a specific
algorithm that does not require this field.

rh_Puzzle=RushHour("A20H-B40H-C51V-X22H-O42V-P03H-D53V-E24V-K05H-G45H", None,True)

Step 2: Choose the Search Algorithm

If running Rushhour.py this step is handled for you, in order to create custom/new rushhour puzzles
simply follow the existing setup code.

bfs =BruteForce_Search()

Step 3: Run the algorithm

Parameter 1 is the puzzle you created in step 1,
Parameter 2 is the logname if you wish the solution steps to be outputted line by line in a .txt file
simply state the file name and omit the .txt extension as that is handled for you.
Parameter 3 is whether or not the algorithm should continue after finding an answer.
bfs.Search( puzzle, logname, False)


Difficulty Analyzer
Step 1->3 are the same as Rushhour.py

Note this analyzer utilizes Bruteforce as it's tester, this .py algorithm has been modified with 2
global variables to be retrieved for calculation which is not present in bestfirst search. This algorithm was
chosen due to speed of traversing the entire search space as zero calculations are required per node.


Step 4: Calculate the Difficulty

print(CalculateDifficulty(bfs))


And that is it.


All puzzles are hardcoded as the spec did not mention reading puzzle setups from a file, and due
to implementing each puzzle manually being time consuming the 5 puzzles implemented were done so by hand,
other types of puzzle configurations also work, so feel free to add them in the format similar to the ones already
incorporated.



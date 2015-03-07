from Node import *;
from bruteforce import *;
import time
import datetime
from RushHour import *;







def CalculateDifficulty(bruteforcePostSearch):

	
	#print("Total Solutions:"+ str(bfs.answersFound))
	#print("Total States Visited:"+ str(bfs.statesVisited))
	#print("Shortest Depth:"+ str(bfs.shortestDepth))
	
	depthCalculation = (bruteforcePostSearch.shortestDepth/7)/2;
	randomCalc = ( (float)(bruteforcePostSearch.answersFound)/ (float)(bruteforcePostSearch.statesVisited))

	#print("PreRC="+str(randomCalc))
	if( randomCalc <= 0.19):
		randomCalc=3
	elif(randomCalc <= 0.3326):
		randomCalc=2
	else:
		randomCalc=1

	depthCalculation = (int)(depthCalculation)

	#print("DC="+ (str)(depthCalculation))
	#print("RC="+ (str)(randomCalc))
	difficulty =(float)  ((depthCalculation+ randomCalc)/2)


	#print("PreD="+str(difficulty))
	difficulty= round(difficulty,0)

	#print("D="+str(difficulty))
	if(difficulty==1):
		return "Puzzle difficulty is: Easy"
	elif(difficulty==2):
		return "Puzzle difficulty is: Moderate"		
	else:
		return "Puzzle difficulty is: Hard"	





if __name__ == "__main__":

	#Create the Rush hour puzzle to analyze


	#Easy 13
	print("Puzzle = Easy 13:")	
	rh_Puzzle=RushHour("O20V-P30V-X02H-F14H-B34H-C54V-D15H-E35H", None,False)
	bfs =BruteForce_Search()
	bfs.Search(rh_Puzzle, None,True) #True to scan entire search space
	print(CalculateDifficulty(bfs))
	print("")
	#Medium 13
	print("Puzzle = Medium 13:")	
	rh_Puzzle=RushHour("A20H-B40H-C51V-X22H-O42V-P03H-D53V-E24V-K05H-G45H", None,False)
	bfs =BruteForce_Search()
	bfs.Search(rh_Puzzle, None,True) #True to scan entire search space
	print(CalculateDifficulty(bfs))
	print("")
	#Hard 13
	print("Puzzle = Hard 13:")	
	rh_Puzzle=RushHour("O00H-F50V-P21V-B31H-X02H-C52V-Q33V-D43V-E04V-K14H-G15H-H45H", None,False)
	bfs =BruteForce_Search()
	bfs.Search(rh_Puzzle, None,True) #True to scan entire search space
	print(CalculateDifficulty(bfs))
	print("")

	#Expert 21
	print("Puzzle = Expert 21:")	
	rh_Puzzle=RushHour("A00V-B10H-C30H-D50V-O21V-X02H-E52V-K33H-G04V-H34V-I44H-J15H", None,False)
	bfs =BruteForce_Search()
	bfs.Search(rh_Puzzle, None,True) #True to scan entire search space
	print(CalculateDifficulty(bfs))




































#To Analyze a Puzzles Difficulty First Run it through a BestFirst search with Heuristic 1

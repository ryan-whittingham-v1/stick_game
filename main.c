#include<stdio.h>

///////////////////////////////////////////////////////////////////////////

/*
Ryan Whittingham
CSE 224
October 14, 2018
Programming Assignment 2


Stick Game in C.

Simple game of strategy using math. User and CPU take turns removing 1 to 3 sticks 
from the pile until there are no more sticks remaining. Whoever takes the last stick wins.

*/

////////////////////  Function Prototypes  //////////////////////////////

int start(int, char **);
int intCheck(char*);
int printSticks(int);
int userTurn(int, int *);
int cpuTurn(int, int *);

/////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv) {
	
	int stickCount;
	int whosTurn = 1; //tracks whos turn, 1 = player, 0 = CPU

/////////////////  Setting number of sticks  /////////////////////////////////

	stickCount = start(argc, argv); //checks for cmd line args, else, prompts
					//for number of sticks
	if( stickCount <= 0){
		printf("\nInvalid input.\nGoodbye.\n\n");
		return 0;
	}
	else if (argc == 2){
		printf("\nWelcome to the Stick Game!\n");
	}

///////////////////////  Gameplay  ///////////////////////////////////////////

	while (stickCount > 0){
		printSticks(stickCount);
		if (whosTurn == 1){ //if users turn
			stickCount = stickCount - userTurn(stickCount, &whosTurn);
		}
		else{	
			stickCount = stickCount - cpuTurn(stickCount, &whosTurn);	
		}
	}

////////////////////  Declare winner  ///////////////////////////////////////	

	printf("\nThere are no more sticks left.\n");	
	if (whosTurn == 1){
		printf("\nCPU wins!\n");
	}
	else{
		printf("\nYou win!\n");
	}
	printf("Thank you for playing.\n\n");
	
return 0;
}

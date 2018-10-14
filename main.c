#include<stdio.h>

///////////////////////////////////////////////////////////////////////////

/*
Ryan Whittingham
CSE224
Programming Assignment 2
October 14, 2018
*/

////////////////////  Function Prototypes  //////////////////////////////

int intCheck(char*);

/////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv) {
	
	char buffer[120];
	int stickCount;
	
	if (argc == 1){ //no command line argument detected
		printf("How many sticks would you like to play with?\n");
		fgets(buffer, 120, stdin);
		stickCount = intCheck(buffer);//function to check if valid #
	}

	else if(argc != 2){ //invalid # of command line arguments
		printf("Invalid number of arguments.\n");
		return 0; //program exits
	}

	if(argc == 2){ //Correct number of arguments
		stickCount = intCheck(argv[1]);//function to check if valid #
		if (stickCount == 0){ //if invalid #...
			return 0; //program exits
		}
	}	
	
	if(stickCount >= 10){	
		printf("Okay. Let's play with %i sticks.\n", stickCount);
	}
	else{
		return 0;
	}
	return 0;
}

////////////////////////   Functions   /////////////////////////////////

int intCheck(char buffer[]){ //Checks if input is an integer and >= 10
	int stickCount;
	int n = sscanf(buffer, "%d", &stickCount); 
	if (n != 1){
		printf("That is not a valid input.\n");
		return 0;
	}
	else if(stickCount < 10){
		printf("That is too low of a number.\n");
		return 0;
	}
	else {
		return stickCount;
	}

}

///////////////////////////////////////////////////////////////////////}

#include<stdio.h>

///////////////////////////////////////////////////////////////////////////

/*
Ryan Whittingham
CSE 224
October 14, 2018
Programming Assignment 2
*/

////////////////////  Function Prototypes  //////////////////////////////

int intCheck(char*);
int printSticks(int);
int userTurn(int, char **);
int cpuTurn(int, char **);

/////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv) {
	
	char buffer[120];
	int stickCount;
	char *whoTurn = "User";
	
	if (argc == 1){ //no command line argument detected
		printf("\nWelcome to the Stick Game!\n");	
		printf("\nHow many sticks would you like to play with?\n");
		fgets(buffer, 120, stdin);
		if (intCheck(buffer) == 0){
			return 0;
		}
		else{
			stickCount = intCheck(buffer);//function to check if valid #
		}
	}



	else if(argc != 2){ //invalid # of command line arguments
		printf("Invalid number of arguments.\n");
		return 0; //program exits
	}

	else if(argc == 2){ //Correct number of arguments
		stickCount = intCheck(argv[1]);//function to check if valid #
		if (stickCount == 0){ //if invalid #...
			return 0; //program exits
		}
		else{
			printf("\nWelcome to the Stick Game!\n");	
		}
	}	
	
	while (stickCount > 0){
		printSticks(stickCount);
		if (whoTurn == "User"){
			stickCount = stickCount - userTurn(stickCount, &whoTurn);
		}
		else {
			stickCount = stickCount - cpuTurn(stickCount, &whoTurn);	
		}
	}
	printf("\nThere are no more sticks left.\n");	
	if (whoTurn == "User"){
		printf("\nCPU wins.\n");
	}
	else{
		printf("\nWow! You actually won.\n");
	}
	printf("Thanks for playing.\n\n");
	
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
	else if (stickCount < 10){
		printf("That is too low of a number.\n");
		return 0;
	}
	else {
		return stickCount;
	}
}

int printSticks(int n){
	int i=0;
	printf("\nCurrent number of sticks:\n");
	while (i < n){
		printf("|");
		i = i+1;
	}
	printf("(%i)\n\n", n);
	return 0;
}

int userTurn(int n, char **s){
	char *whoTurn = "CPU";
	*s = whoTurn;
	
	char buffer[10];
	int takeNum;
	int validInput = 0;
	*s = whoTurn;
	while(validInput == 0){
		printf("How many sticks do you want to take?\n");
		fgets(buffer, 10, stdin);
		int check = sscanf(buffer, "%d", &takeNum);
		if (check != 1 || takeNum < 1 || takeNum > 3){
			printf("\nThat is not a valid input.\n");
			printf("Please try again.\n\n");
		} 
		else{
			validInput = 1;
		}	
	}
	return takeNum;
}

int cpuTurn(int n, char **s){
	char *whoTurn = "User";
	*s = whoTurn;
	
	int takeNum = n%4;
	if(takeNum == 0){
		printf("CPU will take 1.\n");
		return 1;
	}
	else{
		printf("CPU will take %i.\n", takeNum);
		return takeNum;
	}
}
///////////////////////////////////////////////////////////////////////}

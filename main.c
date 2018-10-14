#include<stdio.h>

int main (int argc, char** argv) {
	
	char buffer[120];
	int stickCount;
	int intCheck;
	//sscanf(argv[1], "%i", &stickCount);

	//printf("Welcome to the Stick Game!\n");
	
	//printf("How many sticks would you like to play with?");
	
	//fgets(buffer, 120, stdin);
	//sscanf(buffer, "%d", &stickCount);

	
	if (argc == 1){ //No command line argument
		printf("How many sticks would you like to play with?\n");
		fgets(buffer, 120, stdin);
		intCheck = sscanf(buffer, "%d", &stickCount);
		if (intCheck != 1){
			printf("That is not a number.\n");
			return 0;
		}
	}


	else if(argc != 2){
		printf("Invalid number of arguments.\n");
		return 0;
	}

	if(argc == 2){	
		intCheck = sscanf(argv[1], "%i", &stickCount);
		if (intCheck != 1){
			printf("That is not a number.\n");
			return 0;
		}
	}	
	
	printf("stickCount equals %i\n", stickCount);

	if (stickCount < 10){
		printf("That is too low of a number.\n");
		return 0;	
	}

	printf("Okay. Let's play with %i sticks.\n", stickCount);

	return 0;
}

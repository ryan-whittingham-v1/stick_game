#include<stdio.h>

int main (void) {
	
	char buffer[120];
	int stickCount;
	
	printf("Welcome to the Stick Game!\n");
	printf("How many sticks would you like to play with?");
	
	fgets(buffer, 120, stdin);
	sscanf(buffer, "%d", &stickCount);
	
	printf("%i\n", stickCount);
	
	return 0;
}

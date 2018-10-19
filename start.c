#include<stdio.h>
#include "PA2.h"
int intCheck(char *);

int start(int argc, char **argv){

        int stickCount;
        char buffer[120];

        if (argc == 1){ //no command line argument detected
                printf("\nWelcome to the Stick Game!\n");
                printf("\nHow many sticks would you like to play with?\n");
                fgets(buffer, 120, stdin);
                stickCount = intCheck(buffer); //check if an integer
                return stickCount;
        }
        else if(argc != 2){ //invalid # of command line arguments
                return 0;
        }
        else if(argc == 2){ //Correct number of arguments
                stickCount = intCheck(argv[1]);//check if an integer
                return stickCount;
        }
}


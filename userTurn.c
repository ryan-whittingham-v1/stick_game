#include<stdio.h>

int userTurn(int n, char **s){
        char *whoTurn = "CPU";
        *s = whoTurn;

        char buffer[10];
        int takeNum;
        int validInput = 0;
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

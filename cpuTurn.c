#include<stdio.h>

int cpuTurn(int n, int *x){
        int nextTurn = 1;
        *x = nextTurn; //Signifies next turn is the user.

        int takeNum = n%4; //CPU will win if remaining sticks after it's turn is a multiple of 4.
        if(takeNum == 0){
                printf("CPU will take 1.\n");
                return 1;
        }
        else{
                printf("CPU will take %i.\n", takeNum);
                return takeNum;
        }
}

#include<stdio.h>

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

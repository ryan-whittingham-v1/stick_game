#include<stdio.h>

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

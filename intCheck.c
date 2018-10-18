#include<stdio.h>

int intCheck(char buffer[]){
        int stickCount;
        int n = sscanf(buffer, "%d", &stickCount);
        if (n != 1){ //if not an integer
                return 0;
        }
        else {
                return stickCount;
        }
}

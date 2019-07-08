#include<stdio.h>

void main() {
    int x = 2;
    int y = 8;

    int log = 3;
    int sq = 1;
    int i;
    
    for(i=1;i<=y;i++) {
        sq *= x;
    }

    printf("\n sq = %d\n", sq);
}
#include<stdio.h>

void main() {
    int i;
    for(i=1;i<=5;i=(i+1/2)) 
        printf("%d\n", i);
}
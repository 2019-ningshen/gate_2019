#include<stdio.h>

void main() {
    int i;
    for(i = 0;i<10;i++) 
        if(i%2 == 0) {
            continue;
        } else {
            printf("%d", i);
        }
}
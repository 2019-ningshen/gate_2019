#include<stdio.h>

void main() {
    int n  = -17234;

    int largest = 0;
    int mod;
    while(n) {
        mod = n % 10;
        //printf("%d\n", mod);
        if(mod < largest) 
            largest = mod;
        n = n/10;
    }

    printf("%d\n", largest);
}
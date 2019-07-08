#include<stdio.h>

void main() {
    int n = 49;

    int sqrt, temp;

    sqrt = n / 2;
    temp = 0;

    while(temp != sqrt) {
        temp = sqrt;
        printf("%d\n", sqrt);
        sqrt = (n / temp + temp) / 2;


    }

    printf("square root of %d is %d\n", n, sqrt);
}
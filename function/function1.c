#include<stdio.h>

void main() {
    int x;
    x = printf("ABC"); // ABC
    printf("%d\n", x); // 3

    //COMBINING STATEMENT 5 AND 6  == 
    printf("%d\n", printf("ABC"));
}
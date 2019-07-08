#include<stdio.h>

void main() {
    int f1(int);
    int x = 10;
    int y = 20;
    y  = f1(x);

    printf("%d && %d\n", x, y);
}

int f1(int a ) {
    int f2(int);
    a = a + 2;
    int x = f2(a);
    printf("This is '112' = %d\n", x);
    return a+1;
}

int f2(int a) {
    return a+100;
}


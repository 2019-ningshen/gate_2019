#include<stdio.h>

int p(int, int);
void main() {
    int x = 100;
    int y = 5;
    int v = p(x,y);

    printf("%d\n", v);
}



int p(int x, int y) {
    
    if(y == 0) return 1;
    int temp = p(x, y/2);
    printf("temp %d\n", temp);
    return 2 * temp;
}


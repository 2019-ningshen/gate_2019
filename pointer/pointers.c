#include<stdio.h>

void main() {
    int i = 10;

    int *j = &i;  // value of
    int **k =  &j; // (value of (value of ))

    printf("i = %d  and *j == i == %d *k == i = %d\n", i, *j, **k);
    printf("&i == %u and j == &i == %u and *k == %u\n", &i, j, *k);
}
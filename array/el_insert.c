#include<stdio.h>

void simple_insert(int a[], int s, int key) {
    int i;

    for(i=8;i>=0;i--) {
        if(a[i] < key)
            break;
         a[i+1] = a[i];

    }
    printf("[%d]\n", i);
    a[i] = key;
}

void main() {
    int a[10] = { 1,2,3,4,5,7,8, 9, 10};
    int cap = sizeof(a)/sizeof(a[0]);
    int key = 6;
    simple_insert(a, cap, key);
    for(int i=0;i<cap;i++)
        printf("%d\n", a[i]);
}
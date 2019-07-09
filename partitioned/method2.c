#include<stdio.h>

void swap(int *, int *);
void main() {
    int a[] = {3,8,2,9,4,11,17,21,1,25,36,92,12};
    int s = sizeof(a)/sizeof(a[0]);
    int i;
    int pivot = a[s-1];
    int j = 0;
    for(i=0;i<s;i++) {
        if(a[i] <= pivot) {
            swap(&a[i], &a[j]);
            j++;
        }
           
    }
    swap(&a[j+1], &a[s-1]);

    for(i=0;i<s;i++) 
        printf(" %d", a[i]);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
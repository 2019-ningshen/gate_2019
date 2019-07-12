#include<stdio.h>

void main() {
    int a[] = {0,1,2,3,4,5,6,8,9};
    int s = 10;
    int total = (s * (s-1))/2;
    printf("%d\n", total);
    int sum = 0;
    int i;
    for(i=0;i<sizeof(a)/sizeof(a[0]); i++) 
        sum+=a[i]; 

    printf("sum = %d Missing number:  %d\n", sum, total - sum);
}
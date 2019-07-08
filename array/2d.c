#include<stdio.h>

void main() {
    int s[4][2] = { {1234, 10}, {2345, 20}, {3456, 30}};

    int i;
    for(i=0;i<3;i++) {
        printf("Address of %d th of the 1-d array is %u and value = %d and %d\n", i, s[i], *(s[2] +1), *(*(s + i) +1));
    }

    int ( *p )[2];
    int j, k, *pint;

    for(j=0;j<3;j++) {
        p = &s[j];
        pint = p;
        for(k=0;k<=1;k++) {
            printf("%d\n", *(pint + k));
        }
    }
}




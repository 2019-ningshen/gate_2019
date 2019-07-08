#include<stdio.h>

void insertion_sort(int ar[], int s);
int main() {
    int ar[] = { 4,3,5,1,0,2};
    int s = sizeof(ar)/sizeof(ar[0]);
    insertion_sort(ar, s);
    int i;
    for(i=0;i<s;i++) 
        printf(" %d ", ar[i]);
    return 0;
}

void insertion_sort(int ar[], int s) {
    int i, j, key;
    for(i=1;i<s;i++) {
        key = ar[i];
        j = i - 1;

        while(j >= 0 && ar[j] > key) {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        printf("j _1  = %d", j);
        ar[j+1] = key;
    }
}
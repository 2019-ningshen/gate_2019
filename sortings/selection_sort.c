#include<stdio.h>

void print_ar(int ar[], int s);
void swap(int * , int *);
void selection_sort(int ar[], int s);
int main() {
    int ar[] = {4,3,1,2,8,7};
    int size = sizeof(ar)/sizeof(ar[0]);
    selection_sort(ar, size);
    print_ar(ar, size);
    return 0;
}

void selection_sort(int ar[], int s) {
    int i, j;
    for(i=0;i<s - 1;i++) {
        for(j=i + 1;j < s; j++) {
            if(ar[i] > ar[j]) 
                swap(&ar[i], &ar[j]);
            else 
                printf("No Swap i = %d, j = %d \n", ar[i], ar[j]);
        }
    }
}

void swap(int *x , int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print_ar(int ar[], int s) {
     printf("[");
    for(int i=0;i<s;i++) 
        printf("%d, ", ar[i]);
     printf("] \n");
}
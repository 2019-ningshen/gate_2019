#include<stdio.h>

void print_ar(int ar[], int s);
void swap(int * , int *);
void bubble_sort(int ar[], int s);
int main() {
    int ar[] = {4,3,1,2,8,7};
    int size = sizeof(ar)/sizeof(ar[0]);
    bubble_sort(ar, size);
    print_ar(ar, size);
    return 0;
}

void bubble_sort(int ar[], int s) {
    int i, j;
    for(i=0;i<s;i++) {
        for(j=0;j<s-i-1; j++) {
            if(ar[j] > ar[j+1]) 
                swap(&ar[j], &ar[j+1]);
            else 
                printf("No Swap i = %d, i+1 = %d \n", ar[i], ar[i+1]);
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
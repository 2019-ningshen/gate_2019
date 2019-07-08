#include<stdio.h>
#include<stdlib.h>

void linear_insertion(int a[], int s, int val) {
    int i;
    for(i=s-1;i>=0;i--) {
        if(a[i] > val) a[i+1] = a[i];
        else break; 
    }
    a[i+1] = val;
}

void divide_and_conquer_insertion(int a[], int s, int val) {
    int left, right;
    left = 0;
    right = s-1;

    if(left == right) {
        if(a[left] > val) {
            a[left + 1] = a[left];
            a[left] = val; 
        } else 
            a[left + 1] = val;

            
    }
    while(left < right) {
        /* TODO: Find the index which is just greater than the val and do shifting from that index to last index. and insert it at i+1 */   
        return;
    }
}
void main() {
    int a[] = { 1,2,4,5,6};
    int s = sizeof(a)/sizeof(a[0]);
    int val = 3;
    int choice;
    printf("1. Linear Insertion.\n2. Divide and conquer insertion.\n0. Exit\n");
    while(1) {
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                linear_insertion(a, s, val);
                printf("[ ");
                for(int i=0;i<=s;i++) 
                    printf(" %d", a[i]);
                    printf(" ]\n");
                break;
            case 2:
                divide_and_conquer_insertion(a, s, val);
                printf("Function not implemented! Please Continue with other options.\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Input\n");

        }
    }
}
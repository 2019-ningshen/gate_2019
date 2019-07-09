/*
    Program to find the maximun and minimum element from the array.

    Time Complexity:

        2 + 4 + 6 + 8..........n = O(n)
 */


#include<stdio.h>
#include<stdlib.h>

struct pair {
    int min;
    int max;
};
struct pair divide_conquer(int a[], int low, int high) {
    struct pair minmax, mml, mmr;
    int mid;

    if(low == high) {
        minmax.max = a[low];
        minmax.min = a[low];
        return minmax;
    }

    if(high == low + 1) {
        minmax.max = a[high] > a[low] ? a[high] : a[low];
        minmax.min = a[low] < a[high] ? a[low] : a[high];
        return minmax;
    }

    
    mid = (low + high)/2;
    mml = divide_conquer(a, low, mid);
    mmr = divide_conquer(a, mid + 1, high);

    if(mml.min < mmr.min) 
        minmax.min = mml.min;
    else 
        minmax.min = mmr.min;
    
    if(mml.max > mmr.max) 
        minmax.max = mml.max;
    else 
        minmax.max = mmr.max;
    
    return minmax;

}

// TODO
struct pair divide_conquer_iterative(int a[], int low, int high) {
    struct pair minmax, lmax, lmin, rmax, rmin;
    int mid;
    if(low == high) {
        minmax.min = a[low];
        minmax.max = a[low];
    }

    if(high == low + 1) {
        minmax.min = a[low] < a[high] ? a[low] : a[high];
        minmax.max = a[low] < a[high] ? a[high] : a[low];
    }

    while(low < high) {
        mid = (low + high)/2;

    }
}
void linear_method(int a[], int s, int *min, int *max) {
    *min = (s%2) ? a[0] > a[1] ? a[1] : a[0] : a[0];
    *max = (s%2) ? a[0] > a[1] ? a[0] : a[1] : a[0]; 
    int i;
    for(i= (s%2) ? 1 : 2; i<s;i=i+2) {
        if(a[i] > a[i+1]) {
            *max = a[i] > *max ? a[i] : *max;
            *min = a[i+1] < *min ? a[i+1] : *min;
        } else {
            *max = a[i+1] > *max ? a[i+1] : *max;
            *min = a[i] < *min ? a[i] : *min;
        }
    }   
}

void main() {
    int a[] = {4,10,3,1, 15,40};
    int s = sizeof(a)/sizeof(a[0]);
    int min, max;
    struct pair minmax; 
   

    int choice;
    printf("Enter your choice\n");
    printf("1.Method 1: Linear.\n2.Divide and conquer.\n0.exit\n");

    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                linear_method(a, s, &min, &max);
                printf("Min = %d and Max = %d\n", min, max);
                break;
            case 2:
                minmax = divide_conquer(a, 0, s-1);
                printf("Using Divide and conquer: Min = %d and Max = %d\n", minmax.min, minmax.max);
                break;
            case 3:
                // TODO: 
                minmax = divide_conquer_iterative(a, 0, s-1);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
}

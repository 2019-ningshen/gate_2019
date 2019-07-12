/*
    Finding duplicates.
*/

#include<stdio.h>
#include<stdlib.h>


void sorted_series(int a[], int s) {
    int sum;
    int total;
    int i;
    for(i=0;i<s;i++) 
        sum+=a[i];
    total = (s* (s-1)) / 2; //take one number more for s (ex: 1 - 7 then s = 8)
    int dif = sum - total;
    printf("sum = %d, total = %d difference == duplicate == : %d\n", sum, total, dif);
}

void sorted_series2(int a[], int s) {
    int l = 0;
    int r = s - 1;
    while((l < r) && (l != r)) {
        int mid = (l+r)/2;
        if(a[mid] == mid) {
            r = mid - 1;

        } else {
            l = mid + 1;
        }
    }
    printf("Duplicated value: %d\n", a[l]);
}
void main() {
    int a[] = {1,2,2,3,4,5,6,7};
    int s = sizeof(a)/sizeof(a[0]);

    int choice;
    printf("Enter your choice\n");
    printf("1. Remove duplicate from 1-n sorted array.\n2. Remove duplicate from unsorted array.\n0. Exit\n");
    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                sorted_series(a, s);
                break;
            case 2:
                sorted_series2(a, s);
                break;

            case 0:
                exit(0);
                break;
            default:
                printf("Invalid Input\n");
        }
    }

}
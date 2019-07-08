#include<stdio.h>
#include<stdlib.h>


int linear_search(int a[], int s, int target) {
    int i;
    for(i=0;i<s;i++) 
        if(a[i] == target) {
            return i;
        }
    return -1;
}

int binary_search_iterative(int a[], int s, int left, int right, int target) {
    int mid;
    if(left == right) 
        return left;
    while(left < right)  {
        mid = (left+right)/2;
        if(target == a[mid])
            return mid;
        if(a[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
}   

int binary_search_recursive(int a[], int s, int left, int right, int target) {
    if(left == right) 
        return left;
    int mid = (left + right)/2;
    if(a[mid] == target) 
        return mid;
    if(a[mid] < target) 
        return binary_search_recursive(a, s, mid + 1, right, target);
    else 
        return binary_search_recursive(a, s, left, mid - 1, target);
}
void main() {
    int a[] = { 1,2,3,4,5,6,7,8,9,100};
    int size = sizeof(a)/sizeof(a[0]);
    int target = 100;
    int index;
    int left, right;
    left = 0;
    right = size-1;
    int choice;
    printf("Enter your choice.\n");
    printf("1. Linear search. \n2. Iterative Binary Search.\n3. Recursive Binary Search.\n0.Exit\n");
   

    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                index = linear_search(a, size, target);
                if(index)
                    printf("Element found at index: %d\n", index);
                else 
                    printf("No Index Found");
                break;
            case 2:
                index = binary_search_iterative(a, size, left, right, target);
                if(index)
                    printf("Index found through binary search at index: %d\n", index);
                else 
                    printf("Binary Search Unsuccessful!\n");
                break;
            case 3: 
                index = binary_search_recursive(a, size, left, right, target);
                if(index) 
                    printf("Index found through recursive binary search at index: %d\n", index);
                else 
                    printf("Recursive Binary search Unsuccessful\n");
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Input.\n");
        }
    }

}
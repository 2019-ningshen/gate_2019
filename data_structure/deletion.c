/*
    Delete element. 
    Sort element using any sorting method.
    Search element using binary search.
    Shift elements.
 */


#include<stdio.h>
#include<stdlib.h>

/*
    Helper function
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Time Complexity for Binary Search
        a. Worst case : O(logn)
        b. Beast case: O(1)
        c. Average case: O(logn)
 */
int bs(int a[], int s, int del) {
    int l = 0;
    int r = s - 1;
    if(l == r) return 0;
    
    while(l <  r) {
        int mid = (l+r)/2;
        if(a[mid] == del) return mid;
        if(a[mid] > del) 
            r = mid - 1;
        else 
            l = mid + 1;
    }
}


/*
    Time Complexity for bubble sort
        a. Worst case: O(n^2)
        b. Best case: O(n^2)
        c. Average case: O(n^2)

 */
void bubble_sort(int a[], int s) {
    printf("BUBBLE SORT------\n");
    int i, j;
    for(i=0;i<s;i++) {
        for(j= 0; j < (s-i-1); j++) {
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}

/*
    Time Complextity for insertion sort
        a. Worst Case: O(n^2)
        b. Best case: O(n)
        c. Average case: O(n^2)
 */
void insertion_sort(int a[], int s) {
    printf("INSERTION \n");
    int i, j, key;
    for(i=0;i<s;i++) {
        key= a[i];
        j = i - 1;

        while( j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

/*
    Time complexity  
        Best/Worst/Average  = O(n^2)
 */

void selection_sort(int a[], int s) {
    printf("SELECTION SORT--------");
    int i, j, min;
    for(i=0;i<s-1;i++) {
        min = i;
        for(j=i+1;j<s;j++) {
            if(a[j] < a[min]) 
                min = j;
        }
        swap(&a[min], &a[i]);
    }

}

void delete_pos(int a[], int s, int position) {
    a[position] = a[s-1];
}

/*
    Time Complexity to delete 1 element from a sorted array
        1. Sort Element = O(n^2)
        2. Search The key element = O(logn)

        Worst case = O(n^2logn)
 */

void delete_from_sorted(int a[], int s, int del) {
    int sort_choice;
    
    printf("Choose your type of sorting.\n");
    printf("1. Selection Sort.\n 2. Insertion Sort. \n3.Bubble Sort.\n");

    scanf("%d", &sort_choice);

    switch(sort_choice) {
        case 1: 
            selection_sort(a, s);
            break;
        case 2:
            insertion_sort(a, s);
            break;
        case 3:
            bubble_sort(a, s);
            break;
        default:
            bubble_sort(a, s);
            break;
    }

   
    printf("BEFORE\n");
    for( int i = 0;i<s;i++) 
        printf(" %d ", a[i]);
    int i;
    int index  = bs(a, s, del);
    printf("Index of the element %d\n", index);

    for(i=index;i<s;i++) 
        a[i] = a[i+1];
    
    printf("AFTER\n");
    for( int i = 0;i<s-1;i++) 
        printf(" %d ", a[i]);
}
void main() {
    int a[] = {10,2,15, 3, 8, 7, 9, 4};
    int s = sizeof(a)/sizeof(a[0]);
    int i;
    int position;
    int del = 2;
    int choice;
    printf("Enter your choice\n");
    printf("1. Delete element at entered position.\n2. Delete element from sorted array.\n 0.Exit");
    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            /*
                delete element at pos p = 3
            */
                printf("Enter position\n");
                scanf("%d", &position);
                delete_pos(a, s, position);
                printf("[ ");
                for(i=0;i<s - 1;i++) 
                    printf(" %d", a[i]);
                printf(" ]\n");
                break;
            case 2:
                delete_from_sorted(a, s, del);
                break;

            case 0:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    } 
 
}
#include<stdio.h>
#include<stdlib.h>


int n_space(int a[], int n) {
    if(n == 0 || n == 1) 
        return n;
    
    int temp[n];

    int j = 0;
    for(int i=0;i<n;i++) {
        if(a[i] != a[i+1]) 
            temp[j++] = a[i];
    }

    for(int i=0;i<j;i++) {
        a[i] = temp[i];
    }
    return j;
}
int one_space(int a[], int n) {
    if (n == 0 || n == 1) 
        return 1;
    int j = 0;

    for(int i=0;i<n;i++) 
        if(a[i] != a[i+1]) 
            a[j++] = a[i];
    

    return j;
}
void main(){
    int a[] =  {1, 2, 2, 3, 4, 4, 4, 5, 5}; 
    int s = sizeof(a)/sizeof(a[0]);
    int new_size;
    int choice; 
    int i;
    printf("Enter Your choice\n");
    printf("1. Remove duplicate using extra n space\n");
    printf("2. Remove duplicate using extra 1 space\n");
    while(1) {
        scanf("%d", &choice);

        switch(choice) {
            case 1:  
                new_size = n_space(a, s);
                printf("Elements are:\n[");
                for(i=0;i<new_size;i++) 
                    printf(" %d", a[i]);
                printf("]");
                break;
            case 2:
                new_size = one_space(a, s);
                  printf("Elements are:\n[");
                for(i=0;i<new_size;i++) 
                    printf(" %d", a[i]);
                printf("]");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    } 
}
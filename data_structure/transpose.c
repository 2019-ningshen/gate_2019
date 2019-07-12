#include<stdio.h>
#include<stdlib.h>


void additional_array(int a[3][3] , int b[3][3], int s) {
    int i, j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++) {
            b[i][j] = a[j][i];
        }
    }
}

void single_array(int a[3][3], int s) {
    int i,j, t;
    for(i=0;i<3;i++) 
        for(j=i+1;j<3;j++) {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        } 

}
void main() {
    int a[3][3] = {{9,1,0}, {6,2,10}, {9,-15,5}};
    int b[3][3];
    int size = sizeof(a)/sizeof(a[0][0]);
    int i,j;
    printf("Enter your choice?\n");
    printf("1. Transpose Matrix using Additional Array.\n2. Transpose matrix without using additional matrix.\n");
    int choice;
    printf("ORIGINAL MATRIX\n");
     for(i=0;i<3;i++) {
        printf("[ ");
        for(j=0;j<3;j++) {
            printf(" %d", a[i][j]);
        }
        printf(" ]\n");
    }
    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                additional_array(a, b, size);
                printf("Transpose of a matrix using extra array.\n");
                for(i=0;i<3;i++) {
                    printf("[ ");
                    for(j=0;j<3;j++) {
                        printf(" %d", b[i][j]);
                    }
                    printf(" ]\n");
                }
                break;
            case 2:
                single_array(a, size);
                printf("Transpose of a matrix without using extra array.\n");
                for(i=0;i<3;i++) {
                    printf("[ ");
                    for(j=0;j<3;j++) {
                        printf(" %d", a[i][j]);
                    }
                    printf(" ]\n");
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
}
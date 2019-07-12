#include<stdio.h>
#include<stdlib.h>


typedef struct polynomial {
    float coeff;
    int expo;
} polynomial;


void display(polynomial p) {

}
int get_firstPoly(polynomial p[10]) {
    int t1, i;
    printf("Enter total number of terms\n");
    scanf("%d", &t1);

    printf("\n Enter the exponent and coefficient in decending order\n");
    for(i=0;i<t1;i++) {
        printf("Enter the coefficient(%d): \n", i+1);
        scanf("%d", &p[i].coeff);

        printf("Enter the exponent (%d)\n", i+1);
        scanf("%d", &p[i].expo);
    }   
    return t1;
}
void main() {
    struct polynomial p1[] = {10, 3, 12, 5};
    struct polynomial p2[] = {44, 5, 3, 1};
    int t1, t2;
    printf("Enter your choice\n");
    printf("1. Enter First Polynomial\n");
    printf("2. Enter second polynomial\n");
    printf("3. Display polynomials.\n");
    printf("4. Add Two polynomials\n");
    printf("5. Subtract two polynomials\n");
    printf("6. Multiply two polynomials\n");

    int choice;
    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                get_firstPoly(p1);
                display(p1);
                break;
            case 2:
                get_secondPoly(p2);
                display(p2);
            case 3: 
                display_both(p1, p2);
                break;
            
            // case 2:
            //     add(p1, p2);
            //     break;
            // case 3:
            //     subtract(p1, p2);
            //     break;
            // case 4:
            //     multiply(p1, p2);
            //     break;
            case 0:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
}
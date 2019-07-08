#include<stdio.h>

/*
    EXTERNAL STORAGE 
*/
int x = 10;
void external_storage() {
    extern int y;  // variable difinition.
    printf("\n%d and %d\n", x, y); 
}



void main() {

    external_storage();
}
int y = 90;
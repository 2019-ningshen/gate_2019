#include<stdio.h> 

/* Function to calculate x raised to the power y */
int power(int x, unsigned int y) 
{ 
    int c = 0;
	int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    printf("temp = %d\n", temp);
   // return temp * temp;
    if (y%2 == 0) {
        return temp*temp; 
    }
    
    else
        return x*temp*temp; 
    
} 

/* Program to test function power */
void main() 
{ 
	int x = 2; 
	unsigned int y = 8; 

	printf("Final = %d", power(x, y)); 
}

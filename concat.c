#include<stdio.h>

void main() {
    int a[] = {5,20,21,52,60,85};
    int b[] = {1,28,80,95};

    int x = sizeof(a)/sizeof(a[0]);
    int y = sizeof(b)/sizeof(b[0]);

    int c[(x+y) - 2];

    int i, m=0, n=0;
    for(i=0; i<(x+y) - 2; i++) {
        if(m <= x && n <= y) {
            if(a[m] < b[n]) {
                c[i] = a[m];
                m++;
            } else {
                c[i] = b[n];
                n++;
            }
        }
        if( m <= (x-1) && n > (y - 1)) {
            c[i] = a[m];
            m++;
        }

        if(m > (x - 1) && n <= (y - 1)) {
            c[i] = b[n];
            n++;
        }
    } 

    for(i=0;i<(x+y) - 2;i++)
        printf("%d ", c[i]);
}


/*




void merge(int ar1[], int ar2[], int m, int n) 
{ 
    // Iterate through all elements of ar2[] starting from 
    // the last element 
    for (int i=n-1; i>=0; i--) 
    { 
        /* Find the smallest element greater than ar2[i]. Move all 
           elements one position ahead till the smallest greater 
           element is not found */
      /*  int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 
  
        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 
} 

*/
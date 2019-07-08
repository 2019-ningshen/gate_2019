// BUG - NEED FIXING 

#include<stdio.h>

void main() {
    int a[] = {3,8,2,9,4,11,17,21,1,25,36,92,12};
    int s = sizeof(a)/sizeof(a[0]);
    int l = 0;
    int r = s - 1;
    int p = a[r];
    int flag1 = 0, flag2 = 0;
    while(l < r) {
        
        if(flag1  == 0) {
            if(a[l] < a[p]) l++;
            else flag1 = 1;
        }
       

        if( flag2 == 0) {
            if(a[r] > a[p]) r--;
            else flag2 = 1;
      
        }

        if (flag1 == 1 && flag2 == 1 ) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            flag1 = 0;
            flag2 = 0;
        }
        
    }
    if(l == r) {
        int temp = a[l];
        a[l] = a[s-1];
        a[s-1] = temp;
    }

    int i;
    for(i=0;i<s-1;i++) {
        printf("%d ", a[i]);
    }
}
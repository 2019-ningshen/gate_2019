#include<stdio.h>
void cross_max(int a[], int  low, int mid, int high, int *, int *, int *);
void main() {
    int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int s = sizeof(a)/sizeof(a[0]);   
    int low = 0;
    int high = s - 1;
    int mid = (low+high)/2;
    printf("%d\n", mid);
    int max_left, max_right, total_sum;
    cross_max(a, low, mid, high, &max_left, &max_right, &total_sum);
   
    printf("%d", max_left);
    
}
void cross_max(int a[], int low, int mid, int high, int *max_left, int  *max_right, int *total_sum) {
    int left_sum = -32312313;
    int sum = 0;
    int i;
    for(i=mid; i>=low; i--) {
        sum = sum + a[i];
      //  printf("A[I] = %d, i = %d  sum = %d\n", a[i], i, sum);
        if(sum > left_sum) {
          //  printf("hit i = %d\n", i);
            left_sum = sum;
           // printf("lllll = %d\n", left_sum);
            *max_left = i;
        }
    }
    printf("sum  = %d,\n left_sum = %d\n", sum, left_sum);
}
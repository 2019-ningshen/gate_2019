#include<stdio.h>
void swap(int *, int *);
void separator(int a[], int s);
int main() {
    int a[] = { 4,3,7,6,1,2, 5};
    int s = sizeof(a)/sizeof(a[0]);
    separator(a, s);
    int i=0;
    for(i=0;i<s;i++)
        printf("%d", a[i]);
    return 0;
}

void separator(int a[], int s) {
    int r = s - 1;
    int l = 0;
    int pivot = a[r];
    int i;
    int k = -1;
    for(i = 0;i<r;i++)  {
        if(a[i] < pivot) {
            k++;
            swap(&a[k], &a[i]);
        }
    }
    //swap(&a[k+1], &a[r]);
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}
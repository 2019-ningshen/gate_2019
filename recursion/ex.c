#include<stdio.h>



int rec(int x) {
    if(x == 1) return 1;
    int res = x * rec(x-1); // 3 * 2 * 1 
    printf("== %d\n", res);
    return res;
}
void main() {
    int x = 3;

    int val = rec(x);
    printf("val = %d\n", val);
}
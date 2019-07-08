

#include<stdio.h>

/*
    Find a^n.
*/


int power_n(double a, int n) {
    if(n == 0) {
        if(n == 0) {
        int res3 = 1;
        return res3;
    }
    }
    if(n%2) {
        int res1 = power_n(a*a, n/2)*a;
        return res1;
    }
    int res2 = power_n(a*a, n/2);
    return res2;

}

/*
    Find a^n % p
*/

int power_modulo(int a, int n, int p) {
    if(n == 0) return 1%p;
    if(n%2) return power_modulo(a*a%p, n/2, p)* a % p;
    return power_modulo(a * a % p, n/2, p)%p;
}
void main() {
    double a = 2;
    int n = 7;
    
    int res = power_n(a, n);

    printf("%d\n", res);
}
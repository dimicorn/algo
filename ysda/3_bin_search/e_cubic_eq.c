#include <stdio.h>

long double qubic(long double a, long double b, long double c, long double d, long double x) {
    return d + x * (c + x * (b + x * (a)));
}

long double bin_search(long double a, long double b, long double c, long double d) {
    long double l = -2000L, r = 2000L;
    if (a < 0) {
        a = -a; 
        b = -b; 
        c = -c; 
        d = -d; 
    }   
    while (r - l > 1e-10) {
        long double mid = (r + l) * 0.5; 
        long double f = qubic(a, b, c, d, mid);
        if (f >= 0) {
            r = mid;
        } else {
            l = mid;
        }
    }   
    return r;
}

int main() {
    long double a, b, c, d;
    scanf("%Lf %Lf %Lf %Lf", &a, &b, &c, &d);
    long double res = bin_search(a, b, c, d); 
    printf("%.7Lf\n", res);    
    return 0;
}


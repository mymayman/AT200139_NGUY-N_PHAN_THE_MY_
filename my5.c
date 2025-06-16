#include <stdio.h>

long long euclid(long long a , long long b, long long *x, long long *y){
    long long x2 = 1, x1 = 0;
    long long y2 = 0, y1 = 1;
    long long q, r, x_temp, y_temp;
    
    while (b > 0){
        q = a / b;
        r = a - q * b;
        x_temp = x2 - q * x1;
        y_temp = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x_temp;
        y2 = y1;
        y1 = y_temp;
    }
    *x = x2;
    *y = y2;
    return a;
}

int main() {
    long long p, a;
    
    scanf("%lld", &p);
    scanf("%lld", &a) ;

    if (a <= 0 || a >= p) {
        printf("NOT FOUND\n");
        return 0;
    }

    long long x, y;
    long long g = euclid(a, p, &x, &y);
    
    if (g != 1) {
        printf("NOT FOUND\n"); 
    } else {
        if (x < 0) x += p;
        printf("%lld\n", x);  // x chính là nghịch đảo của a mod p
    }

    return 0;
}

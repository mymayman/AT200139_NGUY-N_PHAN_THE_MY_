#include<stdio.h>

long long extended_gcd(long long a, long long b, long long *x, long long *y) {
 long long x2 = 1,x1 = 0;
 long long y2 = 0,y1 = 1;
 long long q,r,x_temp,y_temp;
  while( b > 0){
   q = a/b;
   r = a - q*b;
   x_temp = x2 - x1*q;
   y_temp = y2 - y1*q;
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

long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, &x, &y);
    if (g != 1) return -1;
    else return (x % m + m) % m;
}
// Phép cộng hai điểm elliptic
void elliptic_add(long long x1, long long y1, long long x2, long long y2,
                  long long a, long long p,
                  long long* x3, long long* y3) {
    if (x1 == x2 && (y1 + y2) % p == 0) {
        *x3 = 0;
        *y3 = 0;
        return;
    }

    long long lambda;
    if (x1 == x2 && y1 == y2) {
        long long num = (3 * x1 % p * x1 % p + a) % p;
        long long den = (2 * y1) % p;
        long long inv = mod_inverse(den, p);
        if (inv == -1) {
            *x3 = *y3 = -1;
            return;
        }
        lambda = (num * inv) % p;
    } else {
        long long num = (y2 - y1 + p) % p;
        long long den = (x2 - x1 + p) % p;
        long long inv = mod_inverse(den, p);
        if (inv == -1) {
            *x3 = *y3 = -1;
            return;
        }
        lambda = (num * inv) % p;
    }

    *x3 = (lambda * lambda - x1 - x2 + 3 * p) % p;
    *y3 = (lambda * (x1 - *x3 + p) - y1 + p) % p;
}

int main() {
    long long p, a;
    long long x1, y1, x2, y2, x3, y3;

    scanf("%lld", &p);
    scanf("%lld", &a);
    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);

    elliptic_add(x1, y1, x2, y2, a, p, &x3, &y3);

    if (x3 != -1 && y3 != -1)
        printf("%lld %lld\n", x3, y3);

    return 0;
}

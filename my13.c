#include <stdio.h>

// Hàm Euclid mở rộng tính gcd và tìm x,y sao cho a*x + b*y = gcd(a,b)
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Tính nghịch đảo modulo bằng extended_gcd
long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

// Phép cộng hai điểm elliptic
void elliptic_add(long long x1, long long y1, long long x2, long long y2,
                  long long a, long long p,
                  long long* x3, long long* y3) {
    if (x1 == 0 && y1 == 0) { 
        *x3 = x2;
        *y3 = y2;
        return;
    }                                     // xử lý điểm vô cực ở các điểm p(0;0) và q(0;0)
    if (x2 == 0 && y2 == 0) { 
        *x3 = x1;
        *y3 = y1;
        return;
    }

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


void elliptic_mul_simple(long long k,
                         long long x, long long y,
                         long long a, long long p,
                         long long *rx, long long *ry) {
    *rx = 0;
    *ry = 0;
    long long tx = x, ty = y;

    for (long long i = 0; i < k; i++) {
        elliptic_add(*rx, *ry, tx, ty, a, p, rx, ry); // tính Pa = nA*G; bằng hàm eliptic_add vì nA*G cũng bằng G+G+G...nA lần b khong can thiet vì đang dùng để cọng và nhân
    }
}

int main() {
    long long p, a, b;
    long long gx, gy;
    long long nA;
    long long pax, pay;

    scanf("%lld", &p);
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld %lld", &gx, &gy);
    scanf("%lld", &nA);

    elliptic_mul_simple(nA, gx, gy, a, p, &pax, &pay);

    printf("%lld %lld\n", pax, pay); // trả về một điểm Pa (x,y);

    return 0;
}

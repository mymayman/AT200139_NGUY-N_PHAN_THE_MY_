#include <stdio.h>

// Hàm tính (a * b) % p
long long mulmod(long long a, long long b, long long p) {
    return (a * b) % p;
}

// Hàm tính (a + b) % p
long long addmod(long long a, long long b, long long p) {
    return (a + b) % p;
}

// Hàm tính (a - b) % p
long long submod(long long a, long long b, long long p) {
    return (a - b + p) % p;
}

// Hàm tính nghịch đảo modular của a mod p
long long modinv(long long a, long long p) {
    long long t = 0, newt = 1;
    long long r = p, newr = a;
    while (newr != 0) {
        long long quotient = r / newr;
        long long temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1; // Không tồn tại nghịch đảo
    if (t < 0) t += p;
    return t;
}

int main() {
    long long p, a;
    scanf("%lld", &p);  // Trường modulo p
    scanf("%lld", &a);  // Hệ số a trong phương trình elliptic

    long long x1, y1, x2, y2;
    scanf("%lld %lld", &x1, &y1);  // Điểm P
    scanf("%lld %lld", &x2, &y2);  // Điểm Q

    if (x1 == x2 && y1 == (p - y2) % p) {
        // Trường hợp P = -Q thì P + Q = O
        printf("0 0\n");
        return 0;
    }

    long long lam;
    if (x1 == x2 && y1 == y2) {
        // P = Q
        long long numerator = (3 * x1 % p * x1 % p + a) % p;
        long long denominator = modinv(2 * y1 % p, p);
        lam = mulmod(numerator, denominator, p);
    } else {
        // P != Q
        long long numerator = submod(y2, y1, p);
        long long denominator = modinv(submod(x2, x1, p), p);
        lam = mulmod(numerator, denominator, p);
    }

    long long x3 = submod(mulmod(lam, lam, p), addmod(x1, x2, p), p);
    long long y3 = submod(mulmod(lam, submod(x1, x3, p), p), y1, p);

    printf("%lld %lld\n", x3, y3);

    return 0;
}

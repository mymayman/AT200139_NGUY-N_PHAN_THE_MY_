#include <stdio.h>
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        exp = exp >> 1;    
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, a, b;
    scanf("%lld %lld", &p, &g);
    scanf("%lld %lld", &a, &b);
    long long A = mod_pow(g, a, p);
    long long B = mod_pow(g, b, p);
    long long K = mod_pow(B, a, p);

    printf("%lld\n", K);
    return 0;
}

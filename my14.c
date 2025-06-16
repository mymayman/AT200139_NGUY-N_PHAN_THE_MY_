#include <stdio.h>   
#include <stdlib.h> 
#include <stdint.h>  
#include <stdbool.h> 

long long power(long long base, long long exp, long long mod) {
    long long res = 1;  
    base %= mod;           
    while (exp > 0) {
        if (exp % 2 == 1) { 
            res = (res * base) % mod;
        }
        base = (base * base) % mod; 
        exp /= 2;             
    }
    return res;
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b; 
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

long long modInverse(long long a, long long m) {
    long long m0 = m; 
    long long y = 0, x = 1;

    if (m == 1) { 
        return 0;
    }
    a = (a % m + m) % m;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

int main() {
    long long p, alpha, a, k, x; 
    scanf("%lld", &p);
    scanf("%lld", &alpha);
    scanf("%lld", &a);
    scanf("%lld", &k);
    scanf("%lld", &x);
    long long gamma = power(alpha, k, p);
    if (gcd(k, p - 1) != 1) {
        printf("Lỗi: k phải đồng nguyên tố với (p - 1) để nghịch đảo mô-đun tồn tại.\n");
        return 1;
    }
    long long k_inv = modInverse(k, p - 1);
    long long term_a_gamma_mod = (a * gamma) % (p - 1);
    long long term_x_minus_a_gamma = (x - term_a_gamma_mod);
    term_x_minus_a_gamma = (term_x_minus_a_gamma % (p - 1) + (p - 1)) % (p - 1);

    long long delta = (term_x_minus_a_gamma * k_inv) % (p - 1);
    printf("%lld %lld\n", gamma, delta);
    return 0; 
}

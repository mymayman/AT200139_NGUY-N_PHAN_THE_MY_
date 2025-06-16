#include<stdio.h>

unsigned long long powmod(unsigned long a, unsigned long d,unsigned long long n){
     unsigned long resuslt = 1;
     a = a % n;
     while(d > 0){
        if(d % 2 == 1)
         resuslt = (resuslt*a) % n;
            d = d / 2;
            a = (a*a) % n;
    }
    return resuslt;
}

int main() {
    unsigned long long p, g, k, y, m;
    unsigned long long a, b;

    scanf("%llu", &p);
    scanf("%llu", &g);
    scanf("%llu", &k);
    scanf("%llu", &y);
    scanf("%llu", &m);

    a = powmod(g, k, p);

    unsigned long long y_k = powmod(y, k, p);
    b = (m * y_k) % p;

    printf("%llu\n", a);
    printf("%llu\n", b);

    return 0;
}
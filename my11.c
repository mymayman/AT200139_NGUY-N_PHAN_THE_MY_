#include<stdio.h>

long long powmod(long long a, long long d, long long n){
     long long resuslt = 1;
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
    long long p, q, m, d, n, s;
    scanf("%lld", &p);
    scanf("%lld", &q);
    scanf("%lld", &m);
    scanf("%lld", &d);

    n = p * q;
    s = powmod(m, d, n);
    printf("%lld\n", s);
    return 0;
}
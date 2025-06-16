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
unsigned long long nghichdaonghichdao(long long a,long long p){
    return powmod(a, p - 2, p);
}
 
int main(){
   long long  p, g, x, a, b;
    scanf("%lld" , &p);
    scanf("%lld", &g);
    scanf("%lld" , &x);
    scanf("%lld" " %lld" , &a, &b);
    long long ax = powmod(a, x, p);
    long long ax_inv = nghichdaonghichdao(ax, p);
    long long m = (b * ax_inv) % p;
    printf("%lld"  "\n", m);
    return 0;
}
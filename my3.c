#include<stdio.h>


long long powmod(long long a,long long b,long long n){
    long long resuilt = 1;
    a = a % n;
    while(b > 0){
        if( b % 2 == 1){
            resuilt = (resuilt*a) % n;
        }
        b = b/2;
        a =(a*a) % n;
    }
    return resuilt;
}

 int main(){
    long long p,q,m;
    scanf("%lld,%lld,%lld",&p,&q,&m);
    long long n =p*q;
    long long c = powmod(m,2,n);
    printf("%lld\n",c);
    return 0;
 }

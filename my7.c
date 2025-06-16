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
int main(){
    unsigned long long p,g,x;

    scanf("%llu",&p);
    scanf("%llu",&g);
    scanf("%llu",&x);

    if(x < 1 || x>= p-2){
        return 1;
    }
    unsigned long long y = powmod(g,x,p);
    printf("%llu", y);
    return 0;
    
}
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

uint64_t exp(uint64_t a,uint64_t b,uint64_t n){
    uint64_t result =1;
    a = a % n;
    while (b > 0)
    {
        if(b % 2 == 1){
            result = (result*a) % n;
        }
        b = b/2;
        a = (a*a) % n;
    }
    return result;
}
int main(){
    uint64_t p,q,e,m;
    scanf("%lu", &p);
    scanf("%lu", &q);
    scanf("%lu", &e);
    scanf("%lu", &m);

    uint64_t n = p*q;

    uint64_t c = exp(m, e, n);
    printf("%lu\n", c);
    return 0;
}
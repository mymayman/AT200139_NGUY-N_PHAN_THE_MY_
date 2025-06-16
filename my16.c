#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long modpow(long long a, long long d , long long n ){
    long long result = 1;
    while(d > 0){
        if( d % 2 == 1)
        result = (result*a) % n;
     d = d/2;
    a = (a*a) % n;
}
 return result;
}

int main(){
    long long n;
    int b;
    printf("nhập số n: ");
    scanf("%lld",&n);
    printf("nhap so lan thu: ");
    scanf("%d",&b);
    for(int i = 0; i < b;i++){
        long long a;
        scanf("%lld",&a);
        if(modpow(a,n-1,n) != 1){
        printf("%d",i+1);
        }
    }
    printf("-1\n");
    return 0;
}
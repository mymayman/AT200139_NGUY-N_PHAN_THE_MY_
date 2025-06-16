#include<stdio.h>


long long euclid(long long a , long long b, long long *x, long long *y){
    long long x2 = 1,x1 = 0;
    long long y2 = 0,y1 = 1;
    long long q,r,x_temp,y_temp;
    
    while (b > 0){
        q = a/b;
        r = a - q*b;
        x_temp = x2 - q*x1;
        y_temp = y2 - q*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x_temp;
        y2 = y1;
        y1 = y_temp;
  }
  *x = x2;
  *y = y2;
  return a;

}
int main(){
    long long p,q,e;
    scanf("%lld,%lld,%lld",&p,&q,&e);

    long long n = p*q;
    long long phi = (p-1)*(q-1);
    
    long long x,y;
    long long gdc = euclid(e,phi,&x,&y);
    if (gdc != 1) {
        printf("e không nguyên tố cùng nhau với phi(n)\n");
        return 1;
    }

    if (x < 0) x += phi;
    long long d = x;

    printf("%lld\n", n);
    printf("%lld\n", d);
    return 0;
}


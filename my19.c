#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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


int fermat(int n, int t){
    if(n < 4 ) return(n == 2|| n== 3);
    for(int i = 0; i < t; i++ ){
        int a = 2 + rand() % (n - 3);
       long long r = powmod(a , (n - 1), n);
        if(r != 1) return 0;
    }
    return 1;
}
int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

  srand(time(NULL));
  int sum = 0;
  for(int i = a; i<=b; i++){
    if(i % 2 == 0 && i != 2) continue;
    if(fermat(i,c)){
        sum +=i;
    }
  }
  printf("%d", sum);
  return 0;

}
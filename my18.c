#include<stdio.h>
#include<stdlib.h>
#include<time.h>


long long powmode(long long a,long long d,long long n){
    long long r = 1;
    a = a % n;
    while (d > 0)
    {
       if( d % 2 == 1)
       r = (r*a) % n;
       d = d / 2;
    }
    return r;
}  
   
   int miler(long long n, int k) {
    if( n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0) return 0;

    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0){
        d = d / 2;
        s++;
    }
    for(int i = 0; i < k ; i++){
        long long a = 2 + rand() % (n - 3);
        long long r = powmode(a,d,n);
        if( r == 1|| r == n -1) continue;

        int ok = 1;
        for( int i = 0; i < s; i++){
           r = (r*r) % n;
           if(r == n-1){
           ok = 1;
           break;
           }
        }
        if(!ok) return 0;
    }
    return 1;
 }
  
 int main(){

    
        int a;
        int s[100];

        srand(time(NULL));
        scanf("%d",&a);
        for(int i = 0; i< a; i++){
            scanf("%d",&s[i]);
        }
        for(int i = 0; i < a; i++){
            if(miler(s[i],5));
               printf("%d ", s[i]);
        }
        printf("\n");
         return 0;
}



     
 
 
 

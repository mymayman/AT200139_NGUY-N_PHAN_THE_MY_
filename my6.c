#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

// Ham tinh (a^b) % mod (dung luy thua nhi phan)
ll luy_thua(long long a,long long b,long long n){
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
// Thuat toan buoc lon buoc nho de tinh log_alpha(beta) mod n
ll tim_logarit_roi_rac(ll alpha, ll beta, ll n) {
    ll m = (ll)sqrt(n) + 1;

    // Buoc 2: Lap bang (j, alpha^j mod n)
    ll *bang = (ll*) malloc(sizeof(ll) * m);
    for (ll j = 0, hientai = 1; j < m; ++j) {
        bang[j] = hientai;
        hientai = (hientai * alpha) % n;
    }

    // Buoc 3: Tinh alpha^(-m) mod n (dung Fermat: alpha^-1 = alpha^(n-2) mod n)
    ll alpha_nghich_m = luy_thua(luy_thua(alpha, n - 2, n), m, n);

    // Buoc 4: Duyet i de tim giai thuat
    ll gamma = beta;
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (bang[j] == gamma) {
                free(bang);
                return i * m + j;
            }
        }
        gamma = (gamma * alpha_nghich_m) % n;
    }

    free(bang);
    return -1; // Khong tim duoc
}

int main() {
    ll n, alpha, beta;

    printf("Nhap n: ");
    scanf("%lld", &n);
    printf("Nhap phan tu sinh alpha: ");
    scanf("%lld", &alpha);
    printf("Nhap beta: ");
    scanf("%lld", &beta);

    ll ketqua = tim_logarit_roi_rac(alpha, beta, n);
    if (ketqua != -1)
        printf("log_%lld(%lld) mod %lld = %lld\n", alpha, beta, n, ketqua);
    else
        printf("Khong tim duoc logarit roi rac.\n");

    return 0;
}
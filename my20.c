#include <stdio.h>

// Hàm tính (a^b) % mod bằng lũy thừa nhị phân
long long powmod(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return result;
}

long long miler(long long n, long long r, long long a, int j_max) {
    long long temp = n - 1;
    int s = 0;
    while (temp % 2 == 0) {
        temp /= 2;
        s++;
    }
    long long y = powmod(a, r, n);
    if (y != 1 && y != n - 1) {
        int j = 1;
        while (j <= s - 1 && y != n - 1) {
            y = (y * y) % n;
            if (y == 1)
                return -1; // hợp số
            if (j == j_max)
                return -2; // quá số bước
            j++;
        }

        if (y != n - 1)
            return -1; // hợp số
    }

    return y; // Trả về y nếu không vi phạm gì
}

int main() {
    long long n, r, a;
    int j_max;

    scanf("%lld", &n);
    scanf("%lld", &r);
    scanf("%lld", &a);
    scanf("%d", &j_max);

    long long result = miler(n, r, a, j_max);

    if (result == -1)
        printf("%lld",result);
    else if (result == -2)
        printf("Too many steps\n");
    else
        printf("%lld\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long p, q, m, n, c;

    scanf("%llu", &p);
    scanf("%llu", &q);
    scanf("%llu", &m);

    n = p * q;

    c = (m * m) % n;

    printf("%llu\n", c);

    return 0;
}

#include <stdio.h>


int kiemtra(const char *s1, const char *s2, int n) {
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return s1[i] - s2[i];
    }
    return 0;
}
int main() {
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);

    char arr[n][101];  
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char str[101];
    scanf("%s", str);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (kiemtra(arr[i], str, k) == 0) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

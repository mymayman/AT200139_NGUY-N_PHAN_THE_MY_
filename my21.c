#include <stdio.h>
#include <string.h>
int boiomore(const char *haystack, const char *needle) {
    int n = strlen(haystack);
    int m = strlen(needle);

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == m) return 1;
    }
    return 0;
}


int main() {
    char A[1001], B[1001];
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);

    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';

    char repeated[5001] = ""; 
    int n = 0;

    while (strlen(repeated) < strlen(B) + strlen(A)) {
        strcat(repeated, A);
        n++;
        if (boiomore(repeated, B)) {
            printf("%d\n", n);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}

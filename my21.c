#include <stdio.h>
#include <string.h>

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
        if (strstr(repeated, B)) {
            printf("%d\n", n);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}

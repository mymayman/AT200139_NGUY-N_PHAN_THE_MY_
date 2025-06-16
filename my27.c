#include <stdio.h>
#include <string.h>

int main() {
    char X[1001];
    char Y[101];

    fgets(X, sizeof(X), stdin);
    fgets(Y, sizeof(Y), stdin);

    X[strcspn(X, "\n")] = '\0';
    Y[strcspn(Y, "\n")] = '\0';

    int lenX = strlen(X);
    int lenY = strlen(Y);
    int vitriccuoi = -1;

    for (int i = 0; i <= lenX - lenY; i++) {
        if (strncmp(&X[i], Y, lenY) == 0) {
            vitriccuoi = i; 
        }
    }

    if (vitriccuoi != -1)
        printf("%d\n", vitriccuoi);
    else
        printf("-1\n"); 

    return 0;
}

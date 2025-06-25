#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int tiento(char words[][MAX], int n, int index, char *prefix) {
    for (int i = 0; i < n; i++) {
        if (i != index && strncmp(words[i], prefix, strlen(prefix)) == 0) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char words[n][MAX];

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        int len = strlen(words[i]);
        char prefix[MAX] = "";

        for (int j = 1; j <= len; j++) {
            strncpy(prefix, words[i], j);
            prefix[j] = '\0';

            if (tiento(words, n, i, prefix)) {
                printf("%s ", prefix);
                break;
            }
        }
    }

    printf("\n");
    return 0;
}

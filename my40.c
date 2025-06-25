#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 101 

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("None\n");
        return 0;
    }
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(MAX_WORD_LEN * sizeof(char));
        scanf("%s", words[i]);
    }
    bool *is_substring = (bool *)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (strstr(words[j], words[i]) != NULL) {
                is_substring[i] = true;
                break; 
            }
        }
    }

    bool found_any = false;
    for (int i = 0; i < n; i++) {
        if (is_substring[i]) {
            if (found_any) {
                printf(" ");
            }
            printf("%s", words[i]);
            found_any = true;
        }
    }
    if (!found_any) {
        printf("None");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    free(is_substring);

    return 0;
}
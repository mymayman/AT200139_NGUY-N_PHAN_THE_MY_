#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1005
#define MAX_WORDS 105

char s[MAX_LEN];
char words[MAX_WORDS][MAX_LEN];
bool bold[MAX_LEN];

int main() {
    scanf("%s", s);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", words[i]);
    }

    int len = strlen(s);
    memset(bold, 0, sizeof(bold));
    for (int i = 0; i < len; ++i) {
        for (int k = 0; k < n; ++k) {
            int wl = strlen(words[k]);
            if (i + wl <= len && strncmp(s + i, words[k], wl) == 0) {
                for (int j = i; j < i + wl; ++j) {
                    bold[j] = true;
                }
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        if (bold[i] && (i == 0 || !bold[i - 1])) {
            printf("<b>");
        }
        printf("%c", s[i]);
        if (bold[i] && (i == len - 1 || !bold[i + 1])) {
            printf("</b>");
        }
    }

    printf("\n");
    return 0;
}

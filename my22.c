#include <stdio.h>
#include <string.h>

#define MAX 256 
void buildShiftTable(const char *pattern, int m, int shift[MAX]) {
    for (int i = 0; i < MAX; i++) {
        shift[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        shift[(unsigned char)pattern[i]] = m - i - 1;
    }
}

int main() {
    char text[1001], pattern[101];
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    int found = 0;

    buildShiftTable(pattern, m, shift);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        if (j < 0) {
            printf("%d ", i + 1); 
            found = 1;
            i += 1;  
        } else {
            i += shift[(unsigned char)text[i + m - 1]];
        }
    }

    if (!found) {
        printf("-1");
    }

    return 0;
}

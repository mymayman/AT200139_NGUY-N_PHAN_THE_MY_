#include <stdio.h>
#include <string.h>

#define MAX 1000

void count_char(char *str, int count[256]) {
    for (int i = 0; i < 256; i++) count[i] = 0;
    for (int i = 0; str[i]; i++) count[(unsigned char)str[i]]++;
}

int is_permutation(int a[256], int b[256]) {
    for (int i = 0; i < 256; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    char s[MAX], p[MAX];
    fgets(s, MAX, stdin);
    fgets(p, MAX, stdin);

    s[strcspn(s, "\n")] = 0;
    p[strcspn(p, "\n")] = 0;

    int len_s = strlen(s);
    int len_p = strlen(p);

    int count_p[256], count_window[256];

    count_char(p, count_p);

    for (int i = 0; i <= len_s - len_p; i++) {
        strncpy(p, s + i, len_p);
        p[len_p] = '\0';
        count_char(p, count_window);

        if (is_permutation(count_p, count_window)) {
            printf("%d ", i);
        }
    }

    return 0;
}

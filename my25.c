#include <stdio.h>
#include <string.h>

#define MAX 100

void normalize(char *s, char *pattern) {
    int map[256];
    int count = 0;
    for (int i = 0; i < 256; i++) map[i] = -1;

    for (int i = 0; s[i]; i++) {
        if (map[(unsigned char)s[i]] == -1)
            map[(unsigned char)s[i]] = count++;
        pattern[i] = map[(unsigned char)s[i]] + '0';
    }
    pattern[strlen(s)] = '\0';
}

int main() {
    int n;
    char behaviors[MAX][MAX];
    char target[MAX], pattern1[MAX], pattern2[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", behaviors[i]);
    scanf("%s", target);

    normalize(target, pattern1);

    for (int i = 0; i < n; i++) {
        normalize(behaviors[i], pattern2);
        if (strcmp(pattern1, pattern2) == 0)
            printf("%s ", behaviors[i]);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105

bool isIsomorphic(char* s, char* t) {
    int map1[256], map2[256];
    for (int i = 0; i < 256; i++) map1[i] = map2[i] = -1;

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (map1[c1] == -1 && map2[c2] == -1) {
            map1[c1] = c2;
            map2[c2] = c1;
        } else if (map1[c1] != c2 || map2[c2] != c1) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    char behaviors[MAX][MAX];
    char pattern[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%s", behaviors[i]);
    }
    scanf("%s", pattern);
    for (int i = 0; i < N; i++) {
        if (strlen(behaviors[i]) == strlen(pattern) && isIsomorphic(behaviors[i], pattern)) {
            printf("%s\n", behaviors[i]);
        }
    }

    return 0;
}

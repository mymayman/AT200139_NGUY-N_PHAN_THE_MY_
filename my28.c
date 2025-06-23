#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isBad(char *s, int vi_tri, int nguyen_am, int phu_am) {
    if (nguyen_am > 5 || phu_am > 3)
        return true;

    int len = strlen(s);
    if (vi_tri == len) 
        return false;

    if (s[vi_tri] == '?') {
        if (isBad(s, vi_tri + 1, nguyen_am + 1, 0))
            return true;
        if (isBad(s, vi_tri + 1, 0, phu_am + 1))
            return true;
        return false;
    } else {
        if (isVowel(s[vi_tri])) {
            return isBad(s, vi_tri + 1, nguyen_am + 1, 0);
        } else {
            return isBad(s, vi_tri + 1, 0, phu_am + 1);
        }
    }
}

int main() {
    char s[105];
    scanf("%s", s);

    if (isBad(s, 0, 0, 0)) {
        printf("BAD\n");
    } else {
        printf("GOOD\n");
    }

    return 0;
}

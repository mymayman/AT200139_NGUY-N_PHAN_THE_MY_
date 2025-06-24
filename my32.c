

#include <stdio.h>
#include <string.h>

int tientohauto(char *s) {
    int len = strlen(s);

    for (int l = len / 2; l >= 1; l--) {
        int match = 1;
        for (int i = 0; i < l; i++) {
            if (s[i] != s[len - l + i]) {
                match = 0;
                break;
            }
        }
        if (match)
            return l;
    }

    return 0;
}

int main() {
    char s[1001];
    scanf("%s", s);
    int result = tientohauto(s);
    printf("%d\n", result);
    return 0;
}

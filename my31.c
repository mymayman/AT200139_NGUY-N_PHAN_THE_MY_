#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRepeat(char *s) {
    int len = strlen(s);
    for (int i = 1; i <= len / 2; i++) {
        if (len % i != 0)
            continue;
        
        bool match = true;
        for (int j = i; j < len; j++) {
            if (s[j] != s[j % i]) {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }
    return false;
}

int main() {
    char s[1001];
    scanf("%s", s);

    if (isRepeat(s))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

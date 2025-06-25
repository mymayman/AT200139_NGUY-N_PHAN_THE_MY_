#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool match(const char *query, const char *pattern) {
    int i = 0, j = 0;
    while (query[i]) {
        if (j < strlen(pattern) && query[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (isupper(query[i])) return false;
            i++;
        }
    }
    return j == strlen(pattern);
}

int main() {
    int n;
    scanf("%d", &n);
    char queries[n][110]; 
    char pattern[110];

    for (int i = 0; i < n; i++) {
        scanf("%s", queries[i]);
    }
    scanf("%s", pattern);

    for (int i = 0; i < n; i++) {
        if (match(queries[i], pattern))
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}

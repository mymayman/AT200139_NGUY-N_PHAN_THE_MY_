#include <stdio.h>
#include <string.h>

int is_substring(const char *sequence, const char *sub) {
    return strstr(sequence, sub) != NULL;
}

int main() {
    char sequence[1001];
    char word[1001];
    scanf("%s", sequence);
    scanf("%s", word);

    char repeated[10001] = "";
    int k = 0;

    while (1) {
        strcat(repeated, word);
        if (is_substring(sequence, repeated)) {
            k++;
        } else {
            break;
        }
    }

    printf("%d\n", k);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char sentence[256];
    char searchWord[100];
    fgets(sentence, sizeof(sentence), stdin);
    scanf("%s", searchWord);

    int wordIndex = 1;
    int foundIndex = -1;
    char *word = strtok(sentence, " \n");

    while (word != NULL) {
        if (strstr(word, searchWord) == word) {
            foundIndex = wordIndex;
            break;
        }
        word = strtok(NULL, " \n");
        wordIndex++;
    }
    printf("%d\n", foundIndex);

    return 0;
}
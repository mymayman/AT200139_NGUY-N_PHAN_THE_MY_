#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canRotateTo(char *s, char *goal) {
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    if (len_s != len_goal) return false;

    char doubled[2 * len_s + 1];
    strcpy(doubled, s);
    strcat(doubled, s);
    return strstr(doubled, goal) != NULL;
}

int main() {
    char s[101], goal[101];
    fgets(s, sizeof(s), stdin);
    fgets(goal, sizeof(goal), stdin);
    
    s[strcspn(s, "\n")] = '\0';
    goal[strcspn(goal, "\n")] = '\0';

    if (canRotateTo(s, goal)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

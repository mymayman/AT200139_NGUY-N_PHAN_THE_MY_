#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main() {
    char Aaa[1001];
    char Bbb[101];

    fgets(Aaa, sizeof(Aaa), stdin);
    fgets(Bbb, sizeof(Bbb), stdin);

    Aaa[strcspn(Aaa, "\n")] = '\0';
    Bbb[strcspn(Bbb, "\n")] = '\0';

    int len_A = strlen(Aaa);
    int len_B = strlen(Bbb);

    for (int i = 0; i <= len_A - len_B; i++) {
        if (strncmp(&Aaa[i], Bbb, len_B) == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}

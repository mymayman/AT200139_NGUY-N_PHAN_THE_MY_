#include <stdio.h>
#include <string.h>

int demchuoi(char *s) {
    int count = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (s[i] == s[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    char s[100];
    printf("Nhap chuoi: ");
    scanf("%s", s);

    int result = demchuoi(s);
    printf("So chuoi con thoa man: %d\n", result);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Hàm kiểm tra xem chuỗi mẫu P có khớp với chuỗi S từ vị trí i trở đi
bool match(const char *s, const char *p) {
    if (*p == '\0') return *s == '\0';

    if (*p == '*') {
        // Dấu '*' có thể khớp với 0 hoặc nhiều ký tự
        return match(s, p + 1) || (*s && match(s + 1, p));
    } else if (*p == '?' || *p == *s) {
        // '?' khớp với bất kỳ ký tự đơn nào, hoặc ký tự khớp chính xác
        return *s && match(s + 1, p + 1);
    } else {
        return false;
    }
}

// Hàm chính kiểm tra chuỗi mẫu P có xuất hiện trong chuỗi S không
bool isPatternInText(const char *s, const char *p) {
    int len = strlen(s);
    for (int i = 0; i <= len; i++) {
        if (match(s + i, p))
            return true;
    }
    return false;
}

int main() {
    char S[1000], P[1000];
    fgets(S, sizeof(S), stdin);
    fgets(P, sizeof(P), stdin);

    // Xóa ký tự xuống dòng nếu có
    S[strcspn(S, "\n")] = '\0';
    P[strcspn(P, "\n")] = '\0';

    if (isPatternInText(S, P))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

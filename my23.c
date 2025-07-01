#include <stdio.h>
#include <string.h>

int main() {
    char s[10001];  // Chuỗi đầu vào (tối đa 10,000 ký tự + 1 ký tự '\0')
    scanf("%s", s); // Nhập chuỗi từ bàn phím

    int len = strlen(s);  // Tính độ dài chuỗi
    int count = 0;        // Biến đếm số mẫu hợp lệ

    // Duyệt từng ký tự trong chuỗi
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {        // Nếu gặp ký tự '1'
            int j = i + 1;

            // Kiểm tra nếu ngay sau đó là ít nhất một '0'
            if (j < len && s[j] == '0') {
                while (j < len && s[j] == '0') {
                    j++;          // Đi qua tất cả các ký tự '0' liên tiếp
                }

                // Sau dãy '0' phải là một '1' thì mới tính là mẫu hợp lệ
                if (j < len && s[j] == '1') {
                    count++;      // Tăng số mẫu tìm được
                    i = j - 1;    // Cập nhật i để tránh trùng lặp mẫu
                }
            }
        }
    }

    printf("%d\n", count);  // In kết quả
    return 0;
}
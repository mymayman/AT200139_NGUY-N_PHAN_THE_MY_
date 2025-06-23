#include <stdio.h>
#include <string.h>

void xoaMauKhoiChuoi(char *chuoiGoc, const char *chuoiMau) {
    int doDaiMau = strlen(chuoiMau);
    char ketQua[10001];  
    int chiSo = 0;       

    for (int i = 0; chuoiGoc[i] != '\0'; ++i) {
        ketQua[chiSo++] = chuoiGoc[i];  
        if (chiSo >= doDaiMau && strncmp(ketQua + chiSo - doDaiMau, chuoiMau, doDaiMau) == 0) {
            chiSo -= doDaiMau;  
        }
    }

    ketQua[chiSo] = '\0';          
    strcpy(chuoiGoc, ketQua);    
}

int main() {
    char s[10001], t[101];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

   xoaMauKhoiChuoi(s, t);
    printf("%s\n", s);
    return 0;
}

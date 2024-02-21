#include <stdio.h>

int main() {
    char name[100]; // Khai báo một mảng kí tự đủ lớn để lưu trữ tên

    printf("Nhập tên của bạn: ");
    fgets(name, sizeof(name), stdin); // Nhập một dòng văn bản từ stdin

    printf("Tên của bạn là: %s\n", name);

    return 0;
}

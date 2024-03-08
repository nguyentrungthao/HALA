/*

*/
#include <stdio.h>

#define PRINT(...) printf("%s\r\n", __VA_ARGS__)
#define CHUYEN_THANH_CHUOI(x) #x
#define GHEP_CHUOI(a, b) (a)##(b)

int main() {

    print(CHUYEN_THANH_CHUOI(GHEP_CHUOI(chao, Thao))); //? làm sao để chạy GHEP_CHUOI trước
    print(CHUYEN_THANH_CHUOI(chao));
    print("hello");
    
    return 0;
}


/*
#include <stdio.h>

#define GHEP_CHUOI(a, b) a##b
#define LEVEL_GHEPCHUOI(a, b) GHEP_CHUOI(a, b)
#define CHUYENCHUOI(x) #x
#define LEVEL_CHUYENCHUOI(x) CHUYENCHUOI(x)
#define chuoiChao hello

// Kết hợp chuỗi "a" và "b" thành "ab"
#define KET_HOP_CHUOI(a, b) a##b

// Chuyển biến thành chuỗi
#define CHUYEN_THANH_CHUOI(x) LEVEL_CHUYENCHUOI(x)

int main() {
    // In ngày biên dịch và thời gian biên dịch
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);

    // Kết hợp chuỗi "hello" và "a" thành "helloa"
    printf("%s\n", CHUYEN_THANH_CHUOI(KET_HOP_CHUOI(chuoiChao, a)));

    // Kết hợp chuỗi "a" với ngày và thời gian biên dịch
    printf("%s\n", CHUYEN_THANH_CHUOI(KET_HOP_CHUOI(a, KET_HOP_CHUOI(__DATE__, __TIME__))));

    return 0;
}

*/
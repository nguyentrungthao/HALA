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



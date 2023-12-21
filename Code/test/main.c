#include "lib.h"
#include <stdio.h>

#define PRINT(...) printf("%s\r\n", __VA_ARGS__)
#define CHUYEN_THANH_CHUOI(x) #x
#define GHEP_CHUOI(a, b) (a)##(b)

int main() {


    PRINT(CHUYEN_THANH_CHUOI(GHEP_CHUOI(chao, Thao)));
    PRINT(CHUYEN_THANH_CHUOI(chao));
    PRINT("hello");

    return 0;
}

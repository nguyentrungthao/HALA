#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdint.h>


/*
* @brief

*

*/
// int main() {
//     int* ptr = (int*)malloc(sizeof(int));
//     printf("ptr: %p\n", ptr);

//     int* ptr1 = (int*)malloc(sizeof(int));
//     printf("ptr1: %p\n", ptr1);
//     printf("------------\n");

//     ptr = (int*)realloc(ptr, 8);
//     for (uint8_t i = 0; i < 8; i++) {
//         printf("ptr: %p\n", ptr + i);
//     }
//     printf("------------\n");

//     // int* ptr2 = (int*)malloc(sizeof(int));
//     // printf("ptr2: %p\n", ptr2);

//     // free(ptr);
//     // free(ptr1);
//     // free(ptr2);

//     return 0;
// }

// #include <stdio.h>

// #define PRINT(...) printf("%s\r\n", __VA_ARGS__)
// #define leverUp(x) CHUYEN_THANH_CHUOI(x)
// #define CHUYEN_THANH_CHUOI(x) #x
// #define GHEP_CHUOI(a, b) a##b

// int main() {

//     PRINT(leverUp(GHEP_CHUOI(chao, Thao)));
//     PRINT(CHUYEN_THANH_CHUOI(chao));
//     PRINT("hello");

//     return 0;
// }


int main() {

    printf("%f", .01);
}

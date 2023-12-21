#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <setjmp.h>

//? --------------------------------------làm sao giấu những biến này đi-------------------------------------- 
jmp_buf buf; //static 
int exception_code; //extern 
char error_message[50]; //? làm sao để chuỗi lỗi ko giới hạn ?
//? --------------------------------------làm sao giấu những biến này đi-------------------------------------- 


#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, err_mess) do{ \
                        strncpy(error_message, err_mess, 50);\
                        longjmp(buf, (x));\
                        }while (0)

typedef enum {
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
} ErrorCodes;

void readFile() {
    printf("doc file \n");
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        THROW(FILE_ERROR, "loi doc file: file khong ton tai\r\n");
    }
    fclose(file);
    printf("hoan thanh doc file\r\n");
}

void networkOperation() {
    printf("ket noi mang \n");
    THROW(NETWORK_ERROR, "loi mang: khong the ket noi mang\r\n");
    THROW(NETWORK_ERROR, "loi duong dan: duong dan khong ton tai\r\n");
    printf("ngat ket noi mang\n");
}

void calculateData() {
    THROW(CALCULATION_ERROR, "loi tinh data: tham so dau vao khong hop le \r\n");
    THROW(CALCULATION_ERROR, "loi tinh data: phep tinh khong hop le\r\n");
}

int main() {

    TRY{
       readFile();
       networkOperation();
       calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    } CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);
    } CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_message);
    }

    return 0;
}
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
    THROW(FILE_ERROR, "loi doc file: file khong ton tai");
}

void networkOperation() {

}

void calculateData() {

}

int main() {

    TRY{
       readFile();
       networkOperation();
       calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    } // Bổ sung thêm nhiều CATCH

    return 0;
}
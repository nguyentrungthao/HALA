/*
*Mục tiêu:
Sửa đổi hàm THROW để nó chấp nhận một thông điệp lỗi dưới dạng chuỗi ký tự, bên cạnh mã lỗi.
Thông điệp lỗi nên được lưu trữ ở một nơi mà có thể truy cập được sau khi longjmp được gọi.

*Yêu cầu:
Sửa đổi hàm THROW trong chương trình C mẫu đã cho.
Hàm THROW phải có khả năng nhận một thông điệp lỗi dưới dạng chuỗi ký tự và một mã lỗi.
Thông điệp lỗi và mã lỗi phải được lưu trữ sao cho có thể được truy xuất từ khối CATCH.
Viết hàm hoặc các hàm thử nghiệm khác, mỗi hàm ném ra một loại lỗi khác nhau, sử dụng cải tiến hàm THROW.
Trong hàm main, xử lý các lỗi này một cách riêng biệt, in ra thông điệp lỗi tương ứng cho mỗi loại lỗi.
Ví dụ:
Thay vì bạn sử dụng đoạn mã sau:

double divide(int a, int b) {
   if (b == 0) {
       THROW(1); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   THROW(2); //Những lỗi khác
   return (double)a / b;
}

Được thay thế bằng:
double divide(int a, int b) {
   if (b == 0) {
       THROW(1, "Lỗi: Phép chia cho 0!"); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   THROW(2, "Lỗi: Những lỗi khác!");
   return (double)a / b;
}

Trong ví dụ này, mã lỗi 1 có thể tượng trưng cho lỗi chia cho 0, và chuỗi "Lỗi: Phép chia cho 0!" là thông điệp lỗi tương ứng.
Sau khi gọi THROW, khối CATCH(1) trong main sẽ xử lý lỗi này và in ra thông điệp lỗi.
Thay vì bạn sử dụng đoạn mã sau:
CATCH(1) {
       printf("Lỗi: Phép chia cho 0!\n");
}CATCH(2) {
       printf("Lỗi: Những lỗi khác!\n");
   }


Được thay thế bằng:
CATCH(1) {
       printf("%s\n", error_code)
}CATCH(2) {
       printf("%s\n", error_code)
}
*/

#include <stdio.h>
#include <setjmp.h>
#include <string.h>

#define DIV_BY_ZERO 1u

//? --------------------------------------làm sao giấu những biến này đi-------------------------------------- 
jmp_buf buf;
int exception_code;
char error_code[50]; //? làm sao để chuỗi lỗi ko giới hạn ?
//? --------------------------------------làm sao giấu những biến này đi-------------------------------------- 


#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, err_mess) do{ \
                        strncpy(error_code, err_mess, 50);\
                        longjmp(buf, (x));\
                        }while (0)



double divide(int a, int b) {
    if (b == 0) {
        THROW(DIV_BY_ZERO, "div by 0"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY{
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(DIV_BY_ZERO) {
        printf("err: %s\r\n", error_code);
    }


    // Các xử lý khác của chương trình
    return 0;
}

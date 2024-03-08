/*
https://docs.google.com/document/d/10WujC0g4BZAH2BYhA1Qsh5skTd8H_73JbPI_qhyq9fE/edit#heading=h.fdmv4mkokua5

Bài Tập Lớn: Quản Lý Thông Tin Cư Dân Chung Cư
Mục Tiêu
Phát triển một chương trình bằng C để quản lý thông tin cư dân trong chung cư, bao gồm các chức năng cơ bản: thêm, xóa, chỉnh sửa và tìm kiếm thông tin cư dân. Chương trình này sẽ giúp quản lý cư dân một cách hiệu quả và chính xác, đảm bảo dữ liệu được cập nhật và truy xuất một cách nhanh chóng.

Cấu Trúc Dữ Liệu
Member:
Mô tả: Cấu trúc để lưu trữ thông tin cơ bản của cư dân.
Trường thông tin: UID của RFID, số phòng, tên, biển số xe.

Ví dụ Code:
typedef struct {
 char uid[20]; // UID của RFID
 char roomNumber[10]; // Số Phòng
 char name[50]; // Tên
 char licensePlate[20]; // Biển Số Xe
} Member;

MemberNode:
Mô tả: Node trong linked list chứa thông tin Member.
Trường thông tin: Dữ liệu Member, con trỏ đến MemberNode tiếp theo.
Ví dụ Code:
Định nghĩa cấu trúc MemberNode
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

Hàm tạo một MemberNode mới
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}


Các Chức Năng Chính
Thêm Thành Viên (Add Member):
Mô tả: Ghi thông tin mới của thành viên vào cuối file CSV.
Đầu vào: Member mới.
Đầu ra: File CSV cập nhật.
Ví dụ:
void addMember(const char* filename, Member member)

Xóa Thành Viên (Delete Member):
Mô tả: Xóa thông tin của thành viên dựa trên UID từ file CSV.
Đầu vào: UID của thành viên cần xóa.
Đầu ra: File CSV cập nhật.
Ví dụ:
void deleteMember(const char* filename, const char* uid)

Chỉnh Sửa Thông Tin Thành Viên (Edit Member):
Mô tả: Cập nhật thông tin của thành viên dựa trên UID trong file CSV.
Đầu vào: Member cập nhật và UID.
Đầu ra: File CSV cập nhật.
Ví dụ:
void editMember(const char* filename, Member updatedMember)

Tìm Kiếm Thông Tin Thành Viên (Search Member):
Mô tả: Tìm kiếm thông tin thành viên dựa trên UID hoặc biển số xe.
Đầu vào: Giá trị tìm kiếm và tiêu chí (UID/Biển số xe).
Đầu ra: Thông tin tìm được hoặc thông báo không tìm thấy.
Ví dụ:
int searchByUID(const Member* member, const char* uid)

int searchByLicensePlate(const Member* member, const char* licensePlate)
Member searchMember(const char* filename, const char* searchValue, SearchFunction searchFunc)


Bổ Sung
Định Dạng File CSV: Đảm bảo file CSV tuân thủ định dạng đã quy định với các cột là UID của RFID, Số Phòng, Tên, và Biển Số Xe.
UID của RFID: Chuỗi ký tự độc nhất định danh cho mỗi cư dân.
Số Phòng: Mã số phòng của cư dân.
Tên: Tên đầy đủ của cư dân.
Biển Số Xe: Biển số xe (nếu có) của cư dân.
Ví Dụ
Một ví dụ về dòng dữ liệu trong file CSV:
uID,roomNumber,name,licensePlates
123456789,A-101,Nguyễn Văn A,51F-123.45


Trong đó:
123456789 là UID của RFID.
A-101 là số phòng.
Nguyễn Văn A là tên của cư dân.
51F-123.45 là biển số xe.
Tính Mở Rộng: Cấu trúc chương trình cần cho phép dễ dàng mở rộng thêm chức năng hoặc cấu trúc dữ liệu mới.
Tính Mở Rộng: Cấu trúc chương trình cần cho phép dễ dàng mở rộng thêm chức năng hoặc cấu trúc dữ liệu mới.

*/

#include <stdio.h>
#include <string.h>
#include "./include/LinkList.h"
#include "./include/Member.h"

#define FILE_NAME "./data/data.csv"
#define REMOVE_ENDLINE_STDIN()     do {\
                            char c;\
                            while ((c = getchar()) != '\n' && c != EOF);\
                            } while (0) 

typedef enum {
    add_member,
    delete_member,
    find_UID_member,
    find_licensePlates_member,
    update_member,
    out
} Choose_t;

void printData(Member data);
void printList(node* list);
Member enterData();

int main(int argc, char const* argv[]) {
    node* list = NULL;
    char searchValue[20];
    char deleteUID[20];
    Choose_t choose = 1;
    initData(FILE_NAME, &list);

    while (choose != 5) {
        printf("\nMenu:\n");
        printf("0 - Add member\n");
        printf("1 - Delete member\n");
        printf("2 - Search by UID\n");
        printf("3 - Search by license plate\n");
        printf("4 - Update member\n");
        printf("5 - Exit\n");
        printf("Choose: ");
        scanf("%d", &choose); //! Nhập chế độ này hơi sai do kiểu int chứ ko phải enum

        switch (choose) {
        case add_member: {
            Member newMember;
            printf("Enter information for the new member:\n");
            newMember = enterData();

            addMember(FILE_NAME, &list, newMember);
            printf("Member has been added.\n");
            break;
        }
        case delete_member: {
            printf("Enter the UID of the member to delete: ");
            scanf("%s", deleteUID);
            REMOVE_ENDLINE_STDIN();
            printf("%s\r\n", deleteUID);
            deleteMember(FILE_NAME, &list, deleteUID);
            break;
        }
        case find_UID_member: {
            printf("Enter the UID to search: ");
            scanf("%s", searchValue);
            REMOVE_ENDLINE_STDIN();

            int pos = searchMember(list, searchValue, searchByUID);
            if (pos > -1) {
                printf("member:\r\n");
                printData(get(list, pos));
            }
            else {
                printf("member does not exist\r\n");
            }
            break;
        }
        case find_licensePlates_member: {
            printf("Enter the license plate to search: ");
            scanf("%s", searchValue);
            REMOVE_ENDLINE_STDIN();

            int pos = searchMember(list, searchValue, searchByLicensePlate);
            if (pos > -1) {
                printf("member:\r\n");
                printData(get(list, pos));
            }
            else {
                printf("member does not exist\r\n");
            }
            break;
        }
        case update_member: {
            Member updatedMember;
            printf("Enter the UID of the member to update: ");
            scanf("%s", updatedMember.uid);
            REMOVE_ENDLINE_STDIN();

            int pos = searchMember(list, updatedMember.uid, searchByUID);
            if (pos > -1) {
                printf("Enter the new information:\n");
                updatedMember = enterData();

                editMember(FILE_NAME, &list, pos, updatedMember);
                printf("Member information has been updated.\n");
            }
            else {
                printf("no member update\r\n");
            }

            break;
        }
        case out:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please choose again.\r\n");
            break;
        }
    }
    saveData(FILE_NAME, list);

    return 0;
}


void printData(Member data) {
    printf("uid: %s\r\n", data.uid);
    printf("roomNumber: %s\r\n", data.roomNumber);
    printf("name: %s\r\n", data.name);
    printf("licensePlate: %s\r\n", data.licensePlate);
}
void printList(node* list) {
    node* p;
    p = list;

    //* kiểm tra đã có phần tử nào chưa 
    if (empty(p) == EMPTY) {
        printf("list empty\r\n");
        return;
    }

    while (p->next != NULL)    // free the last node in the list
    {
        printData(p->member);
        printf("-----------\r\n");
        p = p->next;
    }
    printData(p->member);
    printf("-----------\r\n");

}

Member enterData() {
    Member member;

    printf("UID: ");
    scanf("%s", member.uid);
    REMOVE_ENDLINE_STDIN();

    printf("Room Number: ");
    scanf("%s", member.roomNumber);
    REMOVE_ENDLINE_STDIN();

    printf("Name: ");
    fgets(member.name, sizeof(member.name), stdin);
    member.name[strcspn(member.name, "\n")] = '\0';

    printf("License Plate: ");
    fgets(member.licensePlate, sizeof(member.licensePlate), stdin);
    member.licensePlate[strcspn(member.licensePlate, "\n")] = '\0';

    return member;
}


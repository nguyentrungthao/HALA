#include "../include/LinkList.h"


/// @brief create new node with data input  
/// @param value: data struct 
/// @return a new node with data input if success
//           NULL if run out of heap
node* createNode(Member value) {
    node* ptr = (node*)malloc(sizeof(node));

    if (ptr == NULL) {
        printf("\tOUT OF MEMORY\r\n");
        return NULL;
    }

    strncpy(ptr->member.uid, value.uid, NUMBER_CHARACTER_OF_UID - 1);
    strncpy(ptr->member.name, value.name, NUMBER_CHARACTER_OF_NAME - 1);
    strncpy(ptr->member.roomNumber, value.roomNumber, NUMBER_CHARACTER_OF_ROOM - 1);
    strncpy(ptr->member.licensePlate, value.licensePlate, NUMBER_CHARACTER_OF_LICENSE_PLATE - 1);
    ptr->next = NULL;

    return ptr;
}

/// @brief create new node   
/// @param array: 
/// @param value:          
/// @return none
void pushBack(node** array, Member value)
{
    node* temp;
    temp = createNode(value); // khoi tao node

    if (*array == NULL)   // if array doesn't have any node yet
    {
        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}


void pushFront(node** array, Member value) { // them 1 node vao phia truoc
    node* temp;
    temp = createNode(value); // khoi tao node

    if (*array == NULL)
    {
        (*array) = temp;
    }
    else
    {
        node* ptr = *array; //* tạo con trỏ tạm để lưu 
        *array = temp; //* con trỏ đầu mảng thay thành biến mới 
        (*array)->next = ptr; //* con trỏ của node mới sẽ trỏ đến giá trị đã lưu trước đó 

    }
}

void popBack(node** array)
{
    node* p;
    p = *array;

    //* kiểm tra đã có phần tử nào chưa 
    if (empty(p) == EMPTY) {
        printf("list empty\r\n");
        return;
    }
    //* nếu chỉ có 1 phần tử 
    if (p->next == NULL) {
        *array = NULL;
        free(p);
        return;
    }

    //* p->next->next: cần thao tác với node kề cuối trước khi giải phóng
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    p = p->next;

    free(p);
}

void popFront(node** array) { // xoa node dau tien
    node* p;
    p = *array;

    //* kiểm tra đã có phần tử nào chưa 
    if (empty(p) == EMPTY) {
        printf("list empty\r\n");
        return;
    }

    (*array) = p->next;
    free(p);
}

Member front(node* array) {
    //* kiểm tra đã có phần tử nào chưa 
    if (empty(array) == EMPTY) {
        Member nullValue = {
            .uid = "null",
            .roomNumber = "null",
            .name = "null",
            .licensePlate = "null",
        };
        return nullValue;
    }

    return array->member;
}

Member back(node* array) {
    node* p;
    p = array;

    //* check 
    if (empty(array) == EMPTY) {
        Member nullValue = {
            .uid = "null",
            .roomNumber = "null",
            .name = "null",
            .licensePlate = "null",
        };
        return nullValue;
    }

    while (p->next != NULL)     // free the last node in the list
    {
        p = p->next;
    }

    return p->member;
}

void insert(node** array, Member value, int pos) {
    node* p;
    int i = 0;
    p = *array;

    //* check 
    if (empty(p) == EMPTY) {
        if (pos == 0) {
            pushBack(array, value);
        }
        else {
            printf("list empty\r\n");
        }

        return;
    }

    while (p->next != NULL && pos - 1 != i) {
        p = p->next;
        i++;
    }

    i++;
    if (pos == i) {
        node* temp = createNode(value);
        temp->next = p->next;
        p->next = temp;
    }
    else {
        printf("Error: List has less element\n");
    }

}

void delete(node** array, int pos) {
    node* p, temp;
    int i = 0;
    p = *array;

    //* check 
    if (empty(p) == EMPTY) {
        printf("list empty\r\n");
        return;
    }

    if (pos == 0) {
        popFront(array);
        return;
    }

    while (p->next->next != NULL && pos - 1 != i) {
        p = p->next;
        i++;
    }
    i++;

    if (pos == i) {
        node* temp;
        temp = p->next;
        p->next = temp->next;

        free(temp);
    }
    else {
        printf("Error: List has less element\n");
    }
}

int size(node** array) {
    node* p, * temp;
    p = *array;
    int i = 0;

    //* check 
    if (empty(p) == EMPTY) {
        return 0;
    }

    while (p->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }

    i++;
    return i;
}

Member get(node* array, int pos) {
    int i = 0;
    Member nullValue = {
        .uid = "null",
        .roomNumber = "null",
        .name = "null",
        .licensePlate = "null",
    };

    //* check 
    if (empty(array) == EMPTY) {
        printf("list empty\r\n");
        return nullValue;
    }

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return nullValue;
    }

    Member value = array->member;
    return value;
}

bool empty(node* array) {
    if ((array) == NULL) {
        return EMPTY;
    }
    return NOT_EMPTY;
}
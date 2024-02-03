#include "LinkList.h"

node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
    // temp = 0xa1


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


void push_front(node** array, int value) { // them 1 node vao phia truoc
    node* temp;
    temp = createNode(value); // khoi tao node
    // temp = 0xa1

    if (*array == NULL)   
    {
        //* nếu chưa có node nào thì để nó ở đầu và con trỏ tiếp theo chưa có địa chỉ 
        (*array) = temp;
        (*array)->next = NULL;
    }
    else                
    {
        //* nếu có rồi 
        node* ptr = *array; //* tạo con trỏ tạm để lưu 
        *array = temp; //* con trỏ đầu mảng thay thành biến mới 
        (*array)->next = ptr->next; //* con trỏ của node mới sẽ trỏ đến giá trị đã lưu trước đó 

    }
}

void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}

void pop_front(node** array) { // xoa node dau tien
    node* p;
    p = *array;
    int i = 0; 

    //* kiểm tra đã có phần tử nào chưa 
    if (p == NULL) {
        return;
    }

    (*array) = (*array)->next;

    free(p);
}

int front(node** array) {
    return (*array)->value;
}

int back(node** array) {
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;

    return temp->value;
}

void insert(node** array, int value, int pos) {
    
}

void delete(node** array, int pos) {
    
}

int size(node** array) {
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;

    i++;
    return i;
}

int get(node* array, int pos)
{
    int i = 0;

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

bool empty(node** array) {
    
}
#include "LinkList.h"

node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(node** array, int value);

void push_front(node** array, int value); // them 1 node vao phia truoc
void pop_back(node** array);
void pop_front(node** array); // xoa node dau tien
int front(node** array); // lay gia tri cua node dau tien
int back(node** array); // lay gia tri cua node cuoi cung
void insert(node** array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node** array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node** array); // lay kich thuoc cua list
int get(node** array, int pos);
bool empty(node** array); // kiem tra list co rong hay khong
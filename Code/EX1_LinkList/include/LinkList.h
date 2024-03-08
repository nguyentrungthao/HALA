/*

*/
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_CHARACTER_OF_UID 20
#define NUMBER_CHARACTER_OF_ROOM 10
#define NUMBER_CHARACTER_OF_NAME 50
#define NUMBER_CHARACTER_OF_LICENSE_PLATE 20

#define EMPTY true
#define NOT_EMPTY false 

typedef struct {
    char uid[NUMBER_CHARACTER_OF_UID]; // UID của RFID
    char roomNumber[NUMBER_CHARACTER_OF_ROOM]; // Số Phòng
    char name[NUMBER_CHARACTER_OF_NAME]; // Tên
    char licensePlate[NUMBER_CHARACTER_OF_LICENSE_PLATE]; // Biển Số Xe
} Member;

typedef struct node
{
    Member member;
    struct node* next;
}node;

node* createNode(Member value);
void pushBack(node** array, Member value);
void pushFront(node** array, Member value); // them 1 node vao phia truoc
void popBack(node** array);
void popFront(node** array); // xoa node dau tien
Member front(node* array); // lay gia tri cua node dau tien
Member back(node* array); // lay gia tri cua node cuoi cung
void insert(node** array, Member value, int pos); // them 1 node vao mot vi tri bat ky
void delete(node** array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node** array); // lay kich thuoc cua list
Member get(node* array, int pos);
bool empty(node* array); // kiem tra list co rong hay khong

#endif //LINK_LIST_H

#ifndef MEMBER_H
#define MEMBER_H

#include <stdint.h>
#include <stdbool.h>
#include "LinkList.h"

#define CHECK_NULL(ptr, notice) do{if(ptr == NULL){ \
                                printf(notice); \
                                return;} \
                                }while(0)
typedef bool (*SearchFunction)(const Member member, const char* uid);

void initData(const char* filename, node** list);
void saveData(const char* filename, node* list);

void addMember(const char* filename, node** list, Member member);
void deleteMember(const char* filename, node** list, const char* uid);
void editMember(const char* filename, node** list, int pos, Member updatedMember);
bool searchByUID(const Member member, const char* uid);
bool searchByLicensePlate(const Member member, const char* licensePlate);
int searchMember(node* list, const char* searchValue, SearchFunction searchFunc);

#endif //MEMBER_H 
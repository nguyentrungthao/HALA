#include "../include/Member.h"

/// @brief Get data from file into list
/// @param filename file data
/// @param list linklist
/// @return none
void initData(const char* filename, node** list) {
    FILE* file = fopen(filename, "r");
    Member data;

    CHECK_NULL(file, "Unable to open CSV file\r\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* token = strtok(buffer, ",");
        char arrData[4][256];
        int i = 0;

        while (token != NULL) {
            strncpy(arrData[i++], token, 255);
            token = strtok(NULL, ",");
        }

        strncpy(data.uid, arrData[0], NUMBER_CHARACTER_OF_UID - 1);
        strncpy(data.roomNumber, arrData[1], NUMBER_CHARACTER_OF_ROOM - 1);
        strncpy(data.name, arrData[2], NUMBER_CHARACTER_OF_NAME - 1);

        arrData[3][strcspn(arrData[3], "\n")] = '\0';
        strncpy(data.licensePlate, arrData[3], NUMBER_CHARACTER_OF_LICENSE_PLATE - 1);
        pushBack(list, data);
        printf("add new member\r\n");
        i = 0;
    }
    fclose(file);

}

/// @brief update data from list into file
/// @param filename file data
/// @param list linklist
/// @return none
void saveData(const char* filename, node* list) {
    FILE* file = fopen(filename, "w");
    Member data;

    CHECK_NULL(file, "Unable to open CSV file\r\n");
    CHECK_NULL(list, "empty list\r\n");

    node* p;
    p = list;
    while (p->next != NULL)
    {
        fprintf(file, "%s,%s,%s,%s\r\n", p->member.uid, p->member.roomNumber, p->member.name, p->member.licensePlate);
        p = p->next;
    }
    fclose(file);
}

/// @brief add new member to list and data file
/// @param filename file data
/// @param list linklist
/// @param member data for new member 
/// @return none
void addMember(const char* filename, node** list, Member member) {
    FILE* file = fopen(filename, "a");

    CHECK_NULL(file, "Unable to open CSV file\r\n");

    fprintf(file, "%s,%s,%s,%s\r\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);

    pushBack(list, member);
}

/// @brief add member from list and data file
/// @param filename file data
/// @param list linklist
/// @param uid UID of member 
/// @return none
void deleteMember(const char* filename, node** list, const char* uid) {

    CHECK_NULL(filename, "Unable to open CSV file\r\n");
    CHECK_NULL(list, "empty list\r\n");

    int pos = searchMember(*list, uid, searchByUID);
    
    if (pos > -1) {
        delete(list, pos);
        saveData(filename, *list);
    }
}

/// @brief edit member from list and data file
/// @param filename file data
/// @param list linklist
/// @param pos position of member
/// @param updatedMember new data for member
/// @return none
void editMember(const char* filename, node** list, int pos, Member updatedMember) {

    CHECK_NULL(filename, "Unable to open CSV file\r\n");
    CHECK_NULL(list, "empty list\r\n");

    delete(list, pos);
    insert(list, updatedMember, pos);
    
    saveData(filename, *list);
}

/// @brief compare member's UID
/// @param member members need to be compared 
/// @param uid UID 
/// @return member exists or not
bool searchByUID(const Member member, const char* uid) {
    return strcmp(member.uid, uid) == 0 ? true : false;
}

/// @brief compare member's LicensePlate
/// @param member members need to be compared 
/// @param licensePlate licensePlate 
/// @return member exists or not
bool searchByLicensePlate(const Member member, const char* licensePlate) {
    return strcmp(member.licensePlate, licensePlate) == 0 ? true : false;
}
/// @brief Browse the list and find members
/// @param list linkList
/// @param searchValue search content
/// @param searchFunc function seach
/// @return postion of member 
int searchMember(node* list, const char* searchValue, SearchFunction searchFunc) {
    node* p;
    p = list;
    int pos = 0;
    
    while (p->next != NULL)
    {
        if (searchFunc(p->member, searchValue) == true) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    if (searchFunc(p->member, searchValue) == true) {
        return pos;
    }

    return -1;
}



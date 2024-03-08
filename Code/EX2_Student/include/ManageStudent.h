
#ifndef MANAGE_STUDENT_H
#define MANAGE_STUDENT_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "Student.h"


#define CHECK_PRAM(condition, notice, status) do{if(condition){ \
                                std::cout << notice; \
                                return status;} \
                                }while(0)

class ManageStudent : public Student {
public:
    typedef void* TypeOfSort(void);

    ManageStudent(std::string fileName);
    ManageStudent();
    ~ManageStudent();

    Status initData();
    Status addStudent(Student newStudent);
    Status changeStudent(std::string ID, Student Student);
    Status deteleStudent(std::string ID);
    void findStudentbyName(std::string value);
    void findStudentbyID(std::string value);
    void printListStudent();
    void printStudent(Student student);
    void saveListToFile();

    void changeFileName(std::string newFileName);
    std::string getFileName() ;

private:
    int sortByName(const Student& student1, const Student& student2);
    int sortByID(const Student& student1, const Student& student2);
    std::string fileName;
    std::ifstream file;
    std::list<Student> listSortByNameStudent;
    std::list<Student> listSortByIDStudent;

};

#endif //MANAGE_STUDENT_H
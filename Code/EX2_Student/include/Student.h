#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <list>

enum Status {
    success = 0,
    errorData = 1,
};

class Student
{

public:
    enum class Gender {
        male = 1,
        female = 2
    };

    Student(std::string _ID, std::string _name, uint8_t _age, Gender _gender, uint8_t _math, uint8_t _physical, uint8_t _chemistry);
    Student();
    ~Student();

    Status addInfomation(std::string _ID, std::string _name, uint8_t _age, Gender _gender, uint8_t _math, uint8_t _physical, uint8_t _chemistry);

    Status addID(std::string _ID);
    Status addName(std::string _name);
    Status addGender(Gender _name);
    Status addAge(uint8_t _name);
    Status addMath(uint8_t _math);
    Status addPhysical(uint8_t _physical);
    Status addchemistry(uint8_t _chemistry);

    std::string getID() const;
    std::string getName() const;

    void printData();
private:
    std::string ID, name;
    Gender gender;
    uint8_t age, math, physical, chemistry;
};

#endif //STUDENT_H


/*

*/

#include "../include/Student.h"

Student::Student(std::string _ID, std::string _name, uint8_t _age, Gender _gender, uint8_t _math, uint8_t _physical, uint8_t _chemistry) {
    // this->name = _name;
    // this->age = _age;
    // this->gender = _gender;
    // this->math = _math;
    // this->physical = _physical;
    // this->chemistry = _chemistry;
}
Student::Student() {

}

Student::~Student() {
    std::cout << "Remove Student\n";
}

Status Student::addInfomation(std::string _ID, std::string _name, uint8_t _age, Gender _gender, uint8_t _math, uint8_t _physical, uint8_t _chemistry) {
    if (_ID.empty() == true) {
        return errorData;
    }
    if (_name.empty() == true) {
        return errorData;
    }
    if (_gender != Gender::male || _gender != Gender::female) {
        return errorData;
    }
    if (_math > 10 || _physical > 10 || _chemistry > 10) {
        return errorData;
    }

    this->ID = _ID;
    this->name = _name;
    this->age = _age;
    this->gender = _gender;
    this->math = _math;
    this->physical = _physical;
    this->chemistry = _chemistry;

    return success;
}
Status Student::addID(std::string _ID) {
    if (_ID.empty() == true) {
        return errorData;
    }

    this->ID = _ID;
    return success;
}
Status Student::addName(std::string _name) {
    if (_name.empty() == true) {
        return errorData;
    }

    this->name = _name;
    return success;
}
Status Student::addGender(Gender _gender) {
    if (_gender != Gender::male || _gender != Gender::female) {
        return errorData;
    }

    this->gender = _gender;
    return success;
}
Status Student::addAge(uint8_t _age) {
    this->age = _age;
    return success;
}
Status Student::addMath(uint8_t _math) {
    if (_math > 10) {
        return errorData;
    }
    this->math = _math;

    return success;
}
Status Student::addPhysical(uint8_t _physical) {
    if (_physical > 10) {
        return errorData;
    }
    this->physical = _physical;

    return success;
}
Status Student::addchemistry(uint8_t _chemistry) {
    if (_chemistry > 10) {
        return errorData;
    }
    this->chemistry = _chemistry;

    return success;
}
std::string Student::getID() const {
    return ID;
}
std::string Student::getName() const {
    return name;
}


void Student::printData() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "ten: " << name << std::endl;
    std::cout << "tuoi: " << age << std::endl;
    std::cout << "gioi tinh: " << ((gender == Gender::male) ? "male" : "female") << std::endl;
    std::cout << "Toan\tLy\tHoa\t\n";
    std::cout << math << "\t" << physical << "\t" << chemistry << std::endl;
    std::cout << "diem trung binh: " << (math + physical + chemistry) / 3 << std::endl;
}

#include "../include/ManageStudent.h"

/**
 *@brief Construct a new Manage Student:: Manage Student object
 *
 */
ManageStudent::ManageStudent() : Student() {

}

/**
 *@brief Construct a new Manage Student:: Manage Student object
 *
 * @param fileName path to get and save data
 */
ManageStudent::ManageStudent(std::string fileName) : Student() {
    //? có thể viết chương trình khởi tạo trong này không
    //? gọi hàm viết chương trình giống initData ở trong hàm này 
    this->fileName = fileName;
}

/**
 *@brief Destroy the Manage Student:: Manage Student object
 *
 */
ManageStudent::~ManageStudent() {
    //? hủy file file.close
}


/**
 *@brief get data student from data file
 *
 * @return Status
 */
Status ManageStudent::initData() {

    CHECK_PRAM(fileName.empty() == true, "no path to open file\n", errorData);

    /*
        *std::ios::in: Mở file để đọc.
        *std::ios::out : Mở file để ghi.Nếu file đã tồn tại, dữ liệu hiện có trong file sẽ bị ghi đè.
        *std::ios::app : Ghi vào cuối file.Nếu file không tồn tại, nó sẽ được tạo mới.
        *std::ios::ate : Mở file và di chuyển con trỏ đọc / ghi đến cuối file ngay sau khi mở.
        *std::ios::binary : Mở file trong chế độ nhị phân.
    */
    file.open(fileName, std::ios::in);
    CHECK_PRAM(!file.is_open(), "file is not exit\n", errorData);

    std::string line;
    while (std::getline(file, line)) { // Đọc từng dòng của file
        std::string arrData[7]; //? cách nào viết hay hơn để tự động chọn số 
        int i = 0;

        std::istringstream ss(line);
        std::string token;

        // Duyệt qua từng phần của chuỗi và in ra màn hình
        while (std::getline(ss, token, ',')) {
            std::cout << token << std::endl;
            arrData[i++] = token;
        }
        Student newStudent;

        newStudent.addID(arrData[0]);
        newStudent.addName(arrData[1]);
        newStudent.addAge((uint8_t)stoi(arrData[2]));

        Gender genderNewStudent = Gender::male;
        if (arrData[3] == "male") {
            genderNewStudent = Gender::male;
        }
        else if (arrData[3] == "female") {
            genderNewStudent = Gender::female;
        }
        else {
            //in ra thông tin lỗi của 
            std::cout << "error gender of student: " << arrData[0] << std::endl;
        }
        newStudent.addGender(genderNewStudent);
        newStudent.addMath((uint8_t)stoi(arrData[4]));
        newStudent.addPhysical((uint8_t)stoi(arrData[5]));
        newStudent.addchemistry((uint8_t)stoi(arrData[6]));

        listSortByNameStudent.push_back(newStudent);
        listSortByIDStudent.push_back(newStudent);
        //? tạo ra nhiều danh sách đã được sắp sếp nhằm tăng tốc độ tìm kiếm ?
        i = 0;
    }
    file.close(); // Đóng file

    listSortByIDStudent.sort(sortByID);
    listSortByNameStudent.sort(sortByName);

    return success;
}

/**
 *@brief add new member to list
 *
 * @param newStudent: data for new member
 * @return Status
 */
Status ManageStudent::addStudent(Student newStudent) {
    listSortByNameStudent.push_back(newStudent);
    listSortByIDStudent.push_back(newStudent);

    listSortByIDStudent.sort(sortByID);
    listSortByNameStudent.sort(sortByName);
    return success;
}

/**
 *@brief
 *
 * @param ID
 * @param Student
 * @return Status
 */
Status ManageStudent::changeStudent(std::string ID, Student Student) {
    // tìm sinh viên có ID


}
/**
 *@brief detele student front list
 *
 * @return Status
 */
Status ManageStudent::deteleStudent(std::string ID) {
    listSortByIDStudent.remove_if([ID](const Student& student) { return (student.getID()).compare(ID); });
}
/**
 *@brief find student
 *
 * @param value ID of student to find
 * @return Status
 */
void ManageStudent::findStudentbyID(std::string value) {
    int i = 0;
    // list<Student>::iterator it;
    // for (it = listSortByIDStudent.begin(); it != listSortByIDStudent.end(); ++it) {
    for (auto it = listSortByIDStudent.begin(); it != listSortByIDStudent.end(); ++it) {
        if (it->getID() == value) {
            it->printData();
            // return i;
        }
        i++;
    }
    // return -1;
}

/**
 *@brief find student
 *
 * @param value Name of student to find
 * @return Status
 */
void ManageStudent::findStudentbyName(std::string value) {
    for (auto it = listSortByNameStudent.begin(); it != listSortByNameStudent.end(); ++it) {
        if (it->getName() == value) {
            it->printData();
        }
    }
}
/**
 *@brief mentor support sort list by name
 *
 * @param student1
 * @param student2
 * @return int
 */
int ManageStudent::sortByName(const Student& student1, const Student& student2) {
    std::string name1 = student1.getName();
    std::string name2 = student2.getName();

    return name1.compare(name2);
}

/**
 *@brief mentor support sort list by age
 *
 * @param student1
 * @param student2
 * @return int
 */
int ManageStudent::sortByID(const Student& student1, const Student& student2) {
    std::string ID1 = student1.getID();
    std::string ID2 = student2.getID();

    return ID1.compare(ID2);
}

/**
 *@brief print total list data
 *
 */
void ManageStudent::printListStudent() {

}
/**
 *@brief
 *
 * @param student
 */
void ManageStudent::printStudent(Student student) {
    student.printData();
}
void ManageStudent::saveListToFile() {

}

void ManageStudent::changeFileName(std::string newFileName) {

}
std::string ManageStudent::getFileName() {

}
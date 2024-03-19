/*
    thực hiện các thao tác trên file data(lưu trữ danh mục sản phẩm)
    các thao tác:
        - đọc toàn bộ sản phẩm lưu vào cơ sở dữ liệu đang chạy
            (gồm nhiều vector chứa các danh mục sản phẩm)
        - thực hiện yêu cầu tìm sản phẩm in ra sản phẩm
        - thực hiện ghi dữ liệu sau khi thao tác
*/

#ifndef MANAGE_FILE_H
#define MANAGE_FILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>

#define SO_PHAN_TU_TRONG_STRUCT_DU_LIEU 3

//? đã tối ưu vùng nhớ chưa
struct ManageProduct {
    std::string name; // kích thước 24 byte 
    float unitPrice;
    int quantity;
};

class ManageFile {
private:

    std::string nameFile;
    std::ifstream file;
    std::vector<ManageProduct> data;

    void addNewMemBer(std::string arr[]);

public:
    ManageFile(std::string nameFile);

    bool seachName(ManageProduct product, std::string string);

    void initData();
    std::vector<int> seachData(std::string string, bool (*fnc)(ManageProduct product, std::string string));
    void saveData();
    void printProduct(ManageProduct data) const;
};


#endif /*MANAGE_FILE_H*/

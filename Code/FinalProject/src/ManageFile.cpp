#include "../inc/ManageFile.h"
ManageFile::ManageFile(std::string nameFile) : nameFile(nameFile) {
}

void ManageFile::addNewMemBer(std::string arr[]) {
    ManageProduct newProduct;

    newProduct.name = arr[0];

    newProduct.unitPrice = (float)(std::stof(arr[1]));
    if (newProduct.unitPrice < 0.0f) {
        std::cout << newProduct.name << ": gia tri don gia khong hop le\r\n";
        //* nếu giá tiền không hợp lệ cho sản phẩm bằng 0;
        newProduct.quantity = 0;
        return;
    }

    newProduct.quantity = (int)(std::stoi(arr[2]));
    if (newProduct.unitPrice < 0) {
        std::cout << newProduct.name << ": gia tri so luong khong hop le\r\n";
        newProduct.quantity = 0;
    }
    data.push_back(newProduct);
}

void ManageFile::initData() {
    std::cout << "khoi tao du lieu\r\n";

    std::ifstream file;

    assert(nameFile.empty() == false && "chua co file du lieu\r\n");
    /*
        *std::ios::in: Mở file để đọc.
        *std::ios::out : Mở file để ghi.Nếu file đã tồn tại, dữ liệu hiện có trong file sẽ bị ghi đè.
        *std::ios::app : Ghi vào cuối file.Nếu file không tồn tại, nó sẽ được tạo mới.
        *std::ios::ate : Mở file và di chuyển con trỏ đọc / ghi đến cuối file ngay sau khi mở.
        *std::ios::binary : Mở file trong chế độ nhị phân.
    */
    file.open(nameFile, std::ios::in);
    assert(file.is_open() == false && "duong dan file khong hop le\r\n");

    std::string line;
    while (std::getline(file, line)) { // Đọc từng dòng của file
        std::string arrData[SO_PHAN_TU_TRONG_STRUCT_DU_LIEU]; //? cách nào viết hay hơn để tự động chọn số 
        int i = 0;

        std::istringstream ss(line);
        std::string token;

        // Duyệt qua từng phần của chuỗi và in ra màn hình
        while (std::getline(ss, token, ',')) {
            arrData[i++] = token;
        }
        addNewMemBer(arrData);
        i = 0;
    }
    file.close(); // Đóng file
}

bool ManageFile::seachName(ManageProduct product, std::string string) {
    return (std::string::npos != product.name.find(string));
}

std::vector<int> ManageFile::seachData(std::string string, bool(*fnc)(ManageProduct product, std::string string)) {
    std::vector<int> index;
    for (int i = 0; i < data.size(); i++) {
        if (fnc(data[i], string)) {
            index.push_back(i);
        }
    }
    return index;
}

void ManageFile::saveData() {
    std::ofstream file;

    file.open(nameFile, std::ios::out);
    if (file.is_open() == false) {
        std::cout << "khong the mo file \r\n";
        return;
    }

    for (auto element : data) {
        file << element.name << ",";
        file << element.unitPrice << ",";
        file << element.quantity << std::endl;
    }
    file.close();

}

void ManageFile::printProduct(ManageProduct data) const {
    std::cout << "name: " << data.name << std::endl;
    std::cout << "unit price: " << data.unitPrice << std::endl;
    std::cout << "quantity: " << data.quantity << std::endl;
}

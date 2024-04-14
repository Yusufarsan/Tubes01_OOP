#include <exception>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Ini berbagai contoh bentuk exception, kembangin ae sendiri  -ucup-

// Gw mikirnya kayanya semua exception satuin aja di satu file, karena kan isi class nya ntar jg pada dikit kan

// Namain class sesuai kesalahan yang di catch

class ContohStrException : public exception {       // Contoh class yang nerima string sebagai pesan error
    private:
        string message;
    public:
        ContohStrException(const string& message) : message(message) {}

        const char* what() const throw() {
            return message.c_str();
        }
};

class ContohIntException : public exception {       // Contoh class yang nerima int lalu memberikan pesan mengapa error bisa terjadi
    private:
        int idx;
        int arr_capacity;
        string message;
    public:
        ContohIntException(int idx, int arr_capacity) : idx(idx), arr_capacity(arr_capacity) {
            ostringstream oss;
            oss << "This error happens cuz you try to access index " << idx << " in an array with capacity of " << arr_capacity << endl;
            message = oss.str();
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
};

class ContohIntException2 : public exception {       // Contoh class yang nerima int lalu memberikan pesan kesalahan (bukan pesan mengapa error bisa terjadi)
    private:
        int idx;
        int arr_capacity;
        string message;
    public:
        ContohIntException2(int idx, int arr_capacity) : idx(idx), arr_capacity(arr_capacity) {
            ostringstream oss;
            oss << "Kamu tidak memiliki index " << idx << " pada daftar pemain yang hanya berukuran " << arr_capacity<< endl;
            message = oss.str();
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
};
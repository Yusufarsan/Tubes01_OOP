#ifndef EXCEPTION_MATRIX_HPP
#define EXCEPTION_MATRIX_HPP

#include <exception>
#include <sstream>
#include <iostream>

using namespace std;


class tidakBisaTambahElemen : public exception {       // Contoh class yang nerima string sebagai pesan error
private:
    string message;
public:
    tidakBisaTambahElemen(const string& message) : message("Maaf tidak bisa menambah elemen" + message) {}

    const char* what() const throw() {
        return message.c_str();
    }
};

class aksesTidakValid : public exception {       // Contoh class yang nerima int lalu memberikan pesan mengapa error bisa terjadi
private:
    int baris;
    int kolom;
    string message;
public:
    aksesTidakValid(int baris, int kolom) : baris(baris), kolom(kolom) {
        ostringstream oss;
        oss << "Maaf kamu akses matriks di luar batas, baris: " << baris << " kolom: " << kolom << endl;
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class slotKosong : public exception {
private:
    string slot;
    string message;

public:
    slotKosong(string slot) :slot(slot) {
        message = "Maaf slot " + slot + " kosong";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class tidakDapatMenjual : public exception {
private:
    string nama;
    string message;

public:
    tidakDapatMenjual(string nama) :nama(nama) {
        ostringstream oss;
        oss << "Kamu tidak dapat menjual " + nama << endl;
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

};

// Error di matriks:
// -> Ketika ingin menambahkan elemen, matriks sudah penuh
// -> Ketika indeks yang ingin diakses diluar batas
// -> Ketika ingin menambahkan elemen, slot yang dipilih sudah terisi


#endif
#include "TanamanBuah.hpp"

TanamanBuah::TanamanBuah(string id, string kode_huruf, string nama, int harga, int umur_panen): Tanaman(id, kode_huruf, nama, harga, umur_panen) {
} 

TanamanBuah::TanamanBuah(const TanamanBuah &other): Tanaman(other) {
}

TanamanBuah::~TanamanBuah() {}

TanamanBuah& TanamanBuah::operator=(const TanamanBuah &other) {
    if (this != &other) {
        this->id = other.id;
        this->kode_huruf = other.kode_huruf;
        this->nama = other.nama;
        this->harga = other.harga;
        this->umur_panen = other.umur_panen;
        this->umur = other.umur;
    }
    return *this;
}

void TanamanBuah::print_info() {
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Umur: " << umur << endl;
    cout << "Umur Panen: " << umur_panen << endl;
}
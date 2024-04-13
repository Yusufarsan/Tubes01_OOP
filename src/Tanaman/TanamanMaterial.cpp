#include "TanamanMaterial.hpp"

// 4 Sekawan
TanamanMaterial::TanamanMaterial(string id, string kode_huruf, string nama, int harga, int umur_panen) : Tanaman(id, kode_huruf, nama, harga, umur_panen) {}

TanamanMaterial::TanamanMaterial(const TanamanMaterial& other) : Tanaman(other) {}

TanamanMaterial::~TanamanMaterial() {}

TanamanMaterial& TanamanMaterial::operator=(const TanamanMaterial& other) {
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

// Print Info
void TanamanMaterial::print_info() {
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Umur: " << umur << endl;
    cout << "Umur Panen: " << umur_panen << endl;
}
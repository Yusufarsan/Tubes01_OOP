#include "Bangunan.hpp"

Bangunan::Bangunan(string id, string kode_huruf, string nama, int harga) : Entitas(id, kode_huruf, nama, harga) {}

Bangunan::~Bangunan() {}

Bangunan::Bangunan(const Bangunan& other) : Entitas(other) {
    this->resep_tanaman = other.resep_tanaman;
}

Bangunan& Bangunan::operator=(const Bangunan& other) {
    if (this != &other) {
        this->id = other.id;
        this->kode_huruf = other.kode_huruf;
        this->nama = other.nama;
        this->harga = other.harga;
        this->resep_tanaman = other.resep_tanaman;
    }
    return *this;
}

map<string, int> Bangunan::dapatkan_resep() {
    return this->resep_tanaman;
}

void Bangunan::atur_resep_tanaman(map<string, int> resep_tanaman) {
    this->resep_tanaman = resep_tanaman;
}

void Bangunan::print_info() {
    cout << "ID: " << this->id << endl;
    cout << "Kode Huruf: " << this->kode_huruf << endl;
    cout << "Nama: " << this->nama << endl;
    cout << "Harga: " << this->harga << endl;
    cout << "Resep Tanaman: " << endl;
    for (auto it = this->resep_tanaman.begin(); it != this->resep_tanaman.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}
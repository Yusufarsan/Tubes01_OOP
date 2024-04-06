#include "Bangunan.hpp"

Bangunan::Bangunan(string id, string kode_huruf, string nama, int harga) : Entitas(id, kode_huruf, nama, harga) {}

Bangunan::~Bangunan() {}

Bangunan::Bangunan(Bangunan const& other) : Entitas(other) {
    this->resep_tanaman = other.resep_tanaman;
}

Bangunan& Bangunan::operator=(Bangunan const& other) {
    if (this != &other) {
        this->id = other.id;
        this->kode_huruf = other.kode_huruf;
        this->nama = other.nama;
        this->harga = other.harga;
        this->resep_tanaman = other.resep_tanaman;
    }
    return *this;
}
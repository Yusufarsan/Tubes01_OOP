#include "Entitas.hpp"

Entitas::Entitas(string id, string kode_huruf, string nama, int harga) {
    this->id = id;
    this->kode_huruf = kode_huruf;
    this->nama = nama;
    this->harga = harga;
}

Entitas::~Entitas() {}

Entitas::Entitas(const Entitas& other) {
    this->id = other.id;
    this->kode_huruf = other.kode_huruf;
    this->nama = other.nama;
    this->harga = other.harga;
}

Entitas& Entitas::operator=(const Entitas& other) {
    if (this != &other) {
        this->id = other.id;
        this->kode_huruf = other.kode_huruf;
        this->nama = other.nama;
        this->harga = other.harga;
    }
    return *this;
}

string Entitas::dapatkan_kode_huruf() {
    return kode_huruf;
};

string Entitas::dapatkan_nama() {
    return nama;
};

int Entitas::dapatkan_harga() {
    return harga;
};
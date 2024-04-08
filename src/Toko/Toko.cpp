#include "./Toko.hpp"

Toko::Toko(string path) {
    this->tanaman = InputKonfigurasi::InputKonfigurasiTanaman(path + "/plant.txt");
    this->hewan = InputKonfigurasi::InputKonfigurasiHewan(path + "/animal.txt");
}

Toko::~Toko() {
    for (int i = 0; i < this->tanaman.size(); i++) {
        delete this->tanaman[i];
    }

    for (int i = 0; i < this->hewan.size(); i++) {
        delete this->hewan[i];
    }

    for (int i = 0; i < this->produk.size(); i++) {
        delete this->produk[i];
    }
}

Toko::Toko(const Toko& other) {
    this->tanaman = other.tanaman;
    this->hewan = other.hewan;
    this->produk = other.produk;
    this->bangunan = other.bangunan;
}

Toko& Toko::operator=(const Toko& other) {
    if (this != &other) {
        this->tanaman = other.tanaman;
        this->hewan = other.hewan;
        this->produk = other.produk;
        this->bangunan = other.bangunan;
    }
    return *this;
}
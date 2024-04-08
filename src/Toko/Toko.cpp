#include "./Toko.hpp"

Toko::Toko() {}

Toko::Toko(string path) {
    this->tanaman = InputKonfigurasi::InputKonfigurasiTanaman(path + "/plant.txt");
    this->hewan = InputKonfigurasi::InputKonfigurasiHewan(path + "/animal.txt");
}

Toko::~Toko() {}

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
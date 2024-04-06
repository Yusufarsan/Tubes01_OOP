#include "ManajerPermainan.hpp"

ManagerPermainan::ManagerPermainan() {
    this->giliran = 0;
    this->jumlah_pemain = 0;
    this->daftar_tanaman = InputKonfigurasi::InputKonfigurasiTanaman("../../config/plant.txt");
    this->daftar_hewan = InputKonfigurasi::InputKonfigurasiHewan("../../config/animal.txt");
    this->daftar_produk = InputKonfigurasi::InputKonfigurasiProduk("../../config/product.txt");
}

ManagerPermainan::~ManagerPermainan() {
    for (int i = 0; i < this->daftar_tanaman.size(); i++) {
        delete this->daftar_tanaman[i];
    }

    for (int i = 0; i < this->daftar_hewan.size(); i++) {
        delete this->daftar_hewan[i];
    }

    for (int i = 0; i < this->daftar_produk.size(); i++) {
        delete this->daftar_produk[i];
    }
}
#include "ManajerPermainan.hpp"

ManagerPermainan::ManagerPermainan(string path) {
    this->giliran = 0;
    this->jumlah_pemain = 0;
    this->daftar_tanaman = InputKonfigurasi::InputKonfigurasiTanaman(path + "/plant.txt");
    this->daftar_hewan = InputKonfigurasi::InputKonfigurasiHewan(path + "/animal.txt");
    this->daftar_produk = InputKonfigurasi::InputKonfigurasiProduk(path + "/product.txt");
    this->daftar_bangunan = InputKonfigurasi::InputKonfigurasiResepBangunan(path + "/recipe.txt");

    this->toko = Toko(path);
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

    for (int i = 0; i < this->daftar_pemain.size(); i++) {
        delete this->daftar_pemain[i];
    }
}

void ManagerPermainan::print_konfigurasi() {
    cout << "Daftar Tanaman:" << endl;
    for (int i = 0; i < this->daftar_tanaman.size(); i++) {
        this->daftar_tanaman[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Hewan:" << endl;
    for (int i = 0; i < this->daftar_hewan.size(); i++) {
        this->daftar_hewan[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Produk:" << endl;
    for (int i = 0; i < this->daftar_produk.size(); i++) {
        this->daftar_produk[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Bangunan:" << endl;
    for (int i = 0; i < this->daftar_bangunan.size(); i++) {
        this->daftar_bangunan[i].print_info();
        cout << endl;
    }
}
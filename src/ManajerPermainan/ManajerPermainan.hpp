#ifndef MANAGERPERMAINAN_HPP
#define MANAGERPERMAINAN_HPP

#include <iostream>
#include <vector>
#include "../Pemain/Pemain.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"
#include "../Toko/Toko.hpp"

using namespace std;

class ManagerPermainan {
private:
    vector<shared_ptr<Pemain>> daftar_pemain;
    int giliran;
    int jumlah_pemain;

    vector<shared_ptr<Tanaman>> daftar_tanaman;
    vector<shared_ptr<Hewan>> daftar_hewan;
    vector<shared_ptr<Produk>> daftar_produk;
    vector<Bangunan> daftar_bangunan;

    Toko toko;
public:
    ManagerPermainan(string path);
    ~ManagerPermainan();

    void print_konfigurasi();
};

#endif
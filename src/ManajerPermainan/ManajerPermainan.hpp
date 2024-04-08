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
    vector<Pemain*> daftar_pemain;
    int giliran;
    int jumlah_pemain;

    vector<Tanaman*> daftar_tanaman;
    vector<Hewan*> daftar_hewan;
    vector<Produk*> daftar_produk;
    vector<Bangunan> daftar_bangunan;

    Toko toko = Toko("../config");
public:
    ManagerPermainan(string path);
    ~ManagerPermainan();

    void print_konfigurasi();
};

#endif
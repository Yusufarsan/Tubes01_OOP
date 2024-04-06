#ifndef MANAGERPERMAINAN_HPP
#define MANAGERPERMAINAN_HPP

#include <iostream>
#include <vector>
#include "../Pemain/Pemain.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

using namespace std;

class ManagerPermainan {
private:
    vector<Pemain*> daftar_pemain;
    int giliran;
    int jumlah_pemain;

    vector<Tanaman*> daftar_tanaman;
    vector<Hewan*> daftar_hewan;
    vector<Produk*> daftar_produk;
public:
    ManagerPermainan();
    ~ManagerPermainan();
};

#endif
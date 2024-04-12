#ifndef MANAGERPERMAINAN_HPP
#define MANAGERPERMAINAN_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include "../Pemain/Pemain.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"
#include "../Toko/Toko.hpp"

using namespace std;

class ManagerPermainan {
private:
    // State Pemain
    vector<shared_ptr<Pemain>> daftar_pemain;
    int giliran;
    int jumlah_pemain;
    tuple<int, int> besar_penyimpanan;
    tuple<int, int> besar_lahan;
    tuple<int, int> besar_peternakan;

    // State Konfigurasi
    vector<shared_ptr<Tanaman>> daftar_tanaman;
    vector<shared_ptr<Hewan>> daftar_hewan;
    vector<shared_ptr<Produk>> daftar_produk;
    vector<shared_ptr<Bangunan>> daftar_bangunan;

    // State Toko
    Toko toko;

    // State Memenangkan Permainan
    int uang_pemenang;
    int berat_pemenang;
public:
    ManagerPermainan(string path);
    ~ManagerPermainan();

    void atur_pemain(string path);
    void atur_pemain(vector<shared_ptr<Pemain>> daftarPemain);
    void sort_daftar_pemain();
    vector<shared_ptr<Pemain>> dapatkan_daftar_pemain();
    shared_ptr<Pemain> pemain_skrg();        // Nge return pemain saat ini yg lagi gilirannya
    void next();

    void inisialisasi_toko();
    Toko dapatkan_toko();

    tuple<int,int> dapatkanBesarPenyimpanan() const;

    void print_konfigurasi();
};

#endif
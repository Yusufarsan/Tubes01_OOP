#ifndef MANAGERPERMAINAN_HPP
#define MANAGERPERMAINAN_HPP

// STL
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

// User-defined
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
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
    // Constructor & Destructor
    ManagerPermainan(string path);
    ~ManagerPermainan();

    // Getter & Setter
    vector<shared_ptr<Pemain>> dapatkan_daftar_pemain();
    shared_ptr<Pemain> pemain_skrg();
    tuple<int, int> dapatkanBesarPenyimpanan() const;
    tuple<int, int> dapatkanBesarLahan() const;
    tuple<int, int> dapatkanBesarPeternakan() const;
    Toko dapatkan_toko();
    void atur_pemain(string path);
    void atur_pemain(vector<shared_ptr<Pemain>> daftarPemain);

    // Method
    void sort_daftar_pemain();
    void inisialisasi_toko();

    // Command Permainan
    void next();
    void muat();
    void inisialisasi_pemain();
    void simpan();

    // Print Info
    void print_konfigurasi();
};

#endif
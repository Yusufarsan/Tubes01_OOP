#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Produk/Produk.hpp"
#include "../Bangunan/Bangunan.hpp"
// #include "../InputKonfigurasi/InputKonfigurasi.hpp"

using namespace std;

class Toko {
private:
    vector<shared_ptr<Tanaman>> tanaman;
    vector<shared_ptr<Hewan>> hewan;
    map<shared_ptr<Produk>, int> produk;
    map<shared_ptr<Bangunan>, int> bangunan;
public:
    Toko();
    ~Toko();
    Toko(const Toko& other);
    Toko& operator=(const Toko& other);

    void tampilBarang(bool isWalikota);
    void masukanEntitas(Entitas* Entitas);
    void atur_tanaman(vector<shared_ptr<Tanaman>> t);
    void atur_hewan(vector<shared_ptr<Hewan>> h);

    void tambah_produk(shared_ptr<Produk> p);
    void tambah_bangunan(shared_ptr<Bangunan> b);

    void cetak_isi_toko();
};

#endif
#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <vector>
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Produk/Produk.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

using namespace std;

class Toko {
private:
    vector<shared_ptr<Tanaman>> tanaman;
    vector<shared_ptr<Hewan>> hewan;
    vector<shared_ptr<Produk>> produk;
    vector<Bangunan> bangunan;
public:
    Toko();
    Toko(string path);
    ~Toko();
    Toko(const Toko& other);
    Toko& operator=(const Toko& other);

    void tambah_produk(shared_ptr<Produk> p);
    void tambah_bangunan(Bangunan b);
};

#endif
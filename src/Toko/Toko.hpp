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
    vector<Tanaman*> tanaman;
    vector<Hewan*> hewan;
    vector<Produk*> produk;
    vector<Bangunan> bangunan;
public:
    Toko(string path);
    ~Toko();
    Toko(const Toko& other);
    Toko& operator=(const Toko& other);
};

#endif
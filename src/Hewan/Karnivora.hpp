#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Karnivora : public Hewan {
public:
    // 4 Sekawan
    Karnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
    Karnivora(Karnivora& other); // cctor
    ~Karnivora(); // dtor
    Karnivora& operator=(const Karnivora& other); // operator =

    // Command
    void makan(Produk* makanan);
};

#endif
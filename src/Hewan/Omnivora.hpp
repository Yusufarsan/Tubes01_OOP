#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Omnivora : public Hewan {
public:
    // 4 Sekawan
    Omnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
    Omnivora(Omnivora& other); // cctor
    ~Omnivora(); // dtor
    Omnivora& operator=(const Omnivora& other); // operator =

    // Command
    void makan(Produk* makanan);
};

#endif
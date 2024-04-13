#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Util/Util.hpp"

class Herbivora : public Hewan {
public:
    // 4 Sekawan
    Herbivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
    Herbivora(Herbivora& other); // cctor
    ~Herbivora(); // dtor
    Herbivora& operator=(const Herbivora& other); // operator =

    // Command
    void makan(Produk* makanan);
};

#endif
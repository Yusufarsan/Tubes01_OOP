#ifndef PRODUKTANAMANBUAH_HPP
#define PRODUKTANAMANBUAH_HPP

// User-defined
#include "Produk.hpp"
#include "../Util/Util.hpp"

class ProdukTanamanBuah : public Produk {
public:
    // 4 Sekawan
    ProdukTanamanBuah(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor
    ProdukTanamanBuah(string origin, int berat, int harga): Produk(origin, Util::dapatkan_kode(origin)+"P", origin+"_TREE", berat, harga){};
    ~ProdukTanamanBuah(); // dtor
    ProdukTanamanBuah(const ProdukTanamanBuah& other); // cctor
    ProdukTanamanBuah& operator=(const ProdukTanamanBuah& other); // operator=

    // Print Info
    void print_info(); // print info
};

#endif
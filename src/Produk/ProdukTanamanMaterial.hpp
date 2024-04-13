#ifndef PRODUKTANAMANMATERIAL_HPP
#define PRODUKTANAMANMATERIAL_HPP

// User-defined
#include "Produk.hpp"

class ProdukTanamanMaterial : public Produk {
public:
    // 4 Sekawan
    ProdukTanamanMaterial(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor
    ~ProdukTanamanMaterial(); // dtor
    ProdukTanamanMaterial(const ProdukTanamanMaterial& other); // cctor
    ProdukTanamanMaterial& operator=(const ProdukTanamanMaterial& other); // operator=

    // Print Info
    void print_info(); // print info
};

#endif
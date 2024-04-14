#ifndef PRODUKHEWAN_HPP
#define PRODUKHEWAN_HPP

// User-defined
#include "Produk.hpp"
#include "../Util/Util.hpp"

class ProdukHewan : public Produk {
public:
    // 4 Sekawan
    ProdukHewan(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor
    ProdukHewan(string origin, int berat, int harga): Produk(origin+"_MEAT", Util::dapatkan_kode(origin)+"M", origin, berat, harga){};
    ~ProdukHewan(); // dtor
    ProdukHewan(const ProdukHewan& other); // cctor
    ProdukHewan& operator=(const ProdukHewan& other); // operator=

    // Print Info
    void print_info(); // print info
};

#endif
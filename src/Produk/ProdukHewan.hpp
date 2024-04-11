#ifndef PRODUKHEWAN_HPP
#define PRODUKHEWAN_HPP

#include "Produk.hpp"

class ProdukHewan : public Produk {
    public:
        ProdukHewan(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor
        ~ProdukHewan(); // dtor
        ProdukHewan(const ProdukHewan& other); // cctor
        ProdukHewan& operator=(const ProdukHewan& other); // operator=
        
        void print_info(); // print info
};

#endif
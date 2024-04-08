#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <iostream>
#include "../Entitas/Entitas.hpp"

using namespace std;


class Produk : public Entitas {      // ABC
    protected:
        int berat_tambahan;     // tambahan berat untuk pemakan produk ini
        string origin;          // Nama tanaman asal produk
    public:
        Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin);      // ctor
        ~Produk();                                      // dtor
        Produk& operator=(const Produk &produk);        // operator=
        
        void atur_berat_tambahan(int berat_tambahan);    // setter
        void atur_origin(string origin);                
        int dapatkan_berat_tambahan();                       // getter
        string dapatkan_origin();    
        virtual void print_info() = 0;                              // print info
};

#endif

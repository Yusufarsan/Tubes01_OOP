#ifndef PRODUK_HPP
#define PRODUK_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"

using namespace std;


class Produk : public Entitas {      // ABC
protected:
    static int jumlah_produk;
    int berat_tambahan;     // tambahan berat untuk pemakan produk ini
    string origin;          // Nama tanaman asal produk
public:
    // 4 Sekawan
    Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin);      // ctor
    Produk(string nama, string kode, string origin, int berat_tambahan, int harga);
    ~Produk();                                      // dtor
    Produk& operator=(const Produk& produk);        // operator=

    // Getter & Setter
    static int dapatkan_jumlah_produk_saat_ini();
    int dapatkan_berat_tambahan();                       // getter
    string dapatkan_origin();
    void atur_berat_tambahan(int berat_tambahan);    // setter
    void atur_origin(string origin);

    // Print Info
    virtual void print_info() {};                              // print info
};

#endif

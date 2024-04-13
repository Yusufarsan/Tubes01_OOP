#ifndef PRODUK_HPP
#define PRODUK_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"

using namespace std;


class Produk : public Entitas {      // ABC
protected:
    int berat_tambahan;     // tambahan berat untuk pemakan produk ini
    string origin;          // Nama tanaman asal produk
public:
    // 4 Sekawan
    Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin);      // ctor
    Produk(Entitas* other, int berat):origin(other->dapatkan_nama()), berat_tambahan(berat),Entitas(*other){};
    ~Produk();                                      // dtor
    Produk& operator=(const Produk& produk);        // operator=

    // Getter & Setter
    int dapatkan_berat_tambahan();                       // getter
    string dapatkan_origin();
    void atur_berat_tambahan(int berat_tambahan);    // setter
    void atur_origin(string origin);

    // Print Info
    virtual void print_info() {
            cout << "ID: " << id << endl;
        cout << "Kode Huruf: " << kode_huruf << endl;
        cout << "Nama: " << nama << endl;
        cout << "Harga: " << harga << endl;
        cout << "Berat Tambahan: " << berat_tambahan << endl;
        cout << "Origin: " << origin << endl;
    };                              // print info
};

#endif

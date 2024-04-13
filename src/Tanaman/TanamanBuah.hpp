#ifndef TANAMANBUAH_HPP
#define TANAMANBUAH_HPP

// User-defined
#include "Tanaman.hpp"

class TanamanBuah : public Tanaman {
public:
    // 4 Sekawan
    TanamanBuah(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor
    TanamanBuah(const TanamanBuah& other); // cctor
    ~TanamanBuah(); // dtor
    TanamanBuah& operator=(const TanamanBuah& other); // operator =

    // Print Info
    void print_info();
};

#endif
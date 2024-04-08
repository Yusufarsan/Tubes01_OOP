#ifndef TANAMANBUAH_HPP
#define TANAMANBUAH_HPP

#include "Tanaman.hpp"

class TanamanBuah: public Tanaman {
    protected:
    public:
        TanamanBuah(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor
        TanamanBuah(const TanamanBuah &other); // cctor
        ~TanamanBuah(); // dtor
        TanamanBuah& operator=(const TanamanBuah &other); // operator =

        void print_info();
};

#endif
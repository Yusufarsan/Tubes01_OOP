#ifndef TANAMANMATERIAL_HPP
#define TANAMANMATERIAL_HPP

#include "Tanaman.hpp"

class TanamanMaterial: public Tanaman {
    protected:
    public:
        TanamanMaterial(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor
        TanamanMaterial(const TanamanMaterial &other); // cctor
        ~TanamanMaterial(); // dtor
        TanamanMaterial& operator=(const TanamanMaterial &other); // operator =

        void print_info();
};

#endif
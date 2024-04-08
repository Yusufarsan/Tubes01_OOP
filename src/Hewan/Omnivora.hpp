#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

#include "Hewan.hpp"
#include "../Produk/Produk.hpp"

class Omnivora: public Hewan {
    private:

    public:
        Omnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
        Omnivora(Omnivora &other); // cctor
        ~Omnivora(); // dtor
        Omnivora& operator=(const Omnivora &other); // operator =

        void makan(Produk *makanan);
};

#endif
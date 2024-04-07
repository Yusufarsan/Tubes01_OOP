#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

#include "Hewan.hpp"
#include "Produk/Produk.hpp"

class Karnivora: public Hewan {
    private:

    public:
        Karnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
        Karnivora(Karnivora &other); // cctor
        ~Karnivora(); // dtor
        Karnivora& operator=(const Karnivora &other); // operator =

        void makan(Produk *makanan);
};

#endif
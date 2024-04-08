#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include <iostream>
#include "../Entitas/Entitas.hpp"

class Tanaman: public Entitas {
    protected:
        int umur_panen;
        int umur;
    public:
        Tanaman(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor (default umur = 0)
        Tanaman(const Tanaman &other); // cctor
        ~Tanaman(); // dtor
        Tanaman& operator=(const Tanaman &other); // operator =

        int dapatkan_umur(); // getter
        int dapatkan_umur_panen();
        void tambah_umur(); // increment umur
        bool bisa_panen();
        void print_info();
};

#endif
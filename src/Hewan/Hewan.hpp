#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "../Entitas/Entitas.hpp"

class Hewan: public Entitas {
    protected:
        const int berat_panen;
        int berat;
    public:
        Hewan(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
        Hewan(Hewan &other); // cctor
        ~Hewan(); // dtor
        Hewan& operator=(const Hewan &other); // operator =

        int dapatkan_berat(); // getter
        int dapatkan_berat_panen();
        void tambah_berat(int num); // increment berat
        bool bisa_panen(); 
        virtual void makan(Produk *makanan)=0;
        void print_info();
};

#endif
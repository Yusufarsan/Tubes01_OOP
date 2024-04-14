#ifndef HEWAN_HPP
#define HEWAN_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"
#include "../Produk/Produk.hpp"

class Hewan : public Entitas {
protected:
    int berat_panen;
    int berat;
public:
    Hewan(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
    Hewan(Hewan& other); // cctor
    virtual ~Hewan(); // dtor
    Hewan& operator=(const Hewan& other); // operator =

    // Getter & Setter
    int dapatkan_berat(); // getter
    int dapatkan_berat_panen();
    void atur_berat(int berat); // setter

    // Method
    void tambah_berat(int num); // increment berat
    bool bisa_panen();

    // Command
    virtual void makan(Produk* makanan) = 0;

    // Print Info
    void print_info();
};

#endif
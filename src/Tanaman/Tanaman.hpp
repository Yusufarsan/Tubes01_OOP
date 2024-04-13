#ifndef TANAMAN_HPP
#define TANAMAN_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"

class Tanaman : public Entitas {
protected:
    int umur_panen;
    int umur;
public:
    // 4 Sekawan
    Tanaman(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor (default umur = 0)
    Tanaman(const Tanaman& other); // cctor
    ~Tanaman(); // dtor
    Tanaman& operator=(const Tanaman& other); // operator =

    // Getter & Setter
    int dapatkan_umur(); // getter
    int dapatkan_umur_panen();
    void atur_umur(int umur);

    // Method
    void tambah_umur(); // increment umur
    bool bisa_panen();

    // Print Info
    void print_info();
};

#endif
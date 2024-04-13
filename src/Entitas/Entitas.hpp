#ifndef ENTITAS_HPP
#define ENTITAS_HPP

// STL
#include <iostream>

using namespace std;

class Entitas {
protected:
    string id;
    string kode_huruf;
    string nama;
    int harga;
public:
    // 4 Sekawan
    Entitas(string id, string kode_huruf, string nama, int harga);
    ~Entitas();
    Entitas(const Entitas& other);
    Entitas& operator=(const Entitas& other);

    // Getter
    string dapatkanId();
    string dapatkan_kode_huruf();
    string dapatkan_nama();
    int dapatkan_harga();

    // Operator Overloading
    bool operator==(Entitas& other);

    // Print Info
    virtual void print_info() = 0;
};


#endif
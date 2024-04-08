#ifndef ENTITAS_HPP
#define ENTITAS_HPP

#include <iostream>
using namespace std;

class Entitas {
protected:
    string id;
    string kode_huruf;
    string nama;
    int harga;
public:
    Entitas(string id, string kode_huruf, string nama, int harga);
    ~Entitas();
    Entitas(const Entitas& other);
    Entitas& operator=(const Entitas& other);
    virtual void print_info() = 0;

    string dapatkan_kode_huruf();
    string dapatkan_nama();
};


#endif
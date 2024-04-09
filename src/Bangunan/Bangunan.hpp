#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <map>
#include "../Entitas/Entitas.hpp"

using namespace std;

class Bangunan : public Entitas {
private:
    map<string, int> resep_tanaman;
public:
    Bangunan(string id, string kode_huruf, string nama, int harga);
    ~Bangunan();
    Bangunan(const Bangunan& other);
    Bangunan& operator=(const Bangunan& other);

    map<string, int> dapatkan_resep();
    void atur_resep_tanaman(map<string, int> resep_tanaman);
    void print_info();
};

#endif
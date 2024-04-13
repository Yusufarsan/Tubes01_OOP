#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

// STL
#include <iostream>
#include <map>

// User-defined
#include "../Entitas/Entitas.hpp"

using namespace std;

class Bangunan : public Entitas {
private:
    map<string, int> resep_tanaman;
public:
    // 4 Sekawan
    Bangunan(string id, string kode_huruf, string nama, int harga);
    ~Bangunan();
    Bangunan(const Bangunan& other);
    Bangunan& operator=(const Bangunan& other);

    // Getter & Setter
    map<string, int> dapatkan_resep();
    void atur_resep_tanaman(map<string, int> resep_tanaman);

    // Print Info
    void print_info();
};

#endif
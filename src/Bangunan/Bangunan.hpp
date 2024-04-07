#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <map>
#include "../Entitas/Entitas.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
using namespace std;

class Bangunan : public Entitas {
private:
    map<ProdukTanamanMaterial, int> resep_tanaman;
public:
    Bangunan(string id, string kode_huruf, string nama, int harga);
    ~Bangunan();
    Bangunan(Bangunan const& other);
    Bangunan& operator=(Bangunan const& other);
};

#endif
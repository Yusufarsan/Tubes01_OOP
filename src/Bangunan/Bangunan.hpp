#include <iostream>
#include <map>
#include "../Entitas/Entitas.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
using namespace std;

class Bangunan : public Entitas {
private:
    map<ProdukTanamanMaterial, int> resep_tanaman;
};
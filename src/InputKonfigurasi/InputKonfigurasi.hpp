#ifndef INPUTKONFIGURASI_HPP
#define INPUTKONFIGURASI_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include "../Tanaman/Tanaman.hpp"
#include "../Tanaman/TanamanMaterial.hpp"
#include "../Tanaman/TanamanBuah.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"

using namespace std;

class InputKonfigurasi {
public:
    static vector<Tanaman*> InputKonfigurasiTanaman(string nama_file);
    static vector<Hewan*> InputKonfigurasiHewan(string nama_file);
    static vector<Produk*> InputKonfigurasiProduk(string nama_file);
    static vector<Bangunan> InputKonfigurasiResepBangunan(string nama_file);
};

#endif
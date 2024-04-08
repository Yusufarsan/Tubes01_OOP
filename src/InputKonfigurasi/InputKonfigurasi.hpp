#ifndef INPUTKONFIGURASI_HPP
#define INPUTKONFIGURASI_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
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
    static vector<shared_ptr<Tanaman>> InputKonfigurasiTanaman(string nama_file);
    static vector<shared_ptr<Hewan>> InputKonfigurasiHewan(string nama_file);
    static vector<shared_ptr<Produk>> InputKonfigurasiProduk(string nama_file);
    static vector<Bangunan> InputKonfigurasiResepBangunan(string nama_file);
};

#endif
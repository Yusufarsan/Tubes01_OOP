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
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Toko/Toko.hpp"
#include "../Util/Util.hpp"


using namespace std;

class InputKonfigurasi {
public:
    static vector<shared_ptr<Tanaman>> InputKonfigurasiTanaman(string nama_file);
    static vector<shared_ptr<Hewan>> InputKonfigurasiHewan(string nama_file);
    static vector<shared_ptr<Produk>> InputKonfigurasiProduk(string nama_file);
    static vector<Bangunan> InputKonfigurasiResepBangunan(string nama_file);
    static vector<int> InputKonfigurasiMisc(string nama_file);

    static vector<shared_ptr<Pemain>> InputStatePemain(string nama_file, vector<shared_ptr<Tanaman>> daftar_tanaman, vector<shared_ptr<Hewan>> daftar_hewan, vector<shared_ptr<Produk>> daftar_produk, vector<Bangunan> daftar_bangunan, tuple<int, int> besar_penyimpanan, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan, Toko& toko);
};

#endif
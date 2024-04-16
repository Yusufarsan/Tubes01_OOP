#ifndef INPUTKONFIGURASI_HPP
#define INPUTKONFIGURASI_HPP

// STL
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

// User-defined
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
    // Input Konfigurasi

    /**
     * @brief Membaca file konfigurasi tanaman dan mengembalikan vector<shared_ptr<Tanaman>>
     *
     * @param nama_file
     * @return vector<shared_ptr<Tanaman>>
     */
    static vector<shared_ptr<Tanaman>> InputKonfigurasiTanaman(string nama_file);

    /**
     * @brief Membaaca file konfigurasi hewan dan mengembalikan vector<shared_ptr<Hewan>>
     *
     * @param nama_file
     * @return vector<shared_ptr<Hewan>>
     */
    static vector<shared_ptr<Hewan>> InputKonfigurasiHewan(string nama_file);

    /**
     * @brief Membaaca file konfigurasi produk dan mengembalikan vector<shared_ptr<Produk>>
     *
     * @param nama_file
     * @return vector<shared_ptr<Produk>>
     */
    static vector<shared_ptr<Produk>> InputKonfigurasiProduk(string nama_file);

    /**
     * @brief Membaaca file konfigurasi bangunan dan mengembalikan vector<shared_ptr<Bangunan>>
     *
     * @param nama_file
     * @return vector<shared_ptr<Bangunan>>
     */
    static vector<shared_ptr<Bangunan>> InputKonfigurasiResepBangunan(string nama_file);

    /**
     * @brief Membaaca file konfigurasi misc dan mengembalikan vector<int>
     *
     * @param nama_file
     * @return vector<int>
     */
    static vector<int> InputKonfigurasiMisc(string nama_file);

    // Input State Pemain

    /**
     * @brief Membaca file state pemain dan mengembalikan vector<shared_ptr<Pemain>>
     *
     * @param nama_file
     * @param daftar_tanaman
     * @param daftar_hewan
     * @param daftar_produk
     * @param daftar_bangunan
     * @param besar_penyimpanan
     * @param besar_lahan
     * @param besar_peternakan
     * @param toko
     * @return vector<shared_ptr<Pemain>>
     */
    static vector<shared_ptr<Pemain>> InputStatePemain(string nama_file, vector<shared_ptr<Tanaman>> daftar_tanaman, vector<shared_ptr<Hewan>> daftar_hewan, vector<shared_ptr<Produk>> daftar_produk, vector<shared_ptr<Bangunan>> daftar_bangunan, tuple<int, int> besar_penyimpanan, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan, Toko& toko);
};

#endif
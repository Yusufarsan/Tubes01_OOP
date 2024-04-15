#ifndef PRODUKTANAMANMATERIAL_HPP
#define PRODUKTANAMANMATERIAL_HPP

// User-defined
#include "Produk.hpp"
#include "../Util/Util.hpp"

class ProdukTanamanMaterial : public Produk {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Produk Tanaman Material object
     *
     * @param id
     * @param kode_huruf (Contoh: APP = Apple)
     * @param nama
     * @param harga
     * @param berat_tambahan
     * @param origin
     */
    ProdukTanamanMaterial(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor

    /**
     * @brief Construct a new Produk Tanaman Material object
     *
     * @param origin
     * @param berat
     * @param harga
     */
    ProdukTanamanMaterial(string origin, int berat_tambahan, int harga) : Produk(origin + "_WOOD", Util::dapatkan_kode(origin) + "W", origin + "_TREE", berat_tambahan, harga) {};

    /**
     * @brief Destroy the Produk Tanaman Material object
     *
     */
    ~ProdukTanamanMaterial(); // dtor

    /**
     * @brief Construct a new Produk Tanaman Material object
     *
     * @param other
     */
    ProdukTanamanMaterial(const ProdukTanamanMaterial& other); // cctor

    /**
     * @brief Men-assign objek produk tanaman material dengan produk tanaman material lain
     *
     * @param other
     * @return ProdukTanamanMaterial&
     */
    ProdukTanamanMaterial& operator=(const ProdukTanamanMaterial& other); // operator=

    // Print Info

    /**
     * @brief Menampilkan info produk tanaman material
     *
     */
    void print_info(); // print info
};

#endif
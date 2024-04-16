#ifndef PRODUKTANAMANBUAH_HPP
#define PRODUKTANAMANBUAH_HPP

// User-defined
#include "Produk.hpp"
#include "../Util/Util.hpp"

class ProdukTanamanBuah : public Produk {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Produk Tanaman Buah object
     *
     * @param id
     * @param kode_huruf (Contoh: APP = Apple)
     * @param nama
     * @param harga
     * @param berat_tambahan
     * @param origin
     */
    ProdukTanamanBuah(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor

    /**
     * @brief Construct a new Produk Tanaman Buah object
     *
     * @param origin
     * @param berat
     * @param harga
     */
    ProdukTanamanBuah(string origin, int berat, int harga) : Produk(origin, Util::dapatkan_kode(origin) + "P", origin + "_TREE", berat, harga) {};

    /**
     * @brief Destroy the Produk Tanaman Buah object
     *
     */
    ~ProdukTanamanBuah(); // dtor

    /**
     * @brief Construct a new Produk Tanaman Buah object
     *
     * @param other
     */
    ProdukTanamanBuah(const ProdukTanamanBuah& other); // cctor

    /**
     * @brief Men-assign objek produk tanaman buah dengan produk tanaman buah lain
     *
     * @param other
     * @return ProdukTanamanBuah&
     */
    ProdukTanamanBuah& operator=(const ProdukTanamanBuah& other); // operator=

    // Print Info

    /**
     * @brief Menampilkan info produk tanaman buah
     *
     */
    void print_info(); // print info
};

#endif
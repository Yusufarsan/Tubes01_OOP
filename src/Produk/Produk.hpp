#ifndef PRODUK_HPP
#define PRODUK_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"

using namespace std;


class Produk : public Entitas {      // ABC
protected:
    static int jumlah_produk;
    int berat_tambahan;     // tambahan berat untuk pemakan produk ini
    string origin;          // Nama tanaman asal produk
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Produk object
     *
     * @param id
     * @param kode_huruf (Contoh: APP = Apple)
     * @param nama
     * @param harga
     * @param berat_tambahan
     * @param origin
     */
    Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin);      // ctor

    /**
     * @brief Construct a new Produk object
     *
     * @param nama
     * @param kode (Contoh: APP = Apple)
     * @param origin
     * @param berat_tambahan
     * @param harga
     */
    Produk(string nama, string kode, string origin, int berat_tambahan, int harga);

    /**
     * @brief Destroy the Produk object
     *
     */
    ~Produk();                                      // dtor

    /**
     * @brief Men-assign objek produk dengan produk lain
     *
     * @param produk
     * @return Produk&
     */
    Produk& operator=(const Produk& produk);        // operator=

    // Getter & Setter

    /**
     * @brief Mengembalikan jumlah produk saat ini
     *
     * @return int
     */
    static int dapatkan_jumlah_produk_saat_ini();

    /**
     * @brief Mengembalikan berat tambahan
     *
     * @return int
     */
    int dapatkan_berat_tambahan();                       // getter

    /**
     * @brief Mengembalikan origin
     *
     * @return string
     */
    string dapatkan_origin();

    /**
     * @brief Mengatur berat tambahan
     *
     * @param berat_tambahan
     */
    void atur_berat_tambahan(int berat_tambahan);    // setter

    /**
     * @brief Mengatur origin
     *
     * @param origin
     */
    void atur_origin(string origin);

    // Print Info

    /**
     * @brief Virtual method untuk print info
     *
     */
    virtual void print_info() {};                              // print info
};

#endif

#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Omnivora : public Hewan {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Omnivora object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param berat_panen
     */
    Omnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)

    /**
     * @brief Construct a new Omnivora object
     *
     * @param other
     */
    Omnivora(Omnivora& other); // cctor

    /**
     * @brief Destroy the Omnivora object
     *
     */
    ~Omnivora(); // dtor

    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     *
     * @param other
     * @return Omnivora&
     */
    Omnivora& operator=(const Omnivora& other); // operator =

    // Command

    /**
     * @brief Melakukan command makan
     *
     * @param makanan
     * @return bool
     */
    bool makan(Produk* makanan);
};

#endif
#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Util/Util.hpp"

class Herbivora : public Hewan {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Herbivora object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param berat_panen
     */
    Herbivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)

    /**
     * @brief Construct a new Herbivora object
     *
     * @param other
     */
    Herbivora(Herbivora& other); // cctor

    /**
     * @brief Destroy the Herbivora object
     *
     */
    ~Herbivora(); // dtor

    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     *
     * @param other
     * @return Herbivora&
     */
    Herbivora& operator=(const Herbivora& other); // operator =

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
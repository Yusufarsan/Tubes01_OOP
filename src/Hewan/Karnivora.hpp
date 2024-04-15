#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

// STL
#include <iostream>

// User-defined
#include "Hewan.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Karnivora : public Hewan {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Karnivora object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param berat_panen
     */
    Karnivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)

    /**
     * @brief Construct a new Karnivora object
     *
     * @param other
     */
    Karnivora(Karnivora& other); // cctor

    /**
     * @brief Destroy the Karnivora object
     *
     */
    ~Karnivora(); // dtor

    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     *
     * @param other
     * @return Karnivora&
     */
    Karnivora& operator=(const Karnivora& other); // operator =

    // Command

    /**
     * @brief Melakukan command makan
     *
     * @param makanan
     */
    void makan(Produk* makanan);
};

#endif
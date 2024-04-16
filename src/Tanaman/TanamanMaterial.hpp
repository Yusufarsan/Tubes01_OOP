#ifndef TANAMANMATERIAL_HPP
#define TANAMANMATERIAL_HPP

// User-defined
#include "Tanaman.hpp"

class TanamanMaterial : public Tanaman {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Tanaman Material object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param umur_panen
     */
    TanamanMaterial(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor

    /**
     * @brief Construct a new Tanaman Material object
     *
     * @param other
     */
    TanamanMaterial(const TanamanMaterial& other); // cctor

    /**
     * @brief Destroy the Tanaman Material object
     *
     */
    ~TanamanMaterial(); // dtor

    /**
     * @brief Men-assign objek tanaman material dengan tanaman material lain
     *
     * @param other
     * @return TanamanMaterial&
     */
    TanamanMaterial& operator=(const TanamanMaterial& other); // operator =

    // Print Info
    void print_info();
};

#endif
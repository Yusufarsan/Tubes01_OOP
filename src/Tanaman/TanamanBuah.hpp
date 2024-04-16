#ifndef TANAMANBUAH_HPP
#define TANAMANBUAH_HPP

// User-defined
#include "Tanaman.hpp"

class TanamanBuah : public Tanaman {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Tanaman Buah object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param umur_panen
     */
    TanamanBuah(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor

    /**
     * @brief Construct a new Tanaman Buah object
     *
     * @param other
     */
    TanamanBuah(const TanamanBuah& other); // cctor

    /**
     * @brief Destroy the Tanaman Buah object
     *
     */
    ~TanamanBuah(); // dtor

    /**
     * @brief Men-assign objek tanaman buah dengan tanaman buah lain
     *
     * @param other
     * @return TanamanBuah&
     */
    TanamanBuah& operator=(const TanamanBuah& other); // operator =

    // Print Info

    /**
     * @brief Menampilkan info tanaman buah
     *
     */
    void print_info();
};

#endif
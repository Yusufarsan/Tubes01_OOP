#ifndef TANAMAN_HPP
#define TANAMAN_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"

class Tanaman : public Entitas {
protected:
    int umur_panen;
    int umur;
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Tanaman object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     * @param umur_panen
     */
    Tanaman(string id, string kode_huruf, string nama, int harga, int umur_panen); // ctor (default umur = 0)

    /**
     * @brief Construct a new Tanaman object
     *
     * @param other
     */
    Tanaman(const Tanaman& other); // cctor

    /**
     * @brief Destroy the Tanaman object
     *
     */
    ~Tanaman(); // dtor

    /**
     * @brief Men-assign objek tanaman dengan tanaman lain
     *
     * @param other
     * @return Tanaman&
     */
    Tanaman& operator=(const Tanaman& other); // operator =

    // Getter & Setter

    /**
     * @brief Mengembalikan umur tanaman
     *
     * @return int
     */
    int dapatkan_umur(); // getter

    /**
     * @brief Mengembalikan umur panen tanaman
     *
     * @return int
     */
    int dapatkan_umur_panen();

    /**
     * @brief Mengatur umur tanaman
     *
     * @param umur
     */
    void atur_umur(int umur);

    // Method

    /**
     * @brief Menambah umur tanaman
     *
     */
    void tambah_umur(); // increment umur

    /**
     * @brief Mengecek apakah tanaman bisa dipanen
     *
     * @return true
     * @return false
     */
    bool bisa_panen();

    // Print Info

    /**
     * @brief Menampilkan info tanaman
     *
     */
    void print_info();
};

#endif
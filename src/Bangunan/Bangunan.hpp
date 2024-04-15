#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

// STL
#include <iostream>
#include <map>

// User-defined
#include "../Entitas/Entitas.hpp"

using namespace std;

class Bangunan : public Entitas {
private:
    map<string, int> resep_tanaman;
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Bangunan object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     */
    Bangunan(string id, string kode_huruf, string nama, int harga);

    /**
     * @brief Destroy the Bangunan object
     *
     */
    ~Bangunan();

    /**
     * @brief Construct a new Bangunan object
     *
     * @param other
     */
    Bangunan(const Bangunan& other);

    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     *
     * @param other
     * @return Bangunan&
     */
    Bangunan& operator=(const Bangunan& other);

    // Getter & Setter

    /**
     * @brief Mengembalikan resep yang dibutuhkan untuk membangun bangunan
     *
     * @return map<string, int>
     */
    map<string, int> dapatkan_resep();

    /**
     * @brief Mengatur resep yang dibutuhkan untuk membangun bangunan
     *
     * @param resep_tanaman
     */
    void atur_resep_tanaman(map<string, int> resep_tanaman);

    // Print Info

    /**
     * @brief Menampilkan info bangunan
     *
     */
    void print_info();
};

#endif
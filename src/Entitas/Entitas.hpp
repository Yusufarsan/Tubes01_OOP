#ifndef ENTITAS_HPP
#define ENTITAS_HPP

// STL
#include <iostream>

using namespace std;

class Entitas {
protected:
    string id;
    string kode_huruf;
    string nama;
    int harga;
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Entitas object
     *
     * @param id
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama
     * @param harga
     */
    Entitas(string id, string kode_huruf, string nama, int harga);

    /**
     * @brief Destroy the Entitas object
     *
     */
    ~Entitas();

    /**
     * @brief Construct a new Entitas object
     *
     * @param other
     */
    Entitas(const Entitas& other);

    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     *
     * @param other
     * @return Entitas&
     */
    Entitas& operator=(const Entitas& other);

    // Getter

    /**
     * @brief Mengembalikan id dari entitas
     *
     * @return string
     */
    string dapatkanId();

    /**
     * @brief Mengembalikan kode huruf dari entitas
     *
     * @return string
     */
    string dapatkan_kode_huruf();

    /**
     * @brief Mengembalikan nama dari entitas
     *
     * @return string
     */
    string dapatkan_nama();

    /**
     * @brief Mengembalikan harga dari entitas
     *
     * @return int
     */
    int dapatkan_harga();

    // Operator Overloading

    /**
     * @brief Membandingkan 2 entitas
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator==(Entitas& other);

    // Print Info

    /**
     * @brief Virtual method untuk menampilkan info entitas
     *
     */
    virtual void print_info() = 0;
};


#endif
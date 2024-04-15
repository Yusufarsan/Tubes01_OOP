#ifndef PEMAIN_HPP
#define PEMAIN_HPP

// STL
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// User-defined
#include "../Entitas/Entitas.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/TanamanBuah.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"
#include "../Matriks/Matriks.hpp"
#include "../Toko/Toko.hpp"

using namespace std;


class Pemain {
protected:
    string nama;
    Matrix<Entitas> peti;
    int uang;
    int berat_badan;

public:
    // Constructor & Destructor

    /**
     * @brief Construct a new Pemain object
     *
     * @param nama
     * @param uang
     * @param berat_badan
     * @param ukuran_peti
     */
    Pemain(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti);

    /**
     * @brief Destroy the Pemain object
     *
     */
    virtual ~Pemain() {};

    // Getter & Setter

    /**
     * @brief Mengembalikan nama pemain
     *
     * @return string
     */
    string dapatkan_nama();

    /**
     * @brief Mengembalikan berat badan pemain
     *
     * @return int
     */
    int dapatkan_berat_badan();

    /**
     * @brief Mengembalikan peti pemain
     *
     * @return Matrix<Entitas>
     */
    Matrix<Entitas> dapatkan_peti();

    /**
     * @brief Mengembalikan uang pemain
     *
     * @return int
     */
    int dapatkan_uang();

    /**
     * @brief Mengatur uang pemain
     *
     * @param uang
     */
    void atur_uang(int uang);

    /**
     * @brief Mengatur berat badan pemain
     *
     * @param berat
     */
    void atur_berat_badan(int berat);

    // Method

    /**
     * @brief Menambahkan entitas ke dalam peti
     *
     * @param val
     */
    void tambah_peti(shared_ptr<Entitas> val);

    /**
     * @brief Menambahkan entitas ke dalam peti pada slot tertentu
     *
     * @param slot
     * @param val
     */
    void tambah_peti(string slot, shared_ptr<Entitas> val);

    /**
     * @brief Mengembalikan konfigurasi produk yang diinginkan
     *
     * @param daftarProduk
     * @param nama
     * @return tuple<int, int>
     */
    tuple<int, int> dapatkan_konfig_produk(vector<shared_ptr<Produk>> daftarProduk, string nama);

    /**
     * @brief Mengecek apakah item di inventory bisa dimakan
     *
     * @param slot
     * @return true
     * @return false
     */
    bool cek_bisa_dimakan(const string& slot);

    // Command

    /**
     * @brief Melakukan command jual
     *
     * @param toko
     */
    void jual(Toko& toko);

    /**
     * @brief Melakukan command beli
     *
     * @param toko
     */
    void membeli(Toko& toko);

    /**
     * @brief Melakukan command makan
     *
     */
    void makan();

    // Operator Overloading

    /**
     * @brief Operator overloading untuk print info pemain
     *
     * @return ostream&
     */
    friend ostream& operator<<(ostream&, Pemain);

    // Print Info

    /**
     * @brief Mencetak isi peti pemain
     *
     */
    void cetak_peti();
};

#endif
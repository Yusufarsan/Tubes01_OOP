#ifndef TOKO_HPP
#define TOKO_HPP

// STL
#include <iostream>
#include <vector>
#include <memory>

// User-defined
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Produk/Produk.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Toko {
private:
    vector<shared_ptr<Tanaman>> tanaman;
    vector<shared_ptr<Hewan>> hewan;
    map<shared_ptr<Produk>, int> produk;
    map<shared_ptr<Bangunan>, int> bangunan;
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Toko object
     *
     */
    Toko();

    /**
     * @brief Destroy the Toko object
     *
     */
    ~Toko();

    /**
     * @brief Construct a new Toko object
     *
     * @param other
     */
    Toko(const Toko& other);

    /**
     * @brief Men-assign objek toko dengan toko lain
     *
     * @param other
     * @return Toko&
     */
    Toko& operator=(const Toko& other);

    // Getter & Setter

    /**
     * @brief Mengembalikan entitas ke-num
     *
     * @param num
     * @return shared_ptr<Entitas>
     */
    shared_ptr<Entitas> dapatkan_entitas(int num);

    /**
     * @brief Mengembalikan jumlah produk
     *
     * @return int
     */
    int dapatkan_jumlah_produk();

    /**
     * @brief Mengembalikan jumlah bangunan
     *
     * @return int
     */
    int dapatkan_jumlah_bangunan();

    /**
     * @brief Mengembalikan daftar produk
     *
     * @param i
     * @return tuple<shared_ptr<Produk>, int>
     */
    tuple<shared_ptr<Produk>, int> dapatkan_produk(int i);

    /**
     * @brief Mengembalikan daftar bangunan
     *
     * @param i
     * @return tuple<shared_ptr<Bangunan>, int>
     */
    tuple<shared_ptr<Bangunan>, int> dapatkan_bangunan(int i);

    /**
     * @brief Mengatur tanaman
     *
     * @param t
     */
    void atur_tanaman(vector<shared_ptr<Tanaman>> t);

    /**
     * @brief Mengatur hewan
     *
     * @param h
     */
    void atur_hewan(vector<shared_ptr<Hewan>> h);

    // Method

    /**
     * @brief Memasukkan entitas ke dalam toko
     *
     * @param Entitas
     */
    void masukanEntitas(shared_ptr<Entitas> Entitas);

    /**
     * @brief Menambahkan produk ke dalam toko
     *
     * @param p
     */
    void tambah_produk(shared_ptr<Produk> p);

    /**
     * @brief Menambahkan bangunan ke dalam toko
     *
     * @param b
     */
    void tambah_bangunan(shared_ptr<Bangunan> b);

    /**
     * @brief Mengurangi produk dari toko
     *
     * @param p
     */
    void kurangi_produk(shared_ptr<Produk> p);

    /**
     * @brief Menguangi bangunan dari toko
     *
     * @param b
     */
    void kurangi_bangunan(shared_ptr<Bangunan> b);

    // Print Info

    /**
     * @brief Menampilkan isi toko
     *
     */
    void cetak_isi_toko();

    /**
     * @brief Menampilkan barang-barang yang ada di toko
     *
     * @param isWalikota
     */
    void tampilBarang(bool isWalikota);
};

#endif
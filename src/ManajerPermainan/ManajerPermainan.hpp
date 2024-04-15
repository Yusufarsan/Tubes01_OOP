#ifndef MANAGERPERMAINAN_HPP
#define MANAGERPERMAINAN_HPP

// STL
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

// User-defined
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"
#include "../Toko/Toko.hpp"

using namespace std;

class ManagerPermainan {
private:
    // State Pemain
    vector<shared_ptr<Pemain>> daftar_pemain;
    int giliran;
    int jumlah_pemain;
    tuple<int, int> besar_penyimpanan;
    tuple<int, int> besar_lahan;
    tuple<int, int> besar_peternakan;

    // State Konfigurasi
    vector<shared_ptr<Tanaman>> daftar_tanaman;
    vector<shared_ptr<Hewan>> daftar_hewan;
    vector<shared_ptr<Produk>> daftar_produk;
    vector<shared_ptr<Bangunan>> daftar_bangunan;

    // State Toko
    Toko toko;

    // State Memenangkan Permainan
    int uang_pemenang;
    int berat_pemenang;
public:
    // Constructor & Destructor

    /**
     * @brief Construct a new Manager Permainan object
     *
     * @param path
     */
    ManagerPermainan(string path);

    /**
     * @brief Destroy the Manager Permainan object
     *
     */
    ~ManagerPermainan();

    // Getter & Setter

    /**
     * @brief Mengembalikan daftar pemain
     *
     * @return vector<shared_ptr<Pemain>>
     */
    vector<shared_ptr<Pemain>> dapatkan_daftar_pemain();

    /**
     * @brief Mengembalikan pemain sekarang
     *
     * @return shared_ptr<Pemain>
     */
    shared_ptr<Pemain> pemain_skrg();

    /**
     * @brief Mengembalikan besar penyimpanan
     *
     * @return tuple<int, int>
     */
    tuple<int, int> dapatkanBesarPenyimpanan() const;

    /**
     * @brief Mengembalikan besar lahan
     *
     * @return tuple<int, int>
     */
    tuple<int, int> dapatkanBesarLahan() const;

    /**
     * @brief Mengembalikan besar peternakan
     *
     * @return tuple<int, int>
     */
    tuple<int, int> dapatkanBesarPeternakan() const;

    /**
     * @brief Mengembalikan toko
     *
     * @return Toko
     */
    Toko dapatkan_toko();

    /**
     * @brief Mengatur daftar pemain
     *
     * @param path
     */
    void atur_pemain(string path);

    /**
     * @brief Mengatur daftar pemain
     *
     * @param daftarPemain
     */
    void atur_pemain(vector<shared_ptr<Pemain>> daftarPemain);

    // Method

    /**
     * @brief Mengurutkan daftar pemain berdasarkan leksikografis
     *
     */
    void sort_daftar_pemain();

    /**
     * @brief Menginisialisasi toko
     *
     */
    void inisialisasi_toko();

    // Command Permainan

    /**
     * @brief Melanjutkan ke pemain selanjutnya
     *
     */
    void next();

    /**
     * @brief Mencetak penyimpanan pemain sekarang
     *
     */
    void cetak_penyimpanan();

    /**
     * @brief Memungut pajak dari pemain
     *
     */
    void pungut_pajak();    // validasi user

    /**
     * @brief Mencetak ladang pemain sekarang
     *
     */
    void cetak_ladang();    // validasi user

    /**
     * @brief Mencetak peternakan pemain sekarang
     *
     */
    void cetak_peternakan();    // validasi user

    /**
     * @brief Melakukan command tanam
     *
     */
    void tanam();    // validasi user

    /**
     * @brief Melakukan command ternak
     *
     */
    void ternak();   // validasi user

    /**
     * @brief Melakukan command bangun
     *
     */
    void bangun();   // validasi user

    /**
     * @brief Melakukan command makan
     *
     */
    void makan();

    /**
     * @brief Memberikan makanan ke hewan
     *
     */
    void kasih_makan();  // validasi user

    /**
     * @brief Melakukan command beli
     *
     */
    void beli();

    /**
     * @brief Melakukan command jual
     *
     */
    void jual();

    /**
     * @brief Melakukan command panen
     *
     */
    void panen(); // ada peternak dan petani

    /**
     * @brief Melakukan command muat
     *
     */
    void muat();

    /**
     * @brief Menginisialisasi pemain
     *
     */
    void inisialisasi_pemain();

    /**
     * @brief Melakukan command simpan
     *
     */
    void simpan();

    /**
     * @brief Menambahkan pemain
     *
     */
    void tambah_pemain();   // validasi user

    /**
     * @brief Keluar dari permainan
     *
     */
    void keluar();

    // Print Info

    /**
     * @brief Mencetak konfigurasi
     *
     */
    void print_konfigurasi();

    void info_pemain();
};

#endif
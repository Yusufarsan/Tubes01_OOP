#ifndef PETANI_HPP
#define PETANI_HPP

// STL
#include <utility>
#include <cmath>
#include <tuple>
#include <random>
#include <unordered_map>
#include <functional> // Untuk menggunakan std::hash

// User-defined
#include "Pemain.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Matriks/Matriks.hpp"
#include "../Pcolor/Pcolor.hpp"
#include "../Tanaman/TanamanMaterial.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"

using namespace std;

class Petani : public Pemain {
private:
    Matrix<Tanaman> ladang;

public:
    /**
     * @brief  Hash function untuk pair
     *
     */
    class pair_hash {
    public:
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& pair) const {
            // Kombinasi hash dari dua kunci dalam pair
            return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
        }
    };

    // Constructor dan Destructor

    /**
     * @brief Construct a new Petani object
     *
     * @param nama
     * @param uang
     * @param berat_badan
     * @param ukuran_peti
     * @param ukuran_ladang
     */
    Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang); // ctor

    /**
     * @brief Destroy the Petani object
     *
     */
    ~Petani(); // dtor

    // Getter

    /**
     * @brief Mengembalikan ladang
     *
     * @return Matrix<Tanaman>
     */
    Matrix<Tanaman> dapatkan_ladang();

    // Method

    /**
     * @brief Mengembalikan jumlah slot efektif ladang
     *
     * @return int
     */
    int jumlah_slot_efektif_ladang();

    /**
     * @brief Mengembalikan jumlah slot kosong ladang
     *
     * @return int
     */
    int jumlah_slot_kosong_ladang();

    /**
     * @brief Mengecek apakah slot ladang valid
     *
     * @param slot
     * @return true
     * @return false
     */
    bool cek_slot_ladang_valid(const string& slot);

    /**
     * @brief Mengecek apakah ladang penuh
     *
     * @return true
     * @return false
     */
    bool cek_ladang_penuh();

    /**
     * @brief Mengecek apakah ladang kosong
     *
     * @return true
     * @return false
     */
    bool cek_ladang_kosong();

    /**
     * @brief Menambahkan tanaman ke ladang
     *
     * @param slot
     * @param val
     */
    void tambah_ladang(string slot, shared_ptr<Tanaman> val);

    /**
     * @brief Menambah semua umur tanaman di ladang sebanyak 1
     *
     */
    void next_umur();     // Nambahin semua umur tanaman yg di tanem sebanyak 1 karena efek command next

    /**
     * @brief Mengembalikan frekuensi panen
     *
     * @return unordered_map<pair<string, string>, int, Petani::pair_hash>
     */
    unordered_map<pair<string, string>, int, Petani::pair_hash> frekuensi_panen();

    // Command 

    /**
     * @brief Melakukan command tanam
     *
     */
    void tanam();

    /**
     * @brief Melakukan command panen
     *
     * @param daftarProduk
     */
    void panen(vector<shared_ptr<Produk>> daftarProduk);

    /**
     * @brief Menghitung pajak yang harus dibayar
     *
     * @return int
     */
    int hitung_pajak();

    // Print Info

    /**
     * @brief Mencetak ladang
     *
     */
    void cetak_ladang();

    /**
     * @brief Mencetak frekuensi panen
     *
     * @param frequencyMap
     * @return tuple<vector<string>, vector<string>, int>
     */
    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string, string>, int, Petani::pair_hash> frequencyMap);
};

#endif
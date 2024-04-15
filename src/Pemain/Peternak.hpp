#ifndef PETERNAK_HPP
#define PETERNAK_HPP

// STL
#include <unordered_map>
#include <cmath>

// User-defined
#include "Pemain.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include "../Pcolor/Pcolor.hpp"
#include "../Matriks/Matriks.hpp"

using namespace std;

class Peternak : public Pemain {
private:
    Matrix<Hewan> peternakan;

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

    // Constructor & Destructor

    /**
     * @brief Construct a new Peternak object
     *
     * @param nama
     * @param uang
     * @param berat_badan
     * @param ukuran_peti
     * @param ukuran_peternakan
     */
    Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan);

    /**
     * @brief Destroy the Peternak object
     *
     */
    ~Peternak();

    // Getter

    /**
     * @brief Mengembalikan peternakan
     *
     * @return Matrix<Hewan>
     */
    Matrix<Hewan> dapatkan_peternakan();

    // Method

    /**
     * @brief Mengecek apakah slot peternakan valid
     *
     * @param slot
     * @return true
     * @return false
     */
    bool cek_slot_peternakan_valid(string slot);

    /**
     * @brief Mengecek apakah peternakan penuh
     *
     * @return true
     * @return false
     */
    bool cek_peternakan_penuh();

    /**
     * @brief Mengecek apakah peternakan kosong
     *
     * @return true
     * @return false
     */
    bool cek_peternakan_kosong();

    /**
     * @brief Mengembalikan jumlah slot efektif peternakan
     *
     * @return int
     */
    int jumlah_slot_efektif_peternakan();

    /**
     * @brief Mengecek apakah slot peternakan kosong
     *
     * @return int
     */
    int jumlah_slot_kosong_peternakan();

    /**
     * @brief Menambahkan hewan ke peternakan
     *
     * @param slot
     * @param val
     */
    void tambah_peternakan(string slot, shared_ptr<Hewan> val);

    /**
     * @brief Mengembalikan frekuensi panen
     *
     * @return unordered_map<pair<string, string>, int, Peternak::pair_hash>
     */
    unordered_map<pair<string, string>, int, Peternak::pair_hash> frekuensi_panen();

    // Command

    /**
     * @brief Memberi pangan ke hewan
     *
     */
    void beri_pangan();

    /**
     * @brief Melakukan command ternak
     *
     */
    void ternak();

    /**
     * @brief Melakukan command panen
     *
     * @param daftarProduk
     */
    void panen(vector<shared_ptr<Produk>> daftarProduk);

    /**
     * @brief Menghtung pajak yang harus dibayar
     *
     * @return int
     */
    int hitung_pajak();

    // Print Info

    /**
     * @brief Mencetak peternakan
     *
     */
    void cetak_peternakan();

    /**
     * @brief Menampilkan panen
     *
     * @param frequencyMap
     * @return tuple<vector<string>, vector<string>, int>
     */
    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap);
};

#endif
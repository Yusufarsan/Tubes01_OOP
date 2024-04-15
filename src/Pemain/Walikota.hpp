#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

// STL
#include <cmath>
#include <algorithm>
#include <iostream>

// User-defined
#include "Pemain.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include "../Util/Util.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Walikota : public Pemain {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Walikota object
     *
     * @param nama
     * @param uang
     * @param berat_badan
     * @param ukuran_peti
     */
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor

    /**
     * @brief Construct a new Walikota object
     *
     * @param other
     */
    Walikota(const Walikota& other); // cctor

    /**
     * @brief Destroy the Walikota object
     *
     */
    ~Walikota(); // dtor

    // Method

    /**
     * @brief Mengecek apakah nama pemain sudah terdaftar
     *
     * @param daftarPemain
     * @param namaPemain
     * @return true
     * @return false
     */
    bool apakah_nama_terdaftar(vector<shared_ptr<Pemain>>* daftarPemain, string namaPemain);

    /**
     * @brief Membandingkan pajak pemain
     *
     * @param a
     * @param b
     * @return true
     * @return false
     */
    static bool bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b);

    /**
     * @brief Mengecek apakah jenis pemain valid
     *
     * @param jenisPemain
     * @return true
     * @return false
     */
    bool jenis_pemain_valid(string jenisPemain);

    // Method bantuan untuk method bangun()

    /**
     * @brief Mencetak resep semua bangunan
     *
     * @param daftar_bangunan
     */
    void cetak_resep_semua_bangunan(vector<shared_ptr<Bangunan>> daftar_bangunan);

    /**
     * @brief Mengecek apakah bahan cukup
     *
     * @param bangunan
     * @return true
     * @return false
     */
    bool cek_bahan(shared_ptr<Bangunan> bangunan);

    // Command

    /**
     * @brief Menagih pajak dari semua pemain
     *
     * @param daftar_pemain
     */
    void tagih_pajak(vector<shared_ptr<Pemain>>& daftar_pemain);

    /**
     * @brief Melakukan command bangun
     *
     * @param daftar_bangunan
     */
    void bangun(vector<shared_ptr<Bangunan>> daftar_bangunan);

    /**
     * @brief Menambahkan pemain baru
     *
     * @param daftarPemain
     * @param ukuranPenyimpanan
     * @param beratAwal
     * @param besar_lahan
     * @param besar_peternakan
     */
    void tambah_pemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int, int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan);
};

#endif
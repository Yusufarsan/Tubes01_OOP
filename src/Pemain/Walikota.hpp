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
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor
    Walikota(const Walikota& other); // cctor
    ~Walikota(); // dtor

    // Method
    bool apakah_nama_terdaftar(vector<shared_ptr<Pemain>>* daftarPemain, string namaPemain);
    static bool bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b);
    bool jenis_pemain_valid(string jenisPemain);

    // Method bantuan untuk method bangun()
    void cetak_resep_semua_bangunan(vector<shared_ptr<Bangunan>> daftar_bangunan);
    bool cek_bahan(shared_ptr<Bangunan> bangunan);

    // Command
    void tagih_pajak(vector<shared_ptr<Pemain>>& daftar_pemain);
    void bangun(vector<shared_ptr<Bangunan>> daftar_bangunan);
    void tambah_pemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int, int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan);
};

#endif
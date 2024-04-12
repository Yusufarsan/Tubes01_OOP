#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Pemain.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include <cmath>

class Walikota : public Pemain {
public:
    
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor
    Walikota(const Walikota& other); // cctor
    ~Walikota(); // dtor

    static bool bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b);
    void tagih_pajak(vector<shared_ptr<Pemain>>);
    
    // Method bantuan untuk method bangun()
    void cetak_resep_semua_bangunan(vector<Bangunan> daftar_bangunan);
    bool cek_bahan(Bangunan bangunan);
    
    void bangun(vector<Bangunan> daftar_bangunan);
    void tambahPemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int,int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan);

};

#endif
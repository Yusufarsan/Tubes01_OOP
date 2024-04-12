#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"

class Peternak : public Pemain {
private:
    Matrix<Hewan> peternakan;
public:
    Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan);
    ~Peternak();

    void cetak_peternakan();
    bool cek_slot_peternakan_valid(string slot);
    bool cek_peternakan_penuh();
    bool cek_peternakan_kosong();
    int jumlah_slot_kosong_peternakan();

    void ternak();
    void tambah_peternakan(string slot, Hewan* val);
    Hewan* hapus_peternakan(string slot);
    void beri_pangan();
    void panen();
    int hitung_pajak();
};

#endif
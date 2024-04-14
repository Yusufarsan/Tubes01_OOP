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
    // Hash function untuk pair
    class pair_hash {
    public:
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& pair) const {
            // Kombinasi hash dari dua kunci dalam pair
            return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
        }
    };

    // Constructor & Destructor
    Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan);
    ~Peternak();

    // Getter
    Matrix<Hewan> dapatkan_peternakan();

    // Method
    bool cek_slot_peternakan_valid(string slot);
    bool cek_peternakan_penuh();
    bool cek_peternakan_kosong();
    int jumlah_slot_efektif_peternakan();
    int jumlah_slot_kosong_peternakan();
    void tambah_peternakan(string slot, shared_ptr<Hewan> val);
    unordered_map<pair<string, string>, int, Peternak::pair_hash> frekuensi_panen();

    // Command
    void beri_pangan();
    void ternak();
    void panen(vector<shared_ptr<Produk>> daftarProduk);
    int hitung_pajak();

    // Print Info
    void cetak_peternakan();
    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap);
};

#endif
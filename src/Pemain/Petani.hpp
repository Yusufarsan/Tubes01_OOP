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
    // Hash function untuk pair<string, string>
    class pair_hash {
    public:
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& pair) const {
            // Kombinasi hash dari dua kunci dalam pair
            return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
        }
    };

    // Constructor dan Destructor
    Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang); // ctor
    ~Petani(); // dtor

    // Getter
    Matrix<Tanaman> dapatkan_ladang();

    // Method
    int jumlah_slot_efektif_ladang();
    int jumlah_slot_kosong_ladang();
    bool cek_slot_ladang_valid(const string& slot);
    bool cek_ladang_penuh();
    bool cek_ladang_kosong();
    void tambah_ladang(string slot, shared_ptr<Tanaman> val);
    void next_umur();     // Nambahin semua umur tanaman yg di tanem sebanyak 1 karena efek command next
    unordered_map<pair<string, string>, int, Petani::pair_hash> frekuensi_panen();

    // Command 
    void tanam();
    void panen();
    int hitung_pajak();

    // Print Info
    void cetak_ladang();
    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string, string>, int, Petani::pair_hash> frequencyMap);
};

#endif
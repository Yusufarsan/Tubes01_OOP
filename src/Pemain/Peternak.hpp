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
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        // Kombinasi hash dari dua kunci dalam pair
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};
private:
    Matrix<Hewan> peternakan;

    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string,string>, int, pair_hash> frequencyMap);

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
    unordered_map<pair<string, string>, int, pair_hash> frekuensi_panen(){
        unordered_map<pair<string, string>, int, pair_hash> frequencyMap;

        // Iterate over the elements of Peternakan matriks
        for (int i=0; i<peternakan.dapatkanBaris(); i++) {
            for (int j=0; j<peternakan.dapatkanKolom(); j++){
                Hewan* hew = peternakan.dapatkanElemen(i,j);
                if (hew!=nullptr && hew->bisa_panen()) {
                    // Increment the frequency count for the  hewan's name
                    frequencyMap[make_pair(hew->dapatkan_kode_huruf(),hew->dapatkan_nama())]++;
                }
            }
        }
        return frequencyMap;
    }
    Hewan* hapus_peternakan(string slot);
    void beri_pangan();
    void panen();
};

#endif
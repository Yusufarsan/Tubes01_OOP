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
#include <unordered_map>

class Peternak : public Pemain {
private:
    Matrix<Hewan> peternakan;


public:
    class pair_hash {
        public:
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& pair) const {
            // Kombinasi hash dari dua kunci dalam pair
            return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
        }
    };
    Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan);
    ~Peternak();

    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap);
    void cetak_peternakan();
    bool cek_slot_peternakan_valid(string slot);
    bool cek_peternakan_penuh();
    bool cek_peternakan_kosong();
    int jumlah_slot_efektif_peternakan();
    int jumlah_slot_kosong_peternakan();
    Matrix<Hewan> dapatkan_peternakan();

    void ternak();
    void tambah_peternakan(string slot, shared_ptr<Hewan> val);
    
    unordered_map<pair<string, string>, int, Peternak::pair_hash> frekuensi_panen(){
        unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap;

        // Iterate over the elements of Peternakan matriks
        for (int i=0; i<peternakan.dapatkanBaris(); i++) {
            for (int j=0; j<peternakan.dapatkanKolom(); j++){
                shared_ptr<Hewan> hew = peternakan.dapatkan_elemen(i,j);
                if (hew!=nullptr && hew.get()->bisa_panen()) {
                    // Increment the frequency count for the  hewan's name
                    frequencyMap[make_pair(hew.get()->dapatkan_kode_huruf(),hew.get()->dapatkan_nama())]++;
                }
            }
        }
        return frequencyMap;
    }
    // Hewan* hapus_peternakan(string slot);
    void beri_pangan();
    void panen();
    int hitung_pajak();
};

#endif
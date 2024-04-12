#ifndef PETANI_HPP
#define PETANI_HPP


#include "Pemain.hpp"
#include "../Tanaman/Tanaman.hpp"
#include <unordered_map>
#include "../Matriks/Matriks.hpp"

class Petani : public Pemain {
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        // Kombinasi hash dari dua kunci dalam pair
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};
private:
    Matrix<Tanaman> ladang;

    tuple<vector<string>, vector<string>, int> tampilkanPanen(unordered_map<pair<string,string>, int, pair_hash> frequencyMap);
public:
    Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang); // ctor
    ~Petani(); // dtor

    void cetak_ladang();
    bool cek_slot_ladang_valid(const string& slot);
    bool cek_ladang_penuh();
    bool cek_ladang_kosong();
    int jumlah_slot_efektif_ladang();
    int jumlah_slot_kosong_ladang();
    Matrix<Tanaman> dapatkan_ladang();

    void tanam();
    void tambah_ladang(string slot, Tanaman& val);
    Tanaman* hapus_ladang(string slot);
    unordered_map<pair<string, string>, int, pair_hash> frekuensi_panen(){
        unordered_map<pair<string, string>, int, pair_hash> frequencyMap;

        // Iterate over the elements of ladang matriks
        for (int i=0; i<ladang.dapatkanBaris(); i++) {
            for (int j=0; j<ladang.dapatkanKolom(); j++){
                Tanaman* tan = ladang.dapatkanElemen(i,j);
                if (tan!=nullptr && tan->bisa_panen()) {
                    // Increment the frequency count for the Tanaman's name
                    frequencyMap[make_pair(tan->dapatkan_kode_huruf(),tan->dapatkan_nama())]++;
                }
            }
        }
        return frequencyMap;
    }
    void panen();
    void next_umur();     // Nambahin semua umur tanaman yg di tanem sebanyak 1 karena efek command next
    int hitung_pajak();
};

#endif
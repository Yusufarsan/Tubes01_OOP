#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../Entitas/Entitas.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Util/Util.hpp"
#include <iostream>
#include <vector>

using namespace std;


class Pemain{
    protected:
        string nama;
        vector<vector<Entitas*>> peti;
        int uang;
        int berat_badan;
    
    public:
        Pemain(string nama, int uang, int berat_badan);
        ~Pemain(){};

        string dapatkan_nama();
        void atur_uang(int uang);
        int dapatkan_uang();
        void atur_berat_badan(int berat);
        int dapatkan_berat_badan();
        
        void cetak_peti();
        void tambah_peti(string slot, Entitas& val);
        Entitas* hapus_peti(string slot);
        bool cek_slot_peti_valid(string slot);
        int jumlah_slot_kosong_peti();

        void jual();
        void beli();
        void makan();

        friend ostream& operator<<(ostream &, Pemain);
};

#endif
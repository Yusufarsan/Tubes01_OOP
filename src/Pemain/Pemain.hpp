#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../Entitas/Entitas.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/TanamanBuah.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Pemain{
    protected:
        string nama;
        vector<vector<shared_ptr<Entitas>>> peti;
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
        // void tambah_peti(string slot, Entitas& val);
        template<class T>
        void tambah_peti(const string& slot, T& val){
            if (cek_slot_peti_valid(slot)){
                int i = Util::indeks_baris_slot(slot);
                int j = Util::indeks_kolom_slot(slot);

                if (!peti[i][j]){
                    peti[i][j] = make_shared<T>(val);;
                }
                else{
                    cout << "Ada isinya" << endl;
                }
            }
            else{
                cout << "index out of bonds" << endl;
            }
        }

        Entitas* hapus_peti(const string& slot);
        bool cek_slot_peti_valid(const string& slot);
        int jumlah_slot_kosong_peti();
        bool cek_bisa_dimakan(const string& slot);

        void jual();
        void beli();
        void makan();

        friend ostream& operator<<(ostream &, Pemain);
};

#endif
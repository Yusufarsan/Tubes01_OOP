#include "../Entitas/Entitas.hpp"
#include <iostream>
#include <vector>

using namespace std;


class Pemain{
    protected:
        string nama;
        vector<vector<Entitas>> peti;
        int uang;
        int berat_badan;
    
    public:
        Pemain(string nama, int uang, int berat_badan);
        ~Pemain();

        string dapatkan_nama(); // getter
        void atur_uang(int uang); // setter
        int dapatkan_uang(); // getter
        void atur_berat_badan(int berat); // setter
        int dapatkan_berat_badan(); // getter
        
        void cetak_peti();
        void tambah_peti(string slot, Entitas* val);
        Entitas* hapus_peti(string slot);
        bool cek_slot_peti(string slot);        // cek slot ada di peti atau tidak

        void jual();
        void beli();
        void makan();
};
#ifndef PETANI_HPP
#define PETANI_HPP


#include "Pemain.hpp"
#include "../Tanaman/Tanaman.hpp"

class Petani: public Pemain{
    private:
        vector<vector<shared_ptr<Tanaman>>> ladang;
    public:
        Petani(string nama); // ctor
        ~Petani(); // dtor

        void cetak_ladang();
        bool cek_slot_ladang_valid(const string& slot);
        int jumlah_slot_kosong_ladang();
        
        void tanam();
        void tambah_ladang(string slot, Tanaman& val);
        Tanaman* hapus_ladang(string slot);
        void panen();
        int hitung_pajak();
};

#endif
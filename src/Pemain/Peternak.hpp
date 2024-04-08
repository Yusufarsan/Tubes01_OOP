#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"
#include "../Hewan/Hewan.hpp"

class Peternak: public Pemain{
    private:
        vector<vector<Hewan*>> peternakan;
    public:
        Peternak(string nama);
        ~Peternak();
        
        void cetak_peternakan(bool isWarna);
        bool cek_slot_peternakan_valid(string slot);
        void ternak();
        void tambah_peternakan(string slot, Hewan& val);
        Hewan* hapus_peternakan(string slot);
        void beri_pangan();
        void panen();
        int hitung_pajak();
};

#endif
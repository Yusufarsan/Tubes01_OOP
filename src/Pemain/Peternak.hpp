#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"
#include "../Hewan/Hewan.hpp"

class Peternak : public Pemain {
private:
    vector<vector<shared_ptr<Hewan>>> peternakan;
public:
    Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan);
    ~Peternak();

    void cetak_peternakan();
    bool cek_slot_peternakan_valid(string slot);
    void ternak();
    void tambah_peternakan(string slot, shared_ptr<Hewan> val);
    Hewan* hapus_peternakan(string slot);
    void beri_pangan();
    void panen();
    int hitung_pajak();
};

#endif
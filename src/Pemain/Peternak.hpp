#include "Pemain.hpp"
#include "../Hewan/Hewan.hpp"

class Peternak: public Pemain{
    protected:
        vector<vector<Hewan>> peternakan;
    public:
        Peternak(string nama);
        Peternak(const Peternak& other); // cctor
        ~Peternak(); // dtor
        
        void cetak_peternakan();
        void ternak();
        void tambah_peternakan(string slot, Entitas val);
        Hewan hapus_peternakan(string slot);
        void kasih_makan();
        void panen();
        int hitung_pajak();
};
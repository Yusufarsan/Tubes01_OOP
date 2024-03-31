#include "Pemain.hpp"
#include "../Tanaman/Tanaman.hpp"

class Petani: public Pemain{
    protected:
        vector<vector<Tanaman>> ladang;
    public:
        Petani(string nama); // ctor
        Petani(const Petani& other); // cctor
        ~Petani(); // dtor

        void cetak_ladang();
        void tanam();
        void tambah_ladang(string slot, Entitas val);
        Tanaman hapus_ladang(string slot);
        void panen();
        int hitung_pajak();
};
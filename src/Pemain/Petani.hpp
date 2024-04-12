#ifndef PETANI_HPP
#define PETANI_HPP


#include "Pemain.hpp"
#include "../Tanaman/Tanaman.hpp"
#include <unordered_map>
#include "../Matriks/Matriks.hpp"

class Petani : public Pemain {
private:
    Matrix<Tanaman> ladang;
public:
    Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang); // ctor
    ~Petani(); // dtor

    void cetak_ladang();
    bool cek_slot_ladang_valid(const string& slot);
    bool cek_ladang_penuh();
    bool cek_ladang_kosong();
    int jumlah_slot_kosong_ladang();

    void tanam();
    void tambah_ladang(string slot, Tanaman& val);
    Tanaman* hapus_ladang(string slot);
    unordered_map<string, int> frekuensi_panen();
    void panen();
    void next_umur();     // Nambahin semua umur tanaman yg di tanem sebanyak 1 karena efek command next
};

#endif
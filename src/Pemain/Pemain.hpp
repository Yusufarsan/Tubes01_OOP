#ifndef PEMAIN_HPP
#define PEMAIN_HPP

// STL
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// User-defined
#include "../Entitas/Entitas.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/TanamanBuah.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"
#include "../Matriks/Matriks.hpp"
#include "../Toko/Toko.hpp"

using namespace std;


class Pemain {
protected:
    string nama;
    Matrix<Entitas> peti;
    int uang;
    int berat_badan;

public:
    // Constructor & Destructor
    Pemain(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti);
    virtual ~Pemain() {};

    // Getter & Setter
    string dapatkan_nama();
    int dapatkan_berat_badan();
    Matrix<Entitas> dapatkan_peti();
    void atur_uang(int uang);
    int dapatkan_uang();
    void atur_berat_badan(int berat);

    // Method
    void tambah_peti(shared_ptr<Entitas> val) {
        peti += val;
    }
    tuple<int,int> dapatkan_konfig_produk(vector<shared_ptr<Produk>> daftarProduk, string nama);

    void tambah_peti(string slot, shared_ptr<Entitas> val) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);
    
        peti.tambah_elemen_matriks(idxRow, idxCol, val);
    }

    bool cek_bisa_dimakan(const string& slot);

    // Command
    void jual(Toko& toko);
    void membeli(Toko& toko);
    void makan();

    // Operator Overloading
    friend ostream& operator<<(ostream&, Pemain);

    // Print Info
    void cetak_peti();
};

#endif
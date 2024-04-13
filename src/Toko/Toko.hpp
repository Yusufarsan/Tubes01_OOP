#ifndef TOKO_HPP
#define TOKO_HPP

// STL
#include <iostream>
#include <vector>
#include <memory>

// User-defined
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Produk/Produk.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Util/Util.hpp"

using namespace std;

class Toko {
private:
    vector<shared_ptr<Tanaman>> tanaman;
    vector<shared_ptr<Hewan>> hewan;
    map<shared_ptr<Produk>, int> produk;
    map<shared_ptr<Bangunan>, int> bangunan;
public:
    // 4 Sekawan
    Toko();
    ~Toko();
    Toko(const Toko& other);
    Toko& operator=(const Toko& other);

    // Getter & Setter
    shared_ptr<Entitas> dapatkan_entitas(int num);
    int dapatkan_jumlah_produk();
    int dapatkan_jumlah_bangunan();
    tuple<shared_ptr<Produk>, int> dapatkan_produk(int i);
    tuple<shared_ptr<Bangunan>, int> dapatkan_bangunan(int i);
    void atur_tanaman(vector<shared_ptr<Tanaman>> t);
    void atur_hewan(vector<shared_ptr<Hewan>> h);

    // Method
    void masukanEntitas(shared_ptr<Entitas> Entitas);
    void tambah_produk(shared_ptr<Produk> p);
    void tambah_bangunan(shared_ptr<Bangunan> b);
    void kurangi_produk(shared_ptr<Produk> p);
    void kurangi_bangunan(shared_ptr<Bangunan> b);

    // Print Info
    void cetak_isi_toko();
    void tampilBarang(bool isWalikota);
};

#endif
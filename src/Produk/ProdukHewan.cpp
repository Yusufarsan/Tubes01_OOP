#include "ProdukHewan.hpp"

ProdukHewan::ProdukHewan(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin) : 
Produk(id, kode_huruf, nama, harga, berat_tambahan, origin) {}

ProdukHewan::~ProdukHewan() {}

ProdukHewan::ProdukHewan(const ProdukHewan &produk) : Produk(produk) {}

ProdukHewan& ProdukHewan::operator=(const ProdukHewan &produk) {
    Produk::operator=(produk);
    return *this;
}

void ProdukHewan::print_info() {
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Berat Tambahan: " << berat_tambahan << endl;
    cout << "Origin: " << origin << endl;
}
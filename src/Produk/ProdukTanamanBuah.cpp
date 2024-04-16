#include "ProdukTanamanBuah.hpp"

// 4 Sekawan
ProdukTanamanBuah::ProdukTanamanBuah(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin) : Produk(id, kode_huruf, nama, harga, berat_tambahan, origin) {}

ProdukTanamanBuah::~ProdukTanamanBuah() {}

ProdukTanamanBuah::ProdukTanamanBuah(const ProdukTanamanBuah& produk) : Produk(produk) {}

ProdukTanamanBuah& ProdukTanamanBuah::operator=(const ProdukTanamanBuah& produk) {
    Produk::operator=(produk);
    return *this;
}

// Print Info
void ProdukTanamanBuah::print_info() {
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Berat Tambahan: " << berat_tambahan << endl;
    cout << "Origin: " << origin << endl;
}
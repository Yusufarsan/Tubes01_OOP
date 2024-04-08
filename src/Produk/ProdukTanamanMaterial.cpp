#include "ProdukTanamanMaterial.hpp"

ProdukTanamanMaterial::ProdukTanamanMaterial(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin) : Produk(id, kode_huruf, nama, harga, berat_tambahan, origin) {}

ProdukTanamanMaterial::~ProdukTanamanMaterial() {}

ProdukTanamanMaterial::ProdukTanamanMaterial(const ProdukTanamanMaterial& other) : Produk(other) {}

ProdukTanamanMaterial& ProdukTanamanMaterial::operator=(const ProdukTanamanMaterial& other) {
    Produk::operator=(other);
    return *this;
}

void ProdukTanamanMaterial::print_info() {
    cout << "Produk Tanaman Material" << endl;
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Berat Tambahan: " << berat_tambahan << endl;
    cout << "Origin: " << origin << endl;
}
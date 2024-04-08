#include "Produk.hpp"

Produk::Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin) : Entitas(id, kode_huruf, nama, harga), berat_tambahan(berat_tambahan), origin(origin) {}

Produk::~Produk() {}

Produk& Produk::operator=(const Produk &produk) {
    Entitas::operator=(produk);
    berat_tambahan = produk.berat_tambahan;
    origin = produk.origin;
    return *this;
}

void Produk::atur_berat_tambahan(int berat_tambahan) {
    this->berat_tambahan = berat_tambahan;
}

void Produk::atur_origin(string origin) {
    this->origin = origin;
}

int Produk::dapatkan_berat_tambahan() {
    return berat_tambahan;
}

string Produk::dapatkan_origin() {
    return origin;
}
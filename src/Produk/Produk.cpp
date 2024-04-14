#include "Produk.hpp"
#include "../Util/Util.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

int Produk::jumlah_produk = 0;

// 4 Sekawan
Produk::Produk(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin) : Entitas(id, kode_huruf, nama, harga), berat_tambahan(berat_tambahan), origin(origin) {
    jumlah_produk++;
}

Produk::Produk(string nama, string kode, string origin, int berat_tambahan, int harga): origin(origin), berat_tambahan(berat_tambahan), Entitas(to_string(dapatkan_jumlah_produk_saat_ini()), kode, nama, harga){
    jumlah_produk++;
}

Produk::~Produk() {jumlah_produk--;}

Produk& Produk::operator=(const Produk& produk) {
    Entitas::operator=(produk);
    berat_tambahan = produk.berat_tambahan;
    origin = produk.origin;
    jumlah_produk++;
    return *this;
}

// Getter & Setter
int Produk::dapatkan_jumlah_produk_saat_ini(){
    return jumlah_produk;
}
int Produk::dapatkan_berat_tambahan() {
    return berat_tambahan;
}

string Produk::dapatkan_origin() {
    return origin;
}

void Produk::atur_berat_tambahan(int berat_tambahan) {
    this->berat_tambahan = berat_tambahan;
}

void Produk::atur_origin(string origin) {
    this->origin = origin;
}

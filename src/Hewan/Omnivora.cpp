#include "Omnivora.hpp"

// 4 Sekawan
Omnivora::Omnivora(string id, string kode_huruf, string nama, int harga, int berat_panen) :Hewan(id, kode_huruf, nama, harga, berat_panen) {}

Omnivora::Omnivora(Omnivora& other) :Hewan(other) {}

Omnivora::~Omnivora() {}

Omnivora& Omnivora::operator=(const Omnivora& other) {
    Hewan::operator=(other);
    return *this;
}

// Command
void Omnivora::makan(Produk* makanan) {
    if (Util::instanceof<ProdukTanamanBuah>(makanan) || Util::instanceof<ProdukHewan>(makanan)) {
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Berhasil makan" << endl;
    }
    else {
        //mengeluarkan pesan error
        cout << "Tidak berhasil makan, masukan makanan yang sesuai" << endl;
    }
}

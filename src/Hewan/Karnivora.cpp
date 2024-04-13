#include "Karnivora.hpp"

// 4 Sekawan
Karnivora::Karnivora(string id, string kode_huruf, string nama, int harga, int berat_panen) :Hewan(id, kode_huruf, nama, harga, berat_panen) {}

Karnivora::Karnivora(Karnivora& other) :Hewan(other) {}

Karnivora::~Karnivora() {}

Karnivora& Karnivora::operator=(const Karnivora& other) {
    Hewan::operator=(other);
    return *this;
}

// Command
void Karnivora::makan(Produk* makanan) {
    if (Util::instanceof<ProdukHewan>(makanan)) {
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Berhasil makan" << endl;
    }
    else {
        //mengeluarkan pesan error
        cout << "Tidak berhasil makan, masukan makanan yang sesuai" << endl;
    }
}

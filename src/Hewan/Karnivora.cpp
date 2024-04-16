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
bool Karnivora::makan(Produk* makanan) {
    if (Util::instanceof<ProdukHewan>(makanan)) {
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Setelah memakan " << makanan->dapatkan_nama() << ", berat " << dapatkan_nama() << " menjadi " << dapatkan_berat() << endl;

        return true;
    }
    else {
        //mengeluarkan pesan error
        cout << dapatkan_nama() << " merupakan karnivora, Ia alergi dengan " << makanan->dapatkan_nama();

        return false;
    }
}

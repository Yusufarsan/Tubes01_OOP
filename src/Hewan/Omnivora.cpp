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
bool Omnivora::makan(Produk* makanan) {
    if (Util::instanceof<ProdukTanamanBuah>(makanan) || Util::instanceof<ProdukHewan>(makanan)) {
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Setelah memakan " << makanan->dapatkan_nama() << ", berat " << dapatkan_nama() << " menjadi " << dapatkan_berat() << endl;

        return true;
    }
    else {
        //mengeluarkan pesan error
        cout << dapatkan_nama() << " merupakan omnivora, Ia alergi dengan " << makanan->dapatkan_nama();

        return false;
    }
}

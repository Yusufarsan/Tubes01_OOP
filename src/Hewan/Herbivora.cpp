#include "Herbivora.hpp"

using namespace std;

// 4 Sekawan
Herbivora::Herbivora(string id, string kode_huruf, string nama, int harga, int berat_panen) :Hewan(id, kode_huruf, nama, harga, berat_panen) {}

Herbivora::Herbivora(Herbivora& other) :Hewan(other) {}

Herbivora::~Herbivora() {}

Herbivora& Herbivora::operator=(const Herbivora& other) {
    Hewan::operator=(other);
    return *this;
}

// Command
bool Herbivora::makan(Produk* makanan) {
    if (Util::instanceof<ProdukTanamanBuah>(makanan)) {
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Setelah memakan " << makanan->dapatkan_nama() << ", berat " << dapatkan_nama() << " menjadi " << dapatkan_berat() << endl;

        return true;
    }
    else {
        //mengeluarkan pesan error
        cout << dapatkan_nama() << " merupakan herbivora, Ia alergi dengan " << makanan->dapatkan_nama();

        return false;
    }
}

#include "./Toko.hpp"
#include "../Util/Util.hpp"

Toko::Toko() {}

// Toko::Toko(string path) {
//     this->tanaman = InputKonfigurasi::InputKonfigurasiTanaman(path + "/plant.txt");
//     this->hewan = InputKonfigurasi::InputKonfigurasiHewan(path + "/animal.txt");
// }

Toko::~Toko() {}

Toko::Toko(const Toko& other) {
    this->tanaman = other.tanaman;
    this->hewan = other.hewan;
    this->produk = other.produk;
    this->bangunan = other.bangunan;
}

Toko& Toko::operator=(const Toko& other) {
    if (this != &other) {
        this->tanaman = other.tanaman;
        this->hewan = other.hewan;
        this->produk = other.produk;
        this->bangunan = other.bangunan;
    }
    return *this;
}

void Toko::tampilBarang(bool isWalikota) {

}

void Toko::masukanEntitas(Entitas* Ent) {
    if (Util::instanceof<Bangunan>(Ent)) {
        shared_ptr<Bangunan> ptrBangunan(dynamic_cast<Bangunan*>(Ent));
        tambah_bangunan(ptrBangunan);
    }
    else if (Util::instanceof<Produk>(Ent)) {
        shared_ptr<Produk> ptrProduk(dynamic_cast<Produk*>(Ent));
        tambah_produk(ptrProduk);
    }
}

void Toko::atur_tanaman(vector<shared_ptr<Tanaman>> t) {
    this->tanaman = t;
}

void Toko::atur_hewan(vector<shared_ptr<Hewan>> h) {
    this->hewan = h;
}

int Toko::dapatkan_jumlah_produk() {
    return this->produk.size();
}

int Toko::dapatkan_jumlah_bangunan() {
    return this->bangunan.size();
}

tuple<shared_ptr<Produk>, int> Toko::dapatkan_produk(int i) {
    auto it = this->produk.begin();
    advance(it, i);
    return make_tuple(it->first, it->second);
}

tuple<shared_ptr<Bangunan>, int> Toko::dapatkan_bangunan(int i) {
    auto it = this->bangunan.begin();
    advance(it, i);
    return make_tuple(it->first, it->second);
}

void Toko::tambah_produk(shared_ptr<Produk> p) {
    this->produk[p]++;
}

void Toko::tambah_bangunan(shared_ptr<Bangunan> b) {
    this->bangunan[b]++;
}

void Toko::cetak_isi_toko() {
    cout << "Daftar Tanaman:" << endl;
    for (int i = 0; i < this->tanaman.size(); i++) {
        this->tanaman[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Hewan:" << endl;
    for (int i = 0; i < this->hewan.size(); i++) {
        this->hewan[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Produk:" << endl;
    for (auto it = this->produk.begin(); it != this->produk.end(); it++) {
        it->first->print_info();
        cout << "Jumlah: " << it->second << endl;
        cout << endl;
    }

    cout << "Daftar Bangunan:" << endl;
    for (auto it = this->bangunan.begin(); it != this->bangunan.end(); it++) {
        it->first->print_info();
        cout << "Jumlah: " << it->second << endl;
        cout << endl;
    }
}
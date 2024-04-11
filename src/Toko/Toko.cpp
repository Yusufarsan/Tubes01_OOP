#include "./Toko.hpp"

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

bool Toko::operator==(const Toko& other){
    if()
}

void Toko::atur_tanaman(vector<shared_ptr<Tanaman>> t) {
    this->tanaman = t;
}

void Toko::atur_hewan(vector<shared_ptr<Hewan>> h) {
    this->hewan = h;
}

void Toko::tambah_produk(shared_ptr<Produk> p) {
    this->produk[p] += 1;
}

void Toko::tambah_bangunan(shared_ptr<Bangunan> b) {
    this->bangunan[b] += 1;
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
#include "./Toko.hpp"

// 4 Sekawan
Toko::Toko() {}

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

// Getter & Setter
shared_ptr<Entitas> Toko::dapatkan_entitas(int num) {
    if (num <= this->tanaman.size()) {
        return this->tanaman[num - 1];
    }
    else if (num <= this->tanaman.size() + this->hewan.size()) {
        return this->hewan[num - 1 - this->tanaman.size()];
    }
    else if (num <= this->tanaman.size() + this->hewan.size() + this->produk.size()) {
        auto it = this->produk.begin();
        for (int i = 0; i < num - this->tanaman.size() - this->hewan.size() - 1; i++) {
            it++;
        }
        return it->first;
    }
    else {
        auto it = this->bangunan.begin();
        for (int i = 0; i < num - this->tanaman.size() - this->hewan.size() - this->produk.size() - 1; i++) {
            it++;
        }
        return it->first;
    }
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

void Toko::atur_tanaman(vector<shared_ptr<Tanaman>> t) {
    this->tanaman = t;
}

void Toko::atur_hewan(vector<shared_ptr<Hewan>> h) {
    this->hewan = h;
}

// Method
void Toko::masukanEntitas(shared_ptr<Entitas> Ent) {
    if (Util::instanceof<Bangunan>(Ent.get())) {
        shared_ptr<Bangunan> ptrBangunan(dynamic_cast<Bangunan*>(Ent.get()));
        tambah_bangunan(ptrBangunan);
    }
    else if (Util::instanceof<Produk>(Ent.get())) {
        shared_ptr<Produk> ptrProduk(dynamic_cast<Produk*>(Ent.get()));
        tambah_produk(ptrProduk);
    }
}

void Toko::tambah_produk(shared_ptr<Produk> p) {
    this->produk[p]++;
}

void Toko::tambah_bangunan(shared_ptr<Bangunan> b) {
    this->bangunan[b]++;
}

void Toko::kurangi_produk(shared_ptr<Produk> p) {
    this->produk[p]--;
}

void Toko::kurangi_bangunan(shared_ptr<Bangunan> b) {
    this->bangunan[b]--;
}

// Print Info
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

void Toko::tampilBarang(bool isWalikota) {
    int number = 1;
    for (int i = 0; i < this->tanaman.size(); i++) {
        cout << number << ". " << tanaman[i].get()->dapatkan_nama() << " - " << tanaman[i].get()->dapatkan_harga() << endl;
        number++;
    }

    for (int i = 0; i < this->hewan.size(); i++) {
        cout << number << ". " << hewan[i].get()->dapatkan_nama() << " - " << hewan[i].get()->dapatkan_harga() << endl;
        number++;
    }

    for (auto it = this->produk.begin(); it != this->produk.end(); it++) {
        cout << number << ". " << it->first->dapatkan_nama() << " - " << it->first->dapatkan_harga() << " (" << it->second << ")" << endl;
        number++;
    }

    for (auto it = this->bangunan.begin(); it != this->bangunan.end(); it++) {
        cout << number << ". " << it->first->dapatkan_nama() << " - " << it->first->dapatkan_harga() << " (" << it->second << ")" << endl;
        number++;
    }
}
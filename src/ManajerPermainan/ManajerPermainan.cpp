#include "ManajerPermainan.hpp"

ManagerPermainan::ManagerPermainan(string path) {
    this->giliran = 0;
    this->jumlah_pemain = 0;
    this->daftar_tanaman = InputKonfigurasi::InputKonfigurasiTanaman(path + "/plant.txt");
    this->daftar_hewan = InputKonfigurasi::InputKonfigurasiHewan(path + "/animal.txt");
    this->daftar_produk = InputKonfigurasi::InputKonfigurasiProduk(path + "/product.txt");
    this->daftar_bangunan = InputKonfigurasi::InputKonfigurasiResepBangunan(path + "/recipe.txt");

    vector<int> misc = InputKonfigurasi::InputKonfigurasiMisc(path + "/misc.txt");
    this->uang_pemenang = misc[0];
    this->berat_pemenang = misc[1];
    this->besar_penyimpanan = make_tuple(misc[2], misc[3]);
    this->besar_lahan = make_tuple(misc[4], misc[5]);
    this->besar_peternakan = make_tuple(misc[6], misc[7]);


    // this->toko = Toko(path);
}

ManagerPermainan::~ManagerPermainan() {}

void ManagerPermainan::atur_pemain(string path) {
    this->daftar_pemain = InputKonfigurasi::InputStatePemain(path + "/state.txt", this->daftar_tanaman, this->daftar_hewan, this->daftar_produk, this->daftar_bangunan, this->besar_penyimpanan, this->besar_lahan, this->besar_peternakan, this->toko);
}

void ManagerPermainan::atur_pemain(vector<shared_ptr<Pemain>> daftarPemain) {
    this->daftar_pemain = daftarPemain;
}

void ManagerPermainan::sort_daftar_pemain() {
    sort(this->daftar_pemain.begin(), this->daftar_pemain.end(), [](const shared_ptr<Pemain>& a, const shared_ptr<Pemain>& b){
        return a->dapatkan_nama() < b->dapatkan_nama();
    });
}

vector<shared_ptr<Pemain>> ManagerPermainan::dapatkan_daftar_pemain() {
    return this->daftar_pemain;
}

shared_ptr<Pemain> ManagerPermainan::pemain_skrg() {
    return this->daftar_pemain.at(this->giliran);
}

void ManagerPermainan::next() {         // Belom di test
    this->giliran = (this->giliran + 1) % this->daftar_pemain.size();
    for (int i = 0; i < this->daftar_pemain.size(); i++) {
        if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(i))) {
            p->next_umur();
        }
    }
}

tuple<int,int> ManagerPermainan::dapatkanBesarPenyimpanan() const{
    return besar_penyimpanan;
}

void ManagerPermainan::inisialisasi_toko() {
    this->toko.atur_tanaman(this->daftar_tanaman);
    this->toko.atur_hewan(this->daftar_hewan);
}

Toko ManagerPermainan::dapatkan_toko() {
    return this->toko;
}

void ManagerPermainan::print_konfigurasi() {
    cout << "Daftar Tanaman:" << endl;
    for (int i = 0; i < this->daftar_tanaman.size(); i++) {
        this->daftar_tanaman[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Hewan:" << endl;
    for (int i = 0; i < this->daftar_hewan.size(); i++) {
        this->daftar_hewan[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Produk:" << endl;
    for (int i = 0; i < this->daftar_produk.size(); i++) {
        this->daftar_produk[i]->print_info();
        cout << endl;
    }

    cout << "Daftar Bangunan:" << endl;
    for (int i = 0; i < this->daftar_bangunan.size(); i++) {
        this->daftar_bangunan[i]->print_info();
        cout << endl;
    }
}
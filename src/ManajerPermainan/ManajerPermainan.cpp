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
}

ManagerPermainan::~ManagerPermainan() {}

void ManagerPermainan::atur_pemain(string path) {
    this->daftar_pemain = InputKonfigurasi::InputStatePemain(path + "/state.txt", this->daftar_tanaman, this->daftar_hewan, this->daftar_produk, this->daftar_bangunan, this->besar_penyimpanan, this->besar_lahan, this->besar_peternakan, this->toko);
}

vector<shared_ptr<Pemain>> ManagerPermainan::dapatkan_daftar_pemain() {
    return this->daftar_pemain;
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

// Command Permainan
void ManagerPermainan::muat() {
    string path_to_file;
    cout << "Masukkan lokasi berkas state : ";
    cin >> path_to_file;
    cout << endl;

    ifstream file(path_to_file);
    if (!file.is_open()) {
        cout << "File tidak ditemukan" << endl;
        return;
    }

    // Nanti tambahin try catch
    this->daftar_pemain = InputKonfigurasi::InputStatePemain(path_to_file, this->daftar_tanaman, this->daftar_hewan, this->daftar_produk, this->daftar_bangunan, this->besar_penyimpanan, this->besar_lahan, this->besar_peternakan, this->toko);
}

void ManagerPermainan::simpan() {
    string path_to_file;
    cout << "Masukkan lokasi berkas state : ";
    cin >> path_to_file;
    cout << endl;

    // Check if folder exists
    string folder = path_to_file.substr(0, path_to_file.find_last_of("/"));
    if (system(("cd " + folder).c_str()) != 0) {
        cout << "Folder tidak ditemukan" << endl;
        return;
    }

    // Create or overwrite file
    ofstream file(path_to_file);
    if (!file.is_open()) {
        cout << "File tidak dapat dibuat" << endl;
        return;
    }

    file << this->daftar_pemain.size() << endl;
    for (int i = 0; i < this->daftar_pemain.size(); i++) {
        shared_ptr<Pemain> pemain = this->daftar_pemain[i];

        file << pemain->dapatkan_nama();
        if (Util::instanceof<Petani>(pemain.get())) {
            file << " Petani ";
        }
        else if (Util::instanceof<Peternak>(pemain.get())) {
            file << " Peternak ";
        }
        else if (Util::instanceof<Walikota>(pemain.get())) {
            file << " Walikota ";
        }
        file << pemain->dapatkan_berat_badan() << " " << pemain->dapatkan_uang() << endl;

        int jumlah_item = pemain->jumlah_slot_efektif_peti();
        file << jumlah_item << endl;
        Matrix peti = pemain->dapatkan_peti();
        for (int j = 0; j < peti.dapatkanBaris(); j++) {
            for (int k = 0; k < peti.dapatkanKolom(); k++) {
                if (!peti.apakahSlotKosong(j, k)) {
                    Entitas* entitas = peti.dapatkanElemen(j, k);
                    file << entitas->dapatkan_nama() << endl;
                    delete entitas;
                }
            }
        }

        if (Util::instanceof<Petani>(pemain.get())) {
            shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(pemain);
            int jumlah_tanaman_di_ladang = petani->jumlah_slot_efektif_ladang();
            file << jumlah_tanaman_di_ladang << endl;
            // Lanjutin nanti
        }
        else if (Util::instanceof<Peternak>(pemain.get())) {
            shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(pemain);
            // peternak->simpan_peternakan(file);
        }
    }
}
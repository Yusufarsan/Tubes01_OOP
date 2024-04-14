#include "ManajerPermainan.hpp"

// Constructor & Destructor
ManagerPermainan::ManagerPermainan(string path) {
    this->giliran = 0;
    this->jumlah_pemain = 0;

    try {
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
    catch (const invalid_argument& e) {
        cout << e.what() << '\n';
        exit(1);
    }
}

ManagerPermainan::~ManagerPermainan() {}

// Getter & Setter
vector<shared_ptr<Pemain>> ManagerPermainan::dapatkan_daftar_pemain() {
    return this->daftar_pemain;
}

shared_ptr<Pemain> ManagerPermainan::pemain_skrg() {
    return this->daftar_pemain[this->giliran];
}

tuple<int, int> ManagerPermainan::dapatkanBesarPenyimpanan() const {
    return besar_penyimpanan;
}

tuple<int, int> ManagerPermainan::dapatkanBesarLahan() const {
    return besar_lahan;
}

tuple<int, int> ManagerPermainan::dapatkanBesarPeternakan() const {
    return besar_peternakan;
}

Toko ManagerPermainan::dapatkan_toko() {
    return this->toko;
}

void ManagerPermainan::atur_pemain(string path) {
    this->daftar_pemain = InputKonfigurasi::InputStatePemain(path + "/state.txt", this->daftar_tanaman, this->daftar_hewan, this->daftar_produk, this->daftar_bangunan, this->besar_penyimpanan, this->besar_lahan, this->besar_peternakan, this->toko);
    this->sort_daftar_pemain();
}

void ManagerPermainan::atur_pemain(vector<shared_ptr<Pemain>> daftarPemain) {
    this->daftar_pemain = daftarPemain;
    this->sort_daftar_pemain();
}

// Method
void ManagerPermainan::sort_daftar_pemain() {
    sort(this->daftar_pemain.begin(), this->daftar_pemain.end(), [](const shared_ptr<Pemain>& a, const shared_ptr<Pemain>& b) {
        return a->dapatkan_nama() < b->dapatkan_nama();
        });
}

void ManagerPermainan::inisialisasi_toko() {
    this->toko.atur_tanaman(this->daftar_tanaman);
    this->toko.atur_hewan(this->daftar_hewan);
}

// Command Permainan
void ManagerPermainan::next() {
    this->giliran = (this->giliran + 1) % this->daftar_pemain.size();
    for (int i = 0; i < this->daftar_pemain.size(); i++) {
        if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(i))) {
            p->next_umur();
        }
    }
}

void ManagerPermainan::cetak_penyimpanan() {
    this->daftar_pemain.at(this->giliran)->cetak_peti();
}

void ManagerPermainan::pungut_pajak() {
    if (shared_ptr<Walikota> p = dynamic_pointer_cast<Walikota>(this->daftar_pemain.at(this->giliran))) {
        p->tagih_pajak(this->daftar_pemain);
    }
    else {
        // throw BukanWalkotException("Hanya Walikota yang dapat mengumpulkan pajak\n");
        cout << "Hanya Walikota yang dapat mengumpulkan pajak" << endl;
    }
}

void ManagerPermainan::cetak_ladang() {
    if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(this->giliran))) {
        p->cetak_ladang();
    }
    else if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->cetak_peternakan();
    }
    else {
        // throw BukanPetaniPeternakException("Hanya Petani atau Peternak yang dapat mencetak ladang\n");
        cout << "Hanya Petani atau Peternak yang dapat mencetak ladang" << endl;
    }
}

void ManagerPermainan::tanam() {
    if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(this->giliran))) {
        p->tanam();
    }
    else {
        // throw BukanPetaniException("Hanya Petani yang dapat menanam\n");
        cout << "Hanya Petani yang dapat menanam" << endl;
    }
}

void ManagerPermainan::ternak() {
    if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->ternak();
    }
    else {
        // throw BukanPeternakException("Hanya Peternak yang dapat beternak\n");
        cout << "Hanya Peternak yang dapat beternak" << endl;
    }
}

void ManagerPermainan::bangun() {
    if (shared_ptr<Walikota> p = dynamic_pointer_cast<Walikota>(this->daftar_pemain.at(this->giliran))) {
        p->bangun(this->daftar_bangunan);
    }
    else {
        // throw BukanWalkotException("Hanya Walikota yang dapat membangun\n");
        cout << "Hanya Walikota yang dapat membangun" << endl;
    }
}

void ManagerPermainan::makan() {
    this->daftar_pemain.at(this->giliran)->makan();
}

void ManagerPermainan::kasih_makan() {
    if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->beri_pangan();
    }
    else {
        // throw BukanPeternakException("Hanya Peternak yang dapat memberi makan\n");
        cout << "Hanya Peternak yang dapat memberi makan" << endl;
    }
}

void ManagerPermainan::beli() {
    if (shared_ptr<Walikota> p = dynamic_pointer_cast<Walikota>(this->daftar_pemain.at(this->giliran))) {
        p->membeli(this->toko);
    }
    else if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(this->giliran))) {
        p->membeli(this->toko);
    }
    else if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->membeli(this->toko);
    }
    else {
        // throw BukanWalkotException("Hanya Walikota yang dapat membeli\n");
        cout << "Terdapat kesalahan saat melakukan downcast class Pemain" << endl;
    }
}

void ManagerPermainan::jual() {
    if (shared_ptr<Walikota> p = dynamic_pointer_cast<Walikota>(this->daftar_pemain.at(this->giliran))) {
        p->jual(this->toko);
    }
    else if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(this->giliran))) {
        p->jual(this->toko);
    }
    else if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->jual(this->toko);
    }
    else {
        // throw BukanWalkotException("Hanya Walikota yang dapat menjual\n");
        cout << "Terdapat kesalahan saat melakukan downcast class Pemain" << endl;
    }
}

void ManagerPermainan::panen() {
    if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(this->giliran))) {
        p->panen(daftar_produk);
    }
    else if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(this->giliran))) {
        p->panen(daftar_produk);
    }
    else {
        // throw BukanPetaniPeternakException("Hanya Petani atau Peternak yang dapat memanen\n");
        cout << "Hanya Petani atau Peternak yang dapat memanen" << endl;
    }
}

void ManagerPermainan::muat() {
    string path_to_file;
    cout << "Masukkan lokasi berkas state : ";
    cin >> path_to_file;
    cout << endl;

    this->atur_pemain(InputKonfigurasi::InputStatePemain(path_to_file, this->daftar_tanaman, this->daftar_hewan, this->daftar_produk, this->daftar_bangunan, this->besar_penyimpanan, this->besar_lahan, this->besar_peternakan, this->toko));
}

void ManagerPermainan::inisialisasi_pemain() {
    shared_ptr<Pemain> pemain1 = make_shared<Petani>("Petani1", 50, 40, besar_penyimpanan, besar_lahan);
    shared_ptr<Pemain> pemain2 = make_shared<Peternak>("Peternak1", 50, 40, besar_penyimpanan, besar_peternakan);
    shared_ptr<Pemain> pemain3 = make_shared<Walikota>("Walikota", 50, 40, besar_penyimpanan);

    vector<shared_ptr<Pemain>> daftarPemain = { pemain1, pemain2, pemain3 };
    this->atur_pemain(daftarPemain);
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

        Matrix peti = pemain->dapatkan_peti();
        int jumlah_item = peti.jumlahElement();
        file << jumlah_item << endl;
        for (int j = 0; j < peti.dapatkanBaris(); j++) {
            for (int k = 0; k < peti.dapatkanKolom(); k++) {
                if (!peti.apakah_slot_kosong(j, k)) {
                    shared_ptr<Entitas> entitas = peti.dapatkan_elemen(j, k);
                    file << entitas->dapatkan_nama() << endl;
                }
            }
        }

        if (Util::instanceof<Petani>(pemain.get())) {
            shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(pemain);
            Matrix<Tanaman> ladang = petani->dapatkan_ladang();
            int jumlah_tanaman_di_ladang = ladang.jumlahElement();
            file << jumlah_tanaman_di_ladang << endl;
            tuple<int, int> ukuran_ladang = make_tuple(ladang.dapatkanBaris(), ladang.dapatkanKolom());
            for (int j = 0; j < get<0>(ukuran_ladang); j++) {
                for (int k = 0; k < get<1>(ukuran_ladang); k++) {
                    if (!ladang.apakah_slot_kosong(j, k)) {
                        shared_ptr<Tanaman> tanaman = ladang.dapatkan_elemen(j, k);
                        string slot = Util::label_slot_tabel(j, k);
                        file << slot << " " << tanaman->dapatkan_nama() << " " << tanaman->dapatkan_umur() << endl;
                    }
                }
            }
        }
        else if (Util::instanceof<Peternak>(pemain.get())) {
            shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(pemain);
            Matrix<Hewan> peternakan = peternak->dapatkan_peternakan();
            int jumlah_hewan_di_peternakan = peternakan.jumlahElement();
            file << jumlah_hewan_di_peternakan << endl;
            tuple<int, int> ukuran_peternakan = make_tuple(peternakan.dapatkanBaris(), peternakan.dapatkanKolom());
            for (int j = 0; j < get<0>(ukuran_peternakan); j++) {
                for (int k = 0; k < get<1>(ukuran_peternakan); k++) {
                    if (!peternakan.apakah_slot_kosong(j, k)) {
                        shared_ptr<Hewan> hewan = peternakan.dapatkan_elemen(j, k);
                        string slot = Util::label_slot_tabel(j, k);
                        file << slot << " " << hewan->dapatkan_nama() << " " << hewan->dapatkan_berat() << endl;
                    }
                }
            }
        }
    }

    int jumlah_produk_toko = this->toko.dapatkan_jumlah_produk();
    int jumlah_bangunan_toko = this->toko.dapatkan_jumlah_bangunan();
    file << jumlah_produk_toko + jumlah_bangunan_toko << endl;
    for (int i = 0; i < jumlah_produk_toko; i++) {
        tuple<shared_ptr<Produk>, int> produk = this->toko.dapatkan_produk(i);
        file << get<0>(produk)->dapatkan_nama() << " " << get<1>(produk) << endl;
    }

    for (int i = 0; i < jumlah_bangunan_toko; i++) {
        tuple<shared_ptr<Bangunan>, int> bangunan = this->toko.dapatkan_bangunan(i);
        file << get<0>(bangunan)->dapatkan_nama() << " " << get<1>(bangunan) << endl;
    }
}

void ManagerPermainan::tambah_pemain() {
    if (shared_ptr<Walikota> p = dynamic_pointer_cast<Walikota>(this->daftar_pemain.at(this->giliran))) {
        p->tambah_pemain(&this->daftar_pemain, this->besar_penyimpanan, 40, this->besar_lahan, this->besar_peternakan);
    }
    else {
        // throw BukanWalkotException("Hanya Walikota yang dapat menambah pemain\n");
        cout << "Hanya Walikota yang dapat menambah pemain" << endl;
    }
}

void ManagerPermainan::keluar() {
    cout << "Terima kasih telah bermain!" << endl;
}

// Print Info
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

    cout << "Daftar Pemain:" << endl;
    for (int i = 0; i < this->daftar_pemain.size(); i++) {
        cout << this->daftar_pemain[i]->dapatkan_nama() << endl;
        this->daftar_pemain[i]->cetak_peti();

        if (shared_ptr<Petani> p = dynamic_pointer_cast<Petani>(this->daftar_pemain.at(i))) {
            p->cetak_ladang();
        }
        else if (shared_ptr<Peternak> p = dynamic_pointer_cast<Peternak>(this->daftar_pemain.at(i))) {
            p->cetak_peternakan();
        }

        cout << endl;
    }

    cout << "Daftar Produk di Toko:" << endl;
    this->toko.cetak_isi_toko();
}
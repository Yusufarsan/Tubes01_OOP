#include "Petani.hpp"

// Constructor & Destructor
Petani::Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang) : Pemain(nama, uang, berat_badan, ukuran_peti), ladang(get<0>(ukuran_ladang), get<1>(ukuran_ladang)) {}

Petani::~Petani() {};

// Getter
Matrix<Tanaman> Petani::dapatkan_ladang() {
    return ladang;
};

// Method
bool Petani::cek_ladang_penuh() {
    return ladang.apakah_penuh();
};

bool Petani::cek_ladang_kosong() {
    return ladang.apakah_kosong();
};

int Petani::jumlah_slot_efektif_ladang() {
    return ladang.jumlahElement();
};

int Petani::jumlah_slot_kosong_ladang() {
    return ladang.jumlah_slot_kosong();
};

void Petani::tambah_ladang(string slot, shared_ptr<Tanaman> val) {
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);
    
    ladang.tambah_elemen_matriks(idxRow, idxCol, val);
}

void Petani::next_umur() {
    if (ladang.apakah_kosong()) return;      // Kalo ladang nya kosong ya udah lah cuk, ga ngapa ngapain
    for (int i = 0; i < this->ladang.dapatkanBaris(); i++) {
        for (int j = 0; j < this->ladang.dapatkanKolom(); j++) {    // Kalo ladang pada petak tertentu tidak kosong (ada tanamannya), maka umur ditambah
            if (this->ladang.dapatkan_elemen(i, j) != nullptr) this->ladang.dapatkan_elemen(i, j)->tambah_umur();
        }
    }
}

unordered_map<pair<string, string>, int, Petani::pair_hash> Petani::frekuensi_panen() {
    unordered_map<pair<string, string>, int, Petani::pair_hash> frequencyMap;

    // Iterate over the elements of ladang matriks
    for (int i = 0; i < ladang.dapatkanBaris(); i++) {
        for (int j = 0; j < ladang.dapatkanKolom(); j++) {
            Tanaman* tan = ladang.dapatkan_elemen(i, j).get();
            if (tan != nullptr && tan->bisa_panen()) {
                // Increment the frequency count for the Tanaman's name
                frequencyMap[make_pair(tan->dapatkan_kode_huruf(), tan->dapatkan_nama())]++;
            }
        }
    }
    return frequencyMap;
}

// Command
void Petani::panen(vector<shared_ptr<Produk>> daftarProduk) {
    cetak_ladang();
    unordered_map<pair<string, string>, int, pair_hash> frequencyMap = frekuensi_panen();
    if (frequencyMap.size() != 0) {
        auto res = tampilkanPanen(frequencyMap);
        vector<string> kode = get<0>(res);
        vector<string> nama = get<1>(res);
        int counter = get<2>(res);
        bool isNumValid = false;
        int nomor, petak;
        while (!isNumValid) {
            bool isJumlahValid = false;
            cout << "Nomor tanaman yang ingin dipanen: ";
            cin >> nomor;
            if (cin.fail() || nomor >= counter || nomor <= 0) {
                cout << "---Masukkan nomor yang valid!---" << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
            while (!isJumlahValid && nomor < counter && nomor>0) {
                cout << "Berapa petak yang ingin dipanen: ";
                cin >> petak;
                if (petak <= frequencyMap[make_pair((kode.at(nomor - 1)), (nama.at(nomor - 1)))] && petak > 0) {
                    if (peti.jumlah_slot_kosong() >= petak) {
                        cout << "Pilih petak yang ingin dipanen: " << endl;
                        vector<string> succ;
                        int i = 0; bool isPetakValid = false;
                        while (i < petak) {
                            string slot;
                            cout << "   Petak ke-" << i + 1 << " : ";
                            cin >> slot;
                            int row = Util::indeks_baris_slot(slot);
                            int col = Util::indeks_kolom_slot(slot);
                            if (ladang.apakah_index_valid(row, col)) {
                                if (!ladang.apakah_slot_kosong(slot)) {
                                    if (ladang.dapatkan_elemen(row, col)->bisa_panen()) {
                                        if (Util::strComp(nama.at(nomor - 1), ladang.dapatkan_elemen(row, col)->dapatkan_nama())) {
                                            // hapus dari ladang dan konversi dari Tanaman -> Entitas -> Produk
                                            shared_ptr<Entitas> ent = ladang.hapus(row, col);
                                            shared_ptr<Entitas> prod;
                                            auto conf = dapatkan_konfig_produk(daftarProduk, ent->dapatkan_nama());
                                            if (Util::instanceof<TanamanMaterial>(ent.get())) {
                                                prod = make_shared<ProdukTanamanMaterial>(Util::dapatkan_nama_tumb(ent->dapatkan_nama()), get<0>(conf), get<1>(conf));
                                            }
                                            else {
                                                prod = make_shared<ProdukTanamanBuah>(Util::dapatkan_nama_tumb(ent->dapatkan_nama()), get<0>(conf), get<1>(conf));
                                            }

                                            // tambah ke peti penyimpanan
                                            peti += (prod);
                                            succ.push_back(slot);
                                            i++;
                                            cout << "----Berhasil----" << endl;
                                        }
                                        else {
                                            cout << "Katanya mau panen " << nama.at(nomor - 1) << endl;
                                        }

                                    }
                                    else {
                                        cout << "--Itu belum bisa dipanen---" << endl;
                                    }

                                }
                                else {
                                    cout << "Kamu ga punya tanaman di situ" << endl;
                                }
                            }
                            else {
                                cout << "Weitts kelebihan tu petaknya" << endl;
                            }
                        }
                        cout << petak << " petak tanaman " << nama.at(nomor - 1) << " pada petak ";
                        for (auto& each : succ) {
                            cout << each << " ";
                        }
                        cout << "telah dipanen!" << endl;
                        isJumlahValid = true;
                        isNumValid = true;
                    }
                    else {
                        cout << "---Penyimpanan kamu ga cukup hey---" << endl;
                        isJumlahValid = true;
                    }
                }
                else if (petak > frequencyMap[make_pair(kode.at(nomor - 1), nama.at(nomor - 1))]) {
                    cout << "Kamu hanya memiliki " << nama.at(nomor - 1) << " sebanyak " << frequencyMap[make_pair(kode.at(nomor - 1), nama.at(nomor - 1))] << endl;
                }
                else {
                    if (petak == -1) {
                        // kembali ke pemilihan nomor
                        isJumlahValid = true;
                    }
                    else {
                        if (cin.fail()){
                            cin.clear(); // Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        }
                        
                        cout << "---Masukan petak yang valid!--- (-1 for back)" << endl;
                    }
                }
            }

        }

    }
    else {
        cout << "Kamu belum punya tanaman siap panen nih, ayo semangat bekerja!" << endl;
    }

}

void Petani::tanam() {
    if (peti.apakah_kosong()) {
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_ladang;
        int idxRowPeti, idxColPeti, idxRowLadang, idxColLadang;
        shared_ptr<Entitas> bibit;

        while (true) {
            cout << "Silakan pilih tanaman yang ingin Anda tanam!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;


            if (peti.apakah_slot_valid(slot_masukan_peti)) {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti.dapatkan_elemen(idxRowPeti, idxColPeti);
                if (!Util::instanceof<Tanaman>(bibit.get())) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi tanaman." << endl;
                }
                else {
                    cout << "Kamu memilih " << bibit.get()->dapatkan_nama() << " untuk ditanam." << endl;
                    break;
                }
            }
        }

        cetak_ladang();

        while (true) {
            cout << "Pilih petak tanah yang akan ditanami" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_ladang;

            if (ladang.apakah_slot_valid(slot_masukan_ladang)) {
                if (!ladang.apakah_slot_kosong(slot_masukan_ladang)) {
                    cout << "Slot " << slot_masukan_ladang << " milik tanaman lain." << endl;
                }
                else {
                    bibit = peti.hapus(idxRowPeti, idxColPeti);
                    tambah_ladang(slot_masukan_ladang, dynamic_pointer_cast<Tanaman>(bibit));
                    cout << "Cangkul, cangkul, cangkul yang dalam!" << endl;
                    cout << bibit.get()->dapatkan_nama() << " berhasil ditanam!" << endl;
                    break;
                }
            }
        }
    };
};

int Petani::hitung_pajak() {
    int KKP, pajak;
    int KTKP = 13;
    int neto_kekayaan = uang;

    if (!ladang.apakah_kosong()) {
        for (int i = 0; i < ladang.dapatkanBaris(); i++) {
            for (int j = 0; j < ladang.dapatkanKolom(); j++) {
                if (ladang.dapatkan_elemen(i, j) != nullptr) {
                    neto_kekayaan += ladang.dapatkan_elemen(i, j)->dapatkan_harga();
                }
            }
        }
    }

    if (!peti.apakah_kosong()) {
        for (int i = 0; i < peti.dapatkanBaris(); i++) {
            for (int j = 0; j < peti.dapatkanKolom(); j++) {
                if (peti.dapatkan_elemen(i, j) != nullptr) {
                    neto_kekayaan += peti.dapatkan_elemen(i, j)->dapatkan_harga();
                }
            }
        }
    }

    KKP = neto_kekayaan - KTKP;
    if (KKP <= 0) {
        pajak = 0;
    }
    else if (KKP <= 6) {
        pajak = round(KKP * 0.05);
    }
    else if (KKP <= 25) {
        pajak = round(KKP * 0.15);
    }
    else if (KKP <= 50) {
        pajak = round(KKP * 0.25);
    }
    else if (KKP <= 500) {
        pajak = round(KKP * 0.3);
    }
    else {
        pajak = round(KKP * 0.35);
    }

    if (pajak > uang) {
        pajak = uang;
    }

    return pajak;
}

// Print Info
void Petani::cetak_ladang() {
    int numRow = ladang.dapatkanBaris();
    int numCol = ladang.dapatkanKolom();
    // int emptySlot = 0;

    // dapatkan label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // Cetak judul tabel
    cout << "    ================[ Ladang ]==================\n\n";

    // label kolom
    for (int n = 1; n <= numCol; ++n) {
        if (n == 1) {
            string spaces(maxLengthRowCode + 1, ' ');
            cout << spaces;
        }

        string label_kolom = Util::label_kolom_tabel(n);
        int pad1Length = round(double(6 - label_kolom.length()) / 2);
        int pad2Length;

        if ((6 - label_kolom.length()) % 2 == 1) {
            pad2Length = pad1Length - 1;
        }
        else {
            pad2Length = pad1Length;
        }

        string pad1(pad1Length, ' ');
        string pad2(pad2Length, ' ');

        cout << pad1 << label_kolom << pad2;
    }
    cout << endl;

    // first +---+
    for (int n = 1; n <= numCol; n++) {
        if (n == 1) {
            string spaces(maxLengthRowCode + 1, ' ');
            cout << spaces;
        }

        string dash(5, '-');

        cout << "+" << dash;
    }
    cout << "+\n";

    // cetak label baris dan elemennya
    for (int n = 1; n <= numRow; n++) {
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode + 1 - label_baris.length(), ' ');
        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++) {
            if (ladang.apakah_slot_kosong(n - 1, m)) {
                cout << "     |";
                // emptySlot++;
            }
            else {
                shared_ptr<Tanaman> val = ladang.dapatkan_elemen(n - 1, m);
                if (val.get()->bisa_panen()) {
                    cout << " ";

                    print_green(val.get()->dapatkan_kode_huruf());

                    cout << " |";
                }
                else {
                    cout << " ";

                    print_red(val.get()->dapatkan_kode_huruf());

                    cout << " |";
                }
            }

        }
        cout << endl;

        // +---+
        for (int n = 1; n <= numCol; n++) {
            if (n == 1) {
                string spaces(maxLengthRowCode + 1, ' ');
                cout << spaces;
            }

            string dash(5, '-');
            cout << "+" << dash;
        }
        cout << "+\n";
    };

    // cout << endl << "Total slot kosong: " << ladang.jumlah_slot_kosong() << endl;
};

tuple<vector<string>, vector<string>, int> Petani::tampilkanPanen(unordered_map<pair<string, string>, int, pair_hash> frequencyMap) {
    // Display the names and frequencies of harvest-ready Tanaman objects

    int counter = 1;
    vector<string> nama;
    vector<string> kode;

    // tampilkan kode & nama
    for (const auto& it : frequencyMap) {
        nama.push_back(it.first.second);
        kode.push_back(it.first.first);
        cout << " -> " << it.first.first << " : " << it.first.second << endl;

    }
    cout << "Pilih tanaman siap panen yang kamu miliki:" << endl;

    // tampilkan kode & petak
    for (const auto& it : frequencyMap) {
        cout << counter << ". " << it.first.first << " (" << it.second << " petak siap panen)" << endl;
        counter++;

    }
    return make_tuple(kode, nama, counter);
}
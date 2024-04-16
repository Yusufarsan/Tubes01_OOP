#include "Peternak.hpp"
#include "../Exception/ExceptionMatrix.hpp"

// Constructor & Destructor
Peternak::Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan) : Pemain(nama, uang, berat_badan, ukuran_peti), peternakan(get<0>(ukuran_peternakan), get<1>(ukuran_peternakan)) {}

Peternak::~Peternak() {};

// Getter
Matrix<Hewan> Peternak::dapatkan_peternakan() {
    return peternakan;
};

// Method
bool Peternak::cek_slot_peternakan_valid(string slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    return peternakan.apakah_index_valid(i, j);
};

bool Peternak::cek_peternakan_penuh() {
    return peternakan.apakah_penuh();
};

bool Peternak::cek_peternakan_kosong() {
    return peternakan.apakah_kosong();
};

int Peternak::jumlah_slot_efektif_peternakan() {
    return peternakan.jumlahElement();
};

int Peternak::jumlah_slot_kosong_peternakan() {
    return peternakan.jumlah_slot_kosong();
};

void Peternak::tambah_peternakan(string slot, shared_ptr<Hewan> val) {
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);

    peternakan.tambah_elemen_matriks(idxRow, idxCol, val);
};

unordered_map<pair<string, string>, int, Peternak::pair_hash> Peternak::frekuensi_panen() {
    unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap;

    // Iterate over the elements of Peternakan matriks
    for (int i = 0; i < peternakan.dapatkanBaris(); i++) {
        for (int j = 0; j < peternakan.dapatkanKolom(); j++) {
            shared_ptr<Hewan> hew = peternakan.dapatkan_elemen(i, j);
            if (hew != nullptr && hew.get()->bisa_panen()) {
                // Increment the frequency count for the  hewan's name
                cout << hew.get()->dapatkan_nama() << endl;
                frequencyMap[make_pair(hew.get()->dapatkan_kode_huruf(), hew.get()->dapatkan_nama())]++;
            }
        }
    }
    return frequencyMap;
}

// Command
void Peternak::beri_pangan() {
    if (peternakan.apakah_kosong()) {
        cout << "Kandangnya kosong semua, mau kasih makan setan?" << endl;
    }
    else {
        if (peti.apakah_kosong()) {
            cout << "Kamu ga punya apa apa, Mau kasih makan pake angin?" << endl;
        }
        else {
            cetak_peternakan();

            string slot_masukan_peti, slot_masukan_peternakan;
            int idxRowPeti, idxColPeti, idxRowPeternakan, idxColPeternakan;
            // Entitas* produk;
            Hewan* hewanLapar;

            while (true) {
                cout << "Pilih kandang yang akan dikasih makan" << endl;
                cout << "Petak : ";
                cin >> slot_masukan_peternakan;

                if (peti.apakah_slot_valid(slot_masukan_peternakan)) {
                    idxRowPeternakan = Util::indeks_baris_slot(slot_masukan_peternakan);
                    idxColPeternakan = Util::indeks_kolom_slot(slot_masukan_peternakan);

                    shared_ptr<Hewan> kandang(peternakan.dapatkan_elemen(idxRowPeternakan, idxColPeternakan));

                    if (!kandang) {
                        cout << "Slot " << slot_masukan_peti << " gak ada hewannya." << endl;
                    }
                    else {
                        hewanLapar = kandang.get();
                        cout << "Kamu memilih " << hewanLapar->dapatkan_nama() << " untuk dikasih makan." << endl;
                        break;
                    }
                }
            }

            cetak_peti();

            while (true) {
                cout << "Silakan pilih pangan yang ingin Anda berikan!" << endl;
                cout << "Petak : ";
                cin >> slot_masukan_peti;

                if (peti.apakah_slot_valid(slot_masukan_peti)) {
                    idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                    idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);

                    shared_ptr<Entitas> produk = peti.dapatkan_elemen(idxRowPeti, idxColPeti);
                    if (!Util::instanceof<Produk>(produk.get())) {
                        cout << "Slot " << slot_masukan_peti << " tidak berisi makanan." << endl;
                    }
                    else if (Util::instanceof<ProdukTanamanMaterial>(produk.get())) {
                        cout << "Slot " << slot_masukan_peti << " berisi produk tanaman material yang tidak bisa dimakan." << endl;
                    }
                    else {
                        Produk* makanan = dynamic_cast<Produk*>(produk.get());
                        if(hewanLapar->makan(makanan)){
                            peti.hapus(idxRowPeti, idxColPeti);
                        }
                    }

                    break;
                }
            }
        }
    };
};

void Peternak::ternak() {
    if (peti.apakah_kosong()) {
        cout << "Gak punya penyimpanan kok mau ternak!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_peternakan;
        int idxRowPeti, idxColPeti, idxRowPeternakan, idxColPeternakan;
        shared_ptr<Entitas> bibit;

        while (true) {
            cout << "Silakan pilih hewan yang ingin Anda ternak!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (slot_masukan_peti == "BATAL") {
                return;
            }

            if (peti.apakah_slot_valid(slot_masukan_peti)) {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);

                bibit = peti.dapatkan_elemen(idxRowPeti, idxColPeti);
                if (!Util::instanceof<Hewan>(bibit.get())) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi bibit hewan." << endl;
                }
                else {
                    cout << "Kamu memilih " << bibit.get()->dapatkan_nama() << " untuk dipelihara." << endl;
                    break;
                }
            }
        }

        cetak_peternakan();

        while (true) {
            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peternakan;

            if (peternakan.apakah_slot_valid(slot_masukan_peternakan)) {
                if (!peternakan.apakah_slot_kosong(slot_masukan_peternakan)) {
                    cout << "Slot " << slot_masukan_peti << " milik hewan lain." << endl;
                }
                else {
                    bibit = peti.hapus(idxRowPeti, idxColPeti);
                    tambah_peternakan(slot_masukan_peternakan, dynamic_pointer_cast<Hewan>(bibit));
                    cout << "Ternak, ternak, ternak yang banyak!" << endl;
                    cout << bibit->dapatkan_nama() << " berhasil diternak!" << endl;
                    break;
                }
            }
        }
    };
};


void Peternak::panen(vector<shared_ptr<Produk>> daftarProduk) {
    cetak_peternakan();
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
            cout << "Nomor hewan yang ingin dipanen: ";
            cin >> nomor;
            if (nomor == -1) {
                return;
            }
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
                            try {
                                if (!peternakan.apakah_index_valid(row, col)) {
                                    throw aksesTidakValid(row, col);
                                }
                                if (peternakan.apakah_slot_kosong(row, col)) {
                                    throw tidakBisaTambahElemen(", Kamu ga punya hewan di situ");
                                }
                                if (peternakan.dapatkan_elemen(row, col)->bisa_panen()) {
                                    if (Util::strComp(nama.at(nomor - 1), peternakan.dapatkan_elemen(row, col)->dapatkan_nama())) {
                                        // hapus dari ladang dan konversi dari Tanaman -> Entitas -> Produk
                                        shared_ptr<Entitas> ent = peternakan.hapus(row, col);
                                        shared_ptr<Entitas> prod;

                                        auto res = dapatkan_konfig_produk(daftarProduk, ent->dapatkan_nama() + "_MEAT");

                                        prod = make_shared<ProdukHewan>(ent->dapatkan_nama(), get<0>(res), get<1>(res));

                                        if (Util::strComp(ent->dapatkan_kode_huruf(), "CHK") || Util::strComp(ent->dapatkan_kode_huruf(), "DCK")) {
                                            auto resEgg = dapatkan_konfig_produk(daftarProduk, ent->dapatkan_nama() + "_EGG");
                                            shared_ptr<Entitas> egg = make_shared<ProdukHewan>(ent->dapatkan_nama(), get<0>(resEgg), get<1>(resEgg), true);
                                            peti += (egg);
                                        }

                                        // tambah ke peti penyimpanan
                                        peti += (prod);
                                        succ.push_back(slot);
                                        i++;
                                        cout << "----Berhasil----" << endl;
                                    }
                                    else {
                                        cout << "----Katanya mau panen " << nama.at(nomor - 1) << "----" << endl;
                                    }

                                }                                
else {
                                    cout << "----Itu belum bisa dipanen-----" << endl;
                                }
                            }
                            catch (const tidakBisaTambahElemen& e) {
                                cout << e.what() << endl;
                            }
                            catch (const aksesTidakValid& e) {
                                cout << e.what();
                            }
                        }
                        cout << petak << " petak peternakan " << nama.at(nomor - 1) << " pada petak ";
                        for (auto& each : succ) {
                            cout << each << " ";
                        }
                        cout << "telah dipanen!" << endl;
                        isJumlahValid = true;
                        isNumValid = true;
                    }
                    else {
                        cout << "----Penyimpanan kamu ga cukup hey----" << endl;
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
                        if (cin.fail()) {
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
        cout << "Kamu belum punya hewan siap panen nih, ayo semangat bekerja!" << endl;
    }

}

int Peternak::hitung_pajak() {
    int KKP, pajak;
    int KTKP = 11;
    int neto_kekayaan = uang;

    if (!peternakan.apakah_kosong()) {
        for (int i = 0; i < peternakan.dapatkanBaris(); i++) {
            for (int j = 0; j < peternakan.dapatkanKolom(); j++) {
                if (peternakan.dapatkan_elemen(i, j) != nullptr) {
                    neto_kekayaan += peternakan.dapatkan_elemen(i, j)->dapatkan_harga();
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
void Peternak::cetak_peternakan() {
    int numRow = peternakan.dapatkanBaris();
    int numCol = peternakan.dapatkanKolom();
    // int emptySlot = 0;


    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // Cetak judul tabel
    cout << "    ================[ Peternakan ]==================\n\n";

    // cetak label kolom
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
            if (peternakan.apakah_slot_kosong(n - 1, m)) {
                cout << "     |";
                // emptySlot++;
            }
            else {
                shared_ptr<Hewan> val = peternakan.dapatkan_elemen(n - 1, m);
                if (val.get()->bisa_panen()) {
                    cout << " ";

                    print_green(val->dapatkan_kode_huruf());

                    cout << " |";
                }
                else {
                    cout << " ";

                    print_red(val->dapatkan_kode_huruf());

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

    cout << endl << "Total slot kosong: " << peternakan.jumlah_slot_kosong() << endl;
};

tuple<vector<string>, vector<string>, int> Peternak::tampilkanPanen(unordered_map<pair<string, string>, int, Peternak::pair_hash> frequencyMap) {
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
    cout << endl << "Pilih hewan siap panen yang kamu miliki:" << endl;

    // tampilkan kode & petak
    for (const auto& it : frequencyMap) {
        cout << counter << ". " << it.first.first << " (" << it.second << " petak siap panen)" << endl;
        counter++;

    }
    cout << endl;
    return make_tuple(kode, nama, counter);
}
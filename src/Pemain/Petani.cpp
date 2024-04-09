#include "Petani.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <cmath>

Petani::Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang) : Pemain(nama, uang, berat_badan, ukuran_peti) {
    int row = get<0>(ukuran_ladang);
    int col = get<1>(ukuran_ladang);

    for (int i = 0; i < row; i++) {
        vector<shared_ptr<Tanaman>> row;
        for (int j = 0; j < col; j++) {
            row.push_back(nullptr);
        }
        ladang.push_back(row);
    }
}

Petani::~Petani() {};

void Petani::cetak_ladang() {
    int numRow = ladang.size();
    int numCol = ladang[0].size();
    int emptySlot = 0;

    // dapatkan label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

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
            if (!ladang[n - 1][m].get()) {
                cout << "     |";
                emptySlot++;
            }
            else {
                Tanaman* val = ladang[n - 1][m].get();
                if (val->bisa_panen()) {
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
};

int Petani::jumlah_slot_kosong_ladang() {
    int emptySlot = 0;

    for (int i = 0; i < ladang.size(); i++) {
        for (int j = 0; j < ladang[0].size(); j++) {
            if (!ladang[i][j].get()) {
                emptySlot++;
            }
        }
    }

    return emptySlot;
};

bool Petani::cek_slot_ladang_valid(const string& slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    if (i < ladang.size() and j < ladang[0].size()) {
        return true;
    }

    return false;
};

void Petani::tanam() {
    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())) {
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_ladang;
        int i, j;
        Entitas* bibit = nullptr;

        while (true) {
            cout << "Silakan pilih tanaman yang ingin Anda tanam!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (!cek_slot_peti_valid(slot_masukan_peti)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                i = Util::indeks_baris_slot(slot_masukan_peti);
                j = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti[i][j].get();
                if (!Util::instanceof<Tanaman>(bibit)) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi makanan." << endl;
                }
                else {
                    cout << "Kamu memilih " << bibit->dapatkan_nama() << " untuk ditanam." << endl;
                }
            }
        }

        cetak_ladang();

        while (true) {
            cout << "Pilih petak tanah yang akan ditanami" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_ladang;

            if (!cek_slot_peti_valid(slot_masukan_ladang)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                i = Util::indeks_baris_slot(slot_masukan_ladang);
                j = Util::indeks_kolom_slot(slot_masukan_ladang);

                shared_ptr<Tanaman> tanah = ladang[i][j];

                if (!tanah) {
                    cout << "Slot " << slot_masukan_peti << " kosong." << endl;
                }
                else {
                    cout << "Cangkul, cangkul, cangkul yang dalam!" << endl;
                    cout << tanah.get()->dapatkan_nama() << " berhasil ditanam!" << endl;
                }
            }
        }
    };
};


void Petani::tambah_ladang(string slot, Tanaman& val) {
    if (cek_slot_ladang_valid(slot)) {
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (ladang[i][j] == nullptr) {
            ladang[i][j] = make_shared<Tanaman>(val);
        }
        else {
            cout << "Ada isinya" << endl;
        }
    }
    else {
        cout << "index out of bonds" << endl;
    }
}

Tanaman* Petani::hapus_ladang(string slot) {
    if (cek_slot_ladang_valid(slot)) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (ladang[idxRow][idxCol] != nullptr) {
            Tanaman* delTanaman = ladang[idxRow][idxCol].get();
            ladang[idxRow][idxCol].reset();

            return delTanaman;
        }
    }

    return nullptr;
}

void Petani::panen() {
    cetak_ladang();

    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
}

int Petani::hitung_pajak() {
    int KKP, neto, KTKP;

    return 10;
}
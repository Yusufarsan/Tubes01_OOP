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

    // cout << endl << "Total slot kosong: " << emptySlot << endl;
};

bool Petani::cek_ladang_penuh() {
    return jumlah_slot_kosong_peti() == 0;
};

bool Petani::cek_ladang_kosong() {
    return jumlah_slot_kosong_peti() == (ladang.size() * ladang[0].size());
};

int Petani::jumlah_slot_kosong_ladang() {
    int emptySlot = 0;

    for (int i = 0; i < ladang.size(); i++) {
        for (int j = 0; j < ladang[0].size(); j++) {
            if (!ladang[i][j]) {
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
    if (cek_peti_penuh()) {
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_ladang;
        int idxRowPeti, idxColPeti, idxRowLadang, idxColLadang;
        Entitas* bibit = nullptr;
        Tanaman* tanamanBibit;

        while (true) {
            cout << "Silakan pilih tanaman yang ingin Anda tanam!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (!cek_slot_peti_valid(slot_masukan_peti)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti[idxRowPeti][idxColPeti].get();
                if (!Util::instanceof<Tanaman>(bibit)) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi tanaman." << endl;
                }
                else{
                    tanamanBibit = dynamic_cast<Tanaman*>(bibit);
                    cout << "Kamu memilih " << bibit->dapatkan_nama() << " untuk ditanam." << endl;
                    break;
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
                idxRowLadang = Util::indeks_baris_slot(slot_masukan_ladang);
                idxColLadang = Util::indeks_kolom_slot(slot_masukan_ladang);

                shared_ptr<Tanaman> tanah = ladang[idxRowLadang][idxColLadang];

                if(tanah){
                    cout << "Slot " << slot_masukan_peti << " milik tanaman lain." << endl;
                }
                else{
                    ladang[idxRowLadang][idxColLadang] = make_shared<Tanaman>(*tanamanBibit);
                    peti[idxRowPeti][idxColPeti].reset();
                    cout << "Cangkul, cangkul, cangkul yang dalam!" << endl;
                    cout << tanamanBibit->dapatkan_nama() << " berhasil ditanam!" << endl;
                    break;
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

unordered_map<string, int> Petani::frekuensi_panen() const {
    unordered_map<string, int> frequencyMap;

    // Iterate over the elements of ladang vector
    for (const auto& row : ladang) {
        for (const auto& tanamanPtr : row) {
            if (tanamanPtr && tanamanPtr.get()->bisa_panen()) {
                // Increment the frequency count for the Tanaman's name
                frequencyMap[tanamanPtr.get()->dapatkan_nama()]++;
            }
        }
    }

    return frequencyMap;
}

void Petani::panen() {
    cetak_ladang();
    
    unordered_map<string, int> frequencyMap = frekuensi_panen();

    // Display the names and frequencies of harvest-ready Tanaman objects
    cout << "Pilih tanaman siap panen yang kamu miliki:" << endl;
    
    int counter = 1;
    for (const auto& [nama, frequency] : frequencyMap) {
        cout << counter << ". " << nama << " (" << frequency << " petak siap panen)" << endl;
        counter++;
    }

}

int Petani::hitung_pajak() {
    int KKP, neto, KTKP;

    return 10;
}
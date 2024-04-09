#include "Peternak.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <cmath>

Peternak::Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan) : Pemain(nama, uang, berat_badan, ukuran_peti) {
    int row = get<0>(ukuran_peternakan);
    int col = get<1>(ukuran_peternakan);

    for (int i = 0; i < row; i++) {
        vector<shared_ptr<Hewan>> row;
        for (int j = 0; j < col; j++) {
            row.push_back(nullptr);
        }
        peternakan.push_back(row);
    }
}

Peternak::~Peternak() {};

void Peternak::cetak_peternakan() {
    int numRow = peternakan.size();
    int numCol = peternakan[0].size();
    int emptySlot = 0;


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
            if (!peternakan[n - 1][m].get()) {
                cout << "     |";
                emptySlot++;
            }
            else {
                Hewan* val = peternakan[n - 1][m].get();
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

bool Peternak::cek_slot_peternakan_valid(string slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    if (i < peternakan.size() and j < peternakan[0].size()) {
        return true;
    }

    return false;
};

void Peternak::ternak() {
    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())) {
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_peternakan;
        int idxRowPeti, idxColPeti, idxRowPeternakan, idxColPeternakan;
        shared_ptr<Entitas> bibit = nullptr;

        while (true) {
            cout << "Silakan pilih hewan yang ingin Anda ternak!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (!cek_slot_peti_valid(slot_masukan_peti)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti[idxRowPeti][idxColPeti];
                if (!Util::instanceof<Hewan>(bibit.get())) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi makanan." << endl;
                }
                else{
                    cout << "Kamu memilih " << bibit->dapatkan_nama() << " untuk dipelihara." << endl;
                    break;
                }
            }
        }

        cetak_peternakan();

        while (true) {
            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peternakan;

            if (!cek_slot_peti_valid(slot_masukan_peternakan)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeternakan = Util::indeks_baris_slot(slot_masukan_peternakan);
                idxColPeternakan = Util::indeks_kolom_slot(slot_masukan_peternakan);

                shared_ptr<Hewan> tanah = peternakan[idxRowPeternakan][idxColPeternakan];

                if(tanah){
                    cout << "Slot " << slot_masukan_peti << " milik tanaman lain." << endl;
                }
                else{
                    // peternakan[idxRowPeternakan][idxColPeternakan] = make_shared<Karnivora>(hewanBibit);
                    shared_ptr<Hewan> hewanPtr = dynamic_pointer_cast<Hewan>(bibit);
                    tambah_peternakan(slot_masukan_peternakan, hewanPtr);
                    peti[idxRowPeti][idxColPeti].reset();
                    cout << "Ternak, ternak, ternak yang banyak!" << endl;
                    cout << bibit.get()->dapatkan_nama() << " berhasil ditanam!" << endl;
                    break;
                }
            }
        }
    };
};

void Peternak::tambah_peternakan(string slot, shared_ptr<Hewan> val) {
    if (cek_slot_peternakan_valid(slot)) {
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (peternakan[i][j] == nullptr) {
            peternakan[i][j] = val;
        }
        else {
            cout << "Ada isinya" << endl;
        }
    }
    else {
        cout << "index out of bonds" << endl;
    }
};

Hewan* Peternak::hapus_peternakan(string slot) {
    if (cek_slot_peternakan_valid(slot)) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (peternakan[idxRow][idxCol] != nullptr) {
            Hewan* delHewan = peternakan[idxRow][idxCol].get();
            peternakan[idxRow][idxCol] = nullptr;

            return delHewan;
        }
    }

    return nullptr;
};

void Peternak::beri_pangan() {
    cetak_peternakan();

    string slot_masukan;

    cout << "Slot hewan yang ingin diberi makan: ";
    cin >> slot_masukan;

    cout << slot_masukan;

    if (cek_slot_peternakan_valid(slot_masukan)) {
        int idxRow = Util::indeks_baris_slot(slot_masukan);
        int idxCol = Util::indeks_kolom_slot(slot_masukan);

        Hewan* val = peternakan[idxRow][idxCol].get();

        if (val) {
            cout << "Kamu ingin memberi makan " << val->dapatkan_nama() << endl;

            cout << "Pilih pangan yang akan diberikan: ";

            cetak_peti();

            cout << "Makanan ingin kamu berikan adalah: ";
        }
        else {
            cout << "Mau ngasih makan setan?";
        }
    }
};

void Peternak::panen() {
    cetak_peternakan();
};


int Peternak::hitung_pajak() {
    int KKP, neto, KTKP;

    return 10;
}
#include "Petani.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <cmath>

Petani::Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang) : Pemain(nama, uang, berat_badan, ukuran_peti), ladang(get<0>(ukuran_ladang), get<1>(ukuran_ladang)) {}

Petani::~Petani() {};

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
            if (ladang.apakahSlotKosong(n - 1, m)) {
                cout << "     |";
                // emptySlot++;
            }
            else {
                Tanaman* val = ladang.dapatkanElemen(n - 1, m);
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

    // cout << endl << "Total slot kosong: " << ladang.jumlahSlotKosong() << endl;
};

bool Petani::cek_ladang_penuh() {
    return ladang.penuh();
};

bool Petani::cek_ladang_kosong() {
    return ladang.kosong();
};

int Petani::jumlah_slot_kosong_ladang() {
    return ladang.jumlahSlotKosong();
};

bool Petani::cek_slot_ladang_valid(const string& slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    return ladang.apakahIndexValid(i,j);
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
                bibit = peti.dapatkanElemen(idxRowPeti, idxColPeti);
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

                shared_ptr<Tanaman> tanah(ladang.dapatkanElemen(idxRowLadang, idxColLadang));

                if(tanah){
                    cout << "Slot " << slot_masukan_peti << " milik tanaman lain." << endl;
                }
                else{
                    ladang.editElemen(idxRowLadang, idxColLadang, tanamanBibit);
                    peti.hapus(idxRowPeti, idxColPeti);
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

        if (ladang.apakahSlotKosong(i,j)) {
            ladang.editElemen(i, j, &val);
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
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);

    return ladang.hapus(idxRow, idxCol);
}

unordered_map<string, int> Petani::frekuensi_panen() {
    unordered_map<string, int> frequencyMap;

    // Iterate over the elements of ladang matriks
    for (int i=0; i<ladang.dapatkanBaris(); i++) {
        for (int j=0; j<ladang.dapatkanKolom(); j++){
            Tanaman* tan = ladang.dapatkanElemen(i,j);
            if (tan && tan->bisa_panen()) {
                // Increment the frequency count for the Tanaman's name
                frequencyMap[tan->dapatkan_nama()]++;
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
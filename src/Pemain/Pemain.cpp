#include "Pemain.hpp"
#include <cmath>

Pemain::Pemain(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) {
    this->nama = nama;
    this->uang = uang;
    this->berat_badan = berat_badan;

    int row = get<0>(ukuran_peti);
    int col = get<1>(ukuran_peti);

    for (int i = 0; i < row; i++) {
        vector<shared_ptr<Entitas>> row;
        for (int j = 0; j < col; j++) {
            row.push_back(nullptr);
        }
        peti.push_back(row);
    }
}

string Pemain::dapatkan_nama() {
    return this->nama;
}

void Pemain::atur_uang(int uang) {
    this->uang = uang;
}

int Pemain::dapatkan_uang() {
    return this->uang;
}

void Pemain::atur_berat_badan(int berat) {
    this->berat_badan = berat;
}

int Pemain::dapatkan_berat_badan() {
    return this->berat_badan;
}

void Pemain::cetak_peti() {
    int numRow = peti.size();
    int numCol = peti[0].size();
    int emptySlot = 0;

    //  Cari tau label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // Cetak judul tabel
    cout << "    ================[ Penyimpanan ]==================\n\n";

    // cetak nama kolom
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

    // Cetak nama baris dan isi elemennya
    for (int n = 1; n <= numRow; n++) {
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode + 1 - label_baris.length(), ' ');

        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++) {
            if (!peti[n - 1][m]) {
                cout << "     |";
                emptySlot++;
            }
            else {
                cout << " ";
                cout << peti[n - 1][m].get()->dapatkan_kode_huruf(); // kode huruf
                cout << " |";
            }

        }
        cout << endl;

        // cetak +---+
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

    cout << endl << "Total slot kosong: " << emptySlot << endl;
}

template<class T>
void Pemain::tambah_peti(const string& slot, T& val) {
    if (cek_slot_peti_valid(slot)) {
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (!peti[i][j]) {
            peti[i][j] = make_shared<T>(val);;
        }
        else {
            cout << "Ada isinya" << endl;
        }
    }
    else {
        cout << "index out of bonds" << endl;
    }
}

template<class T>
void Pemain::tambah_peti(T& val) {
    bool isInserted = false;

    for (int i = 0; i < peti.size(); i++) {
        for (int j = 0; j < peti[0].size(); j++) {
            if (!peti[i][j]) {
                peti[i][j] = make_shared<T>(val);
                isInserted = true;
                break;
            }
        }

        if (isInserted) {
            break;
        }
    }
}

Entitas* Pemain::hapus_peti(const string& slot) {
    if (cek_slot_peti_valid(slot)) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (peti[idxRow][idxCol]) {
            Entitas* delEntitas = peti[idxRow][idxCol].get();
            peti[idxRow][idxCol].reset();

            return delEntitas;
        }
    }

    return nullptr;
}

bool Pemain::cek_slot_peti_valid(const string& slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    if (i < peti.size() and j < peti[0].size()) {
        return true;
    }

    return false;
}

int Pemain::jumlah_slot_kosong_peti() {
    int emptySlot = 0;

    for (int i = 0; i < peti.size(); i++) {
        for (int j = 0; j < peti[0].size(); j++) {
            if (peti[i][j] == nullptr) {
                emptySlot++;
            }
        }
    }

    return emptySlot;
};

bool Pemain::cek_bisa_dimakan(const string& slot) {        // Belom di test
    if (cek_slot_peti_valid(slot)) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (peti[idxRow][idxCol] != nullptr) {
            if (Util::instanceof<Produk>(peti[idxRow][idxCol].get())) {
                return true;
            }
        }
    }

    return false;
}

void Pemain::jual() {
    cetak_peti();

    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())) {
        cout << "Gak punya harta kok mau jual!" << endl;
    }
    else {
        cout << "Silakan pilih petak yang ingin Anda jual!" << endl;
        cout << "Petak : ";

        string slot_masukan;
        getline(cin, slot_masukan);

        istringstream iss(slot_masukan);
        vector<string> list_slot_masukan;

        string slot;
        while (getline(iss, slot, ',')) {
            slot.erase(0, slot.find_first_not_of(" \t"));
            slot.erase(slot.find_last_not_of(" \t") + 1);
            list_slot_masukan.push_back(slot);
        }

        for (const string& cell : list_slot_masukan) {
            cout << "Anda memilih slot: " << cell << endl;
        }

        // TINGGAL JUAL KE TOKO
    }
}

void Pemain::beli() {
    cetak_peti();

    if (jumlah_slot_kosong_peti() == 0) {
        cout << "Peti nya penuh! Cari kantong kresek sana!" << endl;
    }
    else {
        cout << "Selamat Datang di Bacin Mart" << endl;

        // TINGGAL JUAL KE TOKO
    }
}

void Pemain::makan() {       // Belom di test dan tinggal perbaikin print-an
    cout << "Pilih makanan dari penyimpanan\n\n";

    this->cetak_peti();

    while (true) {
        try {
            string slot;
            cout << "Slot: ";
            cin >> slot;
            cout << endl;

            if (!this->cek_slot_peti_valid(slot)) {   // Validasi slot
                throw "Slot tidak valid\n";
            }

            // Validasi isi sloat kosong atau tidak
            if (this->peti[Util::indeks_baris_slot(slot)][Util::indeks_kolom_slot(slot)] == nullptr) {
                throw "Slot yang dipilih kosong\n";
            }

            if (!this->cek_bisa_dimakan(slot)) {   // Validasi makanan
                // Handle the case where makanan is not a Produk
                throw "Slot yang dipilih tidak bisa dimakan\n";
            }

            Entitas* makanan = this->hapus_peti(slot);

            if (Produk* produk = dynamic_cast<Produk*>(makanan)) {
                this->atur_berat_badan(this->dapatkan_berat_badan() + produk->dapatkan_berat_tambahan());
            }
            else {
                // Handle the case where makanan is not a Produk
                throw "Slot yang dipilih tidak bisa dimakan\n";
            }

            cout << "Dengan lahapnya, kamu memakanan hidangan itu\n";
            cout << "Alhasil, berat badan kamu naik menjadi " << this->dapatkan_berat_badan() << "\n\n";
        }
        catch (const char* e) {
            cout << e << endl << endl;
        }
    }

}

ostream& operator<<(ostream& out, Pemain p) {
    out << "nama : " << p.nama << endl;
    out << "uang : " << p.uang << endl;
    out << "berat : " << p.berat_badan << endl;

    p.cetak_peti();

    out << endl;

    return out;
}
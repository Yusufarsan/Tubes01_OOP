#include "Pemain.hpp"
#include "Walikota.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
#include "../Util/Util.hpp"
#include "../Toko/Toko.hpp"
#include <cmath>

Pemain::Pemain(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti): nama(nama), uang(uang), berat_badan(berat_badan), peti(get<0>(ukuran_peti), get<1>(ukuran_peti)){}

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
    int numRow = peti.dapatkanBaris();
    int numCol = peti.dapatkanKolom();

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
            if (peti.apakahSlotKosong(n-1,m)) {
                cout << "     |";
            }
            else {
                cout << " ";
                cout << peti.dapatkanElemen(n - 1,m)->dapatkan_kode_huruf(); // kode huruf
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

    cout << endl << "Total slot kosong: " << peti.jumlahSlotKosong() << endl;
}

Entitas* Pemain::hapus_peti(const string& slot){
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);
    return peti.hapus(idxRow, idxCol);
}

bool Pemain::cek_slot_peti_valid(const string& slot){
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);
    return peti.apakahIndexValid(idxRow, idxCol);
}

bool Pemain::cek_peti_penuh(){
    return peti.penuh();
}

bool Pemain::cek_peti_kosong(){
    return peti.kosong();
}

int Pemain::jumlah_slot_kosong_peti(){
    return peti.jumlahSlotKosong();
}

bool Pemain::cek_bisa_dimakan(const string& slot) {        // Belom di test
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);
    if (peti.apakahIndexValid(idxRow, idxCol)) {
        if (!peti.apakahSlotKosong(idxRow, idxCol)) {
            if (Util::instanceof<Produk>(peti.dapatkanElemen(idxRow, idxCol))) {
                return true;
            }
        }
    }else{
        cout << "masukan slot yang valid" <<endl;
    }

    return false;
}

int Pemain::hitung_pajak() {
    return 0;
}

void Pemain::jual(Toko& toko) {
    cetak_peti();

    if (cek_peti_kosong()) {
        cout << "Gak punya harta kok mau jual!" << endl;
    }
    else {
        string slot_masukan;
        bool isWalikota;
        if(Util::instanceof<Walikota>(this)){
            isWalikota = true;
        }else{
            isWalikota = false;

        }

        // Menampilkan apa saja yang dapat dibeli oleh role;
        toko.tampilBarang(isWalikota);

        // Memilih petak
        cout << "Silakan pilih petak yang ingin Anda jual!" << endl;
        cout << "Petak : ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, slot_masukan);


        istringstream iss(slot_masukan);
        vector<string> list_slot_masukan;

        string slot;
        while (getline(iss, slot, ',')) {
            slot.erase(0, slot.find_first_not_of(" \t"));
            slot.erase(slot.find_last_not_of(" \t") + 1);
            list_slot_masukan.push_back(slot);
        }

        // TINGGAL JUAL KE TOKO
        for (const string& cell : list_slot_masukan) {
            cout << "Anda memilih slot: " << cell << endl;

            int row = Util::indeks_baris_slot(cell);
            int col = Util::indeks_kolom_slot(cell);
            Entitas* ent = peti.dapatkanElemen(row, col);
            if(!peti.apakahSlotKosong(row, col)){
                if(Util::instanceof<Bangunan>(ent)){
                    if(!isWalikota){
                        cout << "   Kamu gabisa jual " << ent->dapatkan_nama() << endl;
                        break;
                    }

                }
                cout << "   -> " << ent->dapatkan_nama() << " dengan harga " << ent->dapatkan_harga() << endl;
                
                // Tambahkan uang ke pemain
                atur_uang(dapatkan_uang()+ent->dapatkan_harga());

                // Tambahkan barang ke toko
                toko.masukanEntitas(ent);

                cout << "   Berhasil menjual " << ent->dapatkan_nama() << endl;
                ent = peti.hapus(row, col);
            }else{
                cout << "ups, untuk yang ini barangnya gaada nih.." << endl;
            }
        }


    }
}

void Pemain::beli() {
    cetak_peti();

    if (cek_peti_penuh()) {
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
            int row = Util::indeks_baris_slot(slot);
            int col = Util::indeks_kolom_slot(slot);

            if (!peti.apakahIndexValid(row,col)) {   // Validasi slot
                throw "Slot tidak valid\n";
            }

            // Validasi isi sloat kosong atau tidak
            if (peti.apakahSlotKosong(row,col)) {
                throw "Slot yang dipilih kosong\n";
            }

            if (!cek_bisa_dimakan(slot)) {   // Validasi makanan
                // Handle the case where makanan is not a Produk
                throw "Slot yang dipilih tidak bisa dimakan\n";
            }

            Entitas* makanan = peti.hapus(row, col);

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
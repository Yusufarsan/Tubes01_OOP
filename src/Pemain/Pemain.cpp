#include "Pemain.hpp"
#include <cmath>

// Nanti ukuran peti 15, 10 nya diganti dari config
Pemain::Pemain(string nama, int uang, int berat_badan) 
    : nama(nama), uang(uang), berat_badan(berat_badan), peti(15, vector<Entitas*>(10, nullptr)){
}

string Pemain::dapatkan_nama(){
    return this->nama;
}

void Pemain::atur_uang(int uang){
    this->uang = uang;
}

int Pemain::dapatkan_uang(){
    return this->uang;
}

void Pemain::atur_berat_badan(int berat){
    this->berat_badan = berat;
}

int Pemain::dapatkan_berat_badan(){
    return this->berat_badan;
}

void Pemain::cetak_peti(){
    int numRow = peti.size();
    int numCol = peti[0].size();
    int emptySlot = 0;

    //  Cari tau label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // cetak nama kolom
    for (int n = 1; n <= numCol; ++n){
        if (n == 1){
            string spaces(maxLengthRowCode+1, ' ');
            cout << spaces;
        }

        string label_kolom = Util::label_kolom_tabel(n);
        int pad1Length = round(double(6-label_kolom.length())/2);
        int pad2Length;

        if ((6-label_kolom.length()) % 2 == 1){
            pad2Length = pad1Length-1;
        }
        else{
            pad2Length = pad1Length;
        }
        
        string pad1(pad1Length, ' ');
        string pad2(pad2Length, ' ');

        cout << pad1 << label_kolom << pad2;
    }
    cout << endl;

    // first +---+
    for (int n = 1; n <= numCol; n++){
        if (n == 1){
            string spaces(maxLengthRowCode+1, ' ');
            cout << spaces;
        }

        string dash(5, '-');
        cout << "+" << dash;
    }
    cout << "+\n";

    // Cetak nama baris dan isi elemennya
    for (int n = 1; n <= numRow; n++){
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode+1-label_baris.length(), ' ');

        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++){
            if (peti[n-1][m] == nullptr){
                cout << "     |";
                emptySlot++;
            }
            else{
                cout << " " << "TAI" << " |";
            }
            
        }
        cout << endl;

        // cetak +---+
        for (int n = 1; n <= numCol; n++){
            if (n == 1){
                string spaces(maxLengthRowCode+1, ' ');
                cout << spaces;
            }

            string dash(5, '-');
            cout << "+" << dash;
        }
        cout << "+\n";
    };

    cout << endl << "Total slot kosong: " << emptySlot << endl;
}

void Pemain::tambah_peti(string slot, Entitas* val){
    if (cek_slot_peti_valid(slot)){
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (peti[i][j] == nullptr){
            peti[i][j] = val;
        }
        else{
            cout << "Ada isinya" << endl;
        }
    }
    else{
        cout << "index out of bonds" << endl;
    }
}

Entitas* Pemain::hapus_peti(string slot) {
    if (cek_slot_peti_valid(slot)){
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (peti[idxRow][idxCol] != nullptr){
            Entitas* delEntitas = peti[idxRow][idxCol];
            peti[idxRow][idxCol] = nullptr;

            return delEntitas;
        }
    }

    return nullptr;
}

bool Pemain::cek_slot_peti_valid(string slot){
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    cout << "Indeks peti [" << i << "][" << j << "]" << endl;

    if (i < peti.size() and j < peti[0].size()){
        return true;
    }

    return false;
}

int Pemain::jumlah_slot_kosong_peti(){
    int emptySlot = 0;

    for (int i = 0; i < peti.size(); i++){
        for (int j = 0; j < peti[0].size(); j++){
            if (peti[i][j] == nullptr){
                emptySlot++;
            }            
        }
    }

    return emptySlot;
};

void Pemain::jual(){
    cetak_peti();

    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())){
        cout << "Gak punya harta kok mau jual!" << endl;
    }
    else{
        cout << "Silakan pilih petak yang ingin Anda jual!" << endl;
        cout << "Petak : ";

        string slot_masukan;
        getline(cin, slot_masukan);

        istringstream iss(slot_masukan);
        vector<string> list_slot_masukan;

        string slot;
        while (getline(iss, slot, ',')){
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

void Pemain::beli(){
    cetak_peti();

    if (jumlah_slot_kosong_peti() == 0){
        cout << "Peti nya penuh! Cari kantong kresek sana!" << endl;
    }
    else{
        cout << "Selamat Datang di Bacin Mart" << endl;

        // TINGGAL JUAL KE TOKO
    }
}

void Pemain::makan(){
    cetak_peti();

    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())){
        cout << "Peti nya kosong! Mau makan angin?" << endl;
    }
    else{
        string slot_masukan;
        cout << "Mau makan slot berapa? ";
        cin >> slot_masukan;

        cout << slot_masukan << endl;
    }


    // cout << "Pilih makanan dari penyimpanan\n\n";

    // this->cetak_peti();

    // while (true) {
    //     try {
    //         string slot;
    //         cout << "\nSlot: ";
    //         cin >> slot;
    //         cout << endl;

    //         if (!this->cek_slot_peti_valid(slot)) {   // Validasi slot
    //             throw ;
    //         }

    //         Entitas* makanan = this->hapus_peti(slot);

    //         if (Produk* produk = dynamic_cast<Produk*>(makanan)) {
    //             this->atur_berat_badan(this->dapatkan_berat_badan() + produk->dapatkan_berat_tambahan());
    //         } else {
    //             // Handle the case where makanan is not a Produk
    //             throw;
    //         }

    //         // cout << 
    //     }
    //     catch (...) {
    //         cout << "Slot tidak valid\n";
    //     }
    // }

}

ostream& operator<<(ostream& out, Pemain p){
    out << "nama : " << p.nama << endl;
    out << "uang : " << p.uang << endl;
    out << "berat : " << p.berat_badan << endl;

    p.cetak_peti();

    out << endl;

    return out;
}
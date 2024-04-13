#include "Pemain.hpp"
#include "Walikota.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
#include <cmath>

Pemain::Pemain(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti): 
    nama(nama), 
    uang(uang), 
    berat_badan(berat_badan), 
    peti(get<0>(ukuran_peti), get<1>(ukuran_peti))
    {}

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

Matrix<Entitas> Pemain::dapatkan_peti() {
    return this->peti;
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
            if (peti.apakah_slot_kosong(n-1, m)) {
                cout << "     |";
            }
            else {
                cout << " ";
                cout << peti.dapatkan_elemen(n - 1, m)->dapatkan_kode_huruf(); // kode huruf
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

    cout << endl << "Total slot kosong: " << peti.jumlah_slot_kosong() << endl;
}

// Entitas* Pemain::hapus_peti(const string& slot){
//     int idxRow = Util::indeks_baris_slot(slot);
//     int idxCol = Util::indeks_kolom_slot(slot);
    
//     return peti.hapus(idxRow, idxCol);
// }

// bool Pemain::cek_slot_peti_valid(const string& slot){   
//     int idxRow = Util::indeks_baris_slot(slot);
//     int idxCol = Util::indeks_kolom_slot(slot);
//     return peti.apakahIndexValid(idxRow, idxCol);
// }

// bool Pemain::cek_peti_penuh(){
//     return peti.penuh();
// }

// bool Pemain::cek_peti_kosong(){
//     return peti.kosong();
// }

// int Pemain::jumlah_slot_efektif_peti(){
//     return peti.jumlahElement();
// }

// int Pemain::jumlah_slot_kosong_peti(){
//     return peti.jumlah_slot_kosong();
// }

bool Pemain::cek_bisa_dimakan(const string& slot) {        // Belom di test
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);
    if (peti.apakah_index_valid(idxRow, idxCol)) {
        if (!peti.apakah_slot_kosong(idxRow, idxCol)) {
            if (Util::instanceof<Produk>(peti.dapatkan_elemen(idxRow, idxCol).get())) {
                return true;
            }
        }
    }else{
        cout << "masukan slot yang valid" <<endl;
    }

    return false;
}

void Pemain::jual(Toko& toko) {
    cetak_peti();

    if (peti.apakah_kosong()) {
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
            shared_ptr<Entitas> ent = peti.dapatkan_elemen(row, col);
            if(!peti.apakah_slot_kosong(row, col)){
                if(Util::instanceof<Bangunan>(ent.get())){
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
                peti.hapus(row, col);
            }else{
                cout << "ups, untuk yang ini barangnya gaada nih.." << endl;
            }
        }


    }
}

void Pemain::membeli(Toko& toko) {
    if (peti.apakah_penuh()) {
        cout << "Peti nya penuh! Cari kantong kresek sana!" << endl;
    }
    else {
        cout << "Selamat Datang di Bacin Mart" << endl;
        cout << "Berikut merupakan barang yang bisa kamu beli" << endl;

        bool isWalikota;
        if(Util::instanceof<Walikota>(this)){
            isWalikota = true;
        }else{
            isWalikota = false;

        }
        toko.tampilBarang(isWalikota);
        cout << endl;

        cout << "Uang Anda : " << uang << endl;
        cout << "Slot penyimpanan tersedia: " << peti.jumlah_slot_kosong() << endl;
        cout << endl;

        int num, kuantitas;
        cout << "Barang ingin dibeli : ";
        cin >> num;
        cout << "Kuantitas : ";
        cin >> kuantitas;

        if (kuantitas >  peti.jumlah_slot_kosong()) {
            cout << "Slot penyimpanan tidak cukup" << endl;
        } else {
            shared_ptr<Entitas> barang = toko.dapatkan_entitas(num);
            if (kuantitas*barang->dapatkan_harga() > uang) {
                cout << "Uang tidak cukup" << endl;
            } else {
                if (Util::instanceof<Produk>(barang.get())) {
                    toko.kurangi_produk(dynamic_pointer_cast<Produk>(barang));
                } else if (Util::instanceof<Bangunan>(barang.get())) {
                    toko.kurangi_bangunan(dynamic_pointer_cast<Bangunan>(barang));
                }

                uang -= kuantitas*barang->dapatkan_harga();
                cout << "Selamat Anda berhasil membeli " << kuantitas << " " << barang->dapatkan_nama() << ".";
                cout << " Uang Anda tersisa " << uang << " gulden." << endl;
                cout << endl;

                cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
                this->cetak_peti();

                cout << "Petak slot: ";
                string slot_masukan;
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

                for (const string& cell : list_slot_masukan) {
                    int row = Util::indeks_baris_slot(cell);
                    int col = Util::indeks_kolom_slot(cell);
                    if (peti.apakah_index_valid(row, col)) {
                        if (peti.apakah_slot_kosong(row, col)) {
                            peti.tambah_elemen_matriks(row, col, barang);
                        } else{
                            throw "Slot yang dipilih sudah terisi";
                        }
                    } else {
                        throw "Slot yang dipilih tidak valid";
                    }
                }
                
                cout << barang->dapatkan_nama() << " berhasil disimpan dalam penyimpanan!" << endl;
            }
        }
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

            if (!peti.apakah_index_valid(row,col)) {   // Validasi slot
                throw "Slot tidak valid\n";
            }

            // Validasi isi sloat kosong atau tidak
            if (peti.apakah_slot_kosong(row,col)) {
                throw "Slot yang dipilih kosong\n";
            }

            if (!cek_bisa_dimakan(slot)) {   // Validasi makanan
                // Handle the case where makanan is not a Produk
                throw "Slot yang dipilih tidak bisa dimakan\n";
            }

            shared_ptr<Entitas> makanan = peti.hapus(row, col);

            if (Produk* produk = dynamic_cast<Produk*>(makanan.get())) {
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
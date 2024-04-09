#include "Peternak.hpp"
#include "../pcolor/pcolor.h"
#include <cmath>

// nanti ganti 50, 10, 15, 10
Peternak::Peternak(string nama): Pemain(nama, 50, 10), peternakan(15, vector<shared_ptr<Hewan>>(10, nullptr)){
}

Peternak::~Peternak(){};

void Peternak::cetak_peternakan(){
    int numRow = peternakan.size();
    int numCol = peternakan[0].size();
    int emptySlot = 0;


    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // cetak label kolom
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

    // cetak label baris dan elementnnya
    for (int n = 1; n <= numRow; n++){
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode+1-label_baris.length(), ' ');
        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++){
            if (!peternakan[n-1][m]){
                cout << "     |";
                emptySlot++;
            }
            else{
                Hewan* val = peternakan[n-1][m].get();
                if (val->bisa_panen()){
                    cout << " ";
                    
                    for (char c: val->dapatkan_kode_huruf()){
                        print_green(c);
                    }

                    cout << " |";
                }
                else{
                    cout << " ";
                    
                    for (char c: val->dapatkan_kode_huruf()){
                        print_red(c);
                    }

                    cout << " |";
                }
            }
        }
            
    }
    cout << endl;

    // +---+
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

bool Peternak::cek_slot_peternakan_valid(string slot){
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    if (i < peternakan.size() and j < peternakan[0].size()){
        return true;
    }

    return false;
};

void Peternak::ternak(){
    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())){
        cout << "Gak punya penyimpanan kok mau ternak!" << endl;
    }
    else{
        cetak_peti();

        string slot_masukan_peti, slot_masukan_peternakan;
        int i, j;
        Entitas* bibit = nullptr;

        while(true){
            cout << "Silakan pilih hewan yang ingin Anda ternak!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if(!cek_slot_peti_valid(slot_masukan_peti)){
                cout << "Slot tidak valid" << endl;
            }
            else{
                i = Util::indeks_baris_slot(slot_masukan_peti);
                j = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti[i][j].get();
                if(!Util::instanceof<Hewan>(bibit)){
                    cout << "Slot " << slot_masukan_peti << " tidak berisi hewan." << endl;
                }
                else{
                    cout << "Kamu memilih " << bibit->dapatkan_nama() << " untuk diternak." << endl;
                }
            }
        }

        cetak_peternakan();
        
        while(true){
            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peternakan;

            if(!cek_slot_peti_valid(slot_masukan_peternakan)){
                cout << "Slot tidak valid" << endl;
            }
            else{
                i = Util::indeks_baris_slot(slot_masukan_peternakan);
                j = Util::indeks_kolom_slot(slot_masukan_peternakan);

                shared_ptr<Hewan> tanah = peternakan[i][j];

                if(!tanah){
                    cout << "Slot " << slot_masukan_peti << " kosong." << endl;
                }
                else{
                    cout << "Ternak, ternak, ternak yang banyak!" << endl;
                    cout << tanah.get()->dapatkan_nama() << " telah menjadi peliharaanmu sekarang!" << endl;
                }
            }
        }
    };
};

void Peternak::tambah_peternakan(string slot, Hewan& val){
    if (cek_slot_peternakan_valid(slot)){
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if(peternakan[i][j] == nullptr){
            peternakan[i][j] = &val;
        }
        else{
            cout << "Ada isinya" << endl;
        }
    }
    else{
        cout << "index out of bonds" << endl;
    }
};

Hewan* Peternak::hapus_peternakan(string slot){
    if (cek_slot_peternakan_valid(slot)){
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (peternakan[idxRow][idxCol] != nullptr){
            Hewan* delHewan = peternakan[idxRow][idxCol].get();
            peternakan[idxRow][idxCol] = nullptr;

            return delHewan;
        }
    }

    return nullptr;
};

void Peternak::beri_pangan(){
    cetak_peternakan();

    string slot_masukan;

    cout  << "Slot hewan yang ingin diberi makan: ";
    cin >> slot_masukan;

    cout << slot_masukan;

    if (cek_slot_peternakan_valid(slot_masukan)){
        int idxRow = Util::indeks_baris_slot(slot_masukan);
        int idxCol = Util::indeks_kolom_slot(slot_masukan);

        Hewan* val = peternakan[idxRow][idxCol].get();

        if (val){
            cout << "Kamu ingin memberi makan " << val->dapatkan_nama() << endl;

            cout << "Pilih pangan yang akan diberikan: ";

            cetak_peti();

            cout  << "Makanan ingin kamu berikan adalah: ";
        }
        else{
            cout << "Mau ngasih makan setan?";
        }
    }
};

void Peternak::panen(){
    cetak_peternakan();
};


int Peternak::hitung_pajak(){
    int KKP, neto, KTKP;

    return 10;
}
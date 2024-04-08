#include "Petani.hpp"
#include "../pcolor/pcolor.h"
#include <cmath>

// Ganti 50, 10, 15, 10 sesuai konfig
Petani::Petani(string nama): Pemain(nama, 50, 10), ladang(15, vector<Tanaman*>(10, nullptr)){
}

Petani::~Petani(){};

void Petani::cetak_ladang(bool isWarna){
    int numRow = ladang.size();
    int numCol = ladang[0].size();
    int emptySlot = 0;

    // dapatkan label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // label kolom
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

    // cetak label baris dan elemennya
    for (int n = 1; n <= numRow; n++){
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode+1-label_baris.length(), ' ');
        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++){
            if (ladang[n-1][m] == nullptr){
                cout << "     |";
                emptySlot++;
            }
            else{
                Tanaman* val = ladang[n-1][m];
                if (isWarna){
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
                else{
                    cout << " " << "TAI" << " |";
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
};

int Petani::jumlah_slot_kosong_ladang(){
    int emptySlot = 0;

    for (int i = 0; i < ladang.size(); i++){
        for (int j = 0; j < ladang[0].size(); j++){
            if (ladang[i][j] == nullptr){
                emptySlot++;
            }            
        }
    }

    return emptySlot;
};

bool Petani::cek_slot_ladang_valid(string slot){
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    cout << "Indeks ladang [" << i << "][" << j << "]" << endl;

    if (i < ladang.size() and j < ladang[0].size()){
        return true;
    }

    return false;
};

void Petani::tanam(){
    cetak_peti();

    if (jumlah_slot_kosong_peti() == (peti.size() * peti[0].size())){
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else{
        // ada penyimpanan, cek ada tanaman gak?
        // baru lanjut
        cout << "Silakan pilih tanaman yang ingin Anda tanam!" << endl;
        cout << "Petak : ";

        string slot_masukan;
        cin >> slot_masukan;

        cout << slot_masukan;
    };
};


void Petani::tambah_ladang(string slot, Tanaman& val){
    if (cek_slot_ladang_valid(slot)){
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (ladang[i][j] == nullptr){
            ladang[i][j] = &val;
        }
        else{
            cout << "Ada isinya" << endl;
        }
    }
    else{
        cout << "index out of bonds" << endl;
    }
}


Tanaman* Petani::hapus_ladang(string slot){
    if (cek_slot_ladang_valid(slot)){
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (ladang[idxRow][idxCol] != nullptr){
            Tanaman* delTanaman = ladang[idxRow][idxCol];
            ladang[idxRow][idxCol] = nullptr;

            return delTanaman;
        }
    }

    return nullptr;
}

void Petani::panen(){
    cetak_ladang(true);
}

int Petani::hitung_pajak(){
    int KKP, neto, KTKP;

    return 10;
}
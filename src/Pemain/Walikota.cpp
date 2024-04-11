#include "Walikota.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "../Util/Util.hpp"
#include <algorithm>

Walikota::Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) : Pemain(nama, uang, berat_badan, ukuran_peti) {}

Walikota::Walikota(const Walikota& other) : Pemain(other.nama, other.uang, other.berat_badan, tuple<int, int>(other.peti.dapatkanBaris(), other.peti.dapatkanKolom())) {}

Walikota::~Walikota() {}

void Walikota::tambahPemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int,int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan){
    if(uang>=50){
        string namaPemain;
        string jenisPemain;

        cout << "Masukan nama pemain: " ;
        cin >> namaPemain;
        cout << "Masukan jenis pemain: ";
        cin >> jenisPemain;

        bool isFound = false;
        int i = 0;
        while(isFound && i<daftarPemain->size()){
            if((*daftarPemain)[i]->dapatkan_nama()==namaPemain){
                isFound = true;
            }
            i++;
        }
        if(!isFound){
            if(Util::strComp(jenisPemain, "peternak")){
                shared_ptr<Pemain> pemainBaru = make_unique<Peternak>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_peternakan);
                daftarPemain->push_back(pemainBaru);
                this->uang -= 50;
                cout<<"Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
            }else if(Util::strComp(jenisPemain, "petani")){
                shared_ptr<Pemain> pemainBaru = make_unique<Petani>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_lahan);
                daftarPemain->push_back(pemainBaru);
                this->uang -= 50;
                cout<<"Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
            }else if(Util::strComp(jenisPemain, "walikota")){
                cout<<"Walikota nya satu aja yah, biar ga berantem" << endl;
            }else{
                cout<<"Role ini tidak tersedia" << endl;
            }
        }else{
            cout << "Ups, namanya sudah digunakan nih..." << endl;
        }
    }else{
        cout<<"Uang tidak cukup!" << endl;
    }
}
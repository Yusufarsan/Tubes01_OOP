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
bool Walikota::bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b) {
    return a->hitung_pajak() > b->hitung_pajak();
}

void Walikota::tagih_pajak(vector<shared_ptr<Pemain>> daftar_pemain) {
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;

    int pajak_pemain = 0;
    int jumlah_pajak = 0;
    sort(daftar_pemain.begin(), daftar_pemain.end(), bandingkan_pajak);
    for (int i = 0; i < daftar_pemain.size(); i++) {
        int j = 1;
        if (Util::instanceof<Petani>(daftar_pemain[i].get())) {
            shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(daftar_pemain[i]);
            pajak_pemain = petani->hitung_pajak();
            petani->atur_uang(petani->dapatkan_uang() - pajak_pemain);
            cout << j << ". " << petani->dapatkan_nama() << " - Petani: " << pajak_pemain << " gulden" << endl;
        } else if (Util::instanceof<Peternak>(daftar_pemain[i].get())) {
            shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(daftar_pemain[i]);
            pajak_pemain = peternak->hitung_pajak();
            peternak->atur_uang(peternak->dapatkan_uang() - pajak_pemain);
            cout << j << ". " << peternak->dapatkan_nama() << " - Peternak: " << pajak_pemain << " gulden" << endl;
        }
        jumlah_pajak += pajak_pemain;
        j++;
    }

    cout << endl;
    cout << "Negara mendapatkan pemasukan sebesar " << jumlah_pajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}
void Walikota::bangun() {}

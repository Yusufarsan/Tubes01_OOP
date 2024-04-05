#include "Pemain.hpp"
#include "../Produk/Produk.hpp"
using namespace std;

Pemain::Pemain(string nama, int uang, int berat_badan){
    this->nama = nama;
    this->uang = uang;
    this->berat_badan = berat_badan;
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
    cout << "cetak_peti belom dibuat euy" << endl;
}

void Pemain::tambah_peti(string slot, Entitas* val){
    cout << "tambah_peti belom dibuat euy" << endl;
}

Entitas* Pemain::hapus_peti(string slot){
    cout << "hapus_peti belom dibuat euy" << endl;
    return ;
}

bool Pemain::cek_slot_peti(string slot){
    cout << "cek_slot_peti belom dibuat euy" << endl;
    return false;
}

void Pemain::jual(){
    cout << "jual belom dibuat euy" << endl;
}

void Pemain::beli(){
    cout << "beli belom dibuat euy" << endl;
}

void Pemain::makan(){
    cout << "Pilih makanan dari penyimpanan\n\n";

    this->cetak_peti();

    while (true) {
        try {
            string slot;
            cout << "\nSlot: ";
            cin >> slot;
            cout << endl;

            if (!this->cek_slot_peti(slot)) {   // Validasi slot
                throw ;
            }

            Entitas* makanan = this->hapus_peti(slot);

            if (Produk* produk = dynamic_cast<Produk*>(makanan)) {
                this->atur_berat_badan(this->dapatkan_berat_badan() + produk->dapatkan_berat_tambahan());
            } else {
                // Handle the case where makanan is not a Produk
                throw;
            }

            // cout << 
        }
        catch (...) {
            cout << "Slot tidak valid\n";
        }
    }

}
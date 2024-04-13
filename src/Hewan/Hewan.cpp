#include "Hewan.hpp"

// 4 Sekawan
Hewan::Hewan(string id, string kode_huruf, string nama, int harga, int berat_panen) : berat(0), berat_panen(berat_panen), Entitas(id, kode_huruf, nama, harga) {};

Hewan::Hewan(Hewan& other) : Entitas(other), berat(other.dapatkan_berat()), berat_panen(other.dapatkan_berat_panen()) {}

Hewan :: ~Hewan() {}

Hewan& Hewan :: operator=(const Hewan& other) {
    berat = other.berat;
    berat_panen = other.berat_panen;
    Entitas::operator=(other);
    return *this;
}

// Getter & Setter
int Hewan::dapatkan_berat() {
    return berat;
}

int Hewan::dapatkan_berat_panen() {
    return berat_panen;
}

void Hewan::atur_berat(int berat) {
    this->berat = berat;
}

// Method
void Hewan::tambah_berat(int num) {
    this->berat += num;
}

bool Hewan::bisa_panen() {
    return berat >= berat_panen;
}

// Print Info
void Hewan::print_info() {
    cout << "ID: " << Entitas::id << endl;
    cout << "Kode Huruf: " << Entitas::nama << endl;
    cout << "Nama: " << Entitas::kode_huruf << endl;
    cout << "Harga: " << Entitas::harga << endl;
    cout << "Berat saat ini: " << berat << endl;
    cout << "Berat untuk panen: " << berat_panen << endl;
}
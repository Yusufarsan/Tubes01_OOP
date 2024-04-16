#include "Tanaman.hpp"

// 4 Sekawan
Tanaman::Tanaman(string id, string kode_huruf, string nama, int harga, int umur_panen) :Entitas(id, kode_huruf, nama, harga) {
    this->umur_panen = umur_panen;
    umur = 0;
}

Tanaman::Tanaman(const Tanaman& other) : Entitas(other) {
    umur_panen = other.umur_panen;
    umur = other.umur;
}

Tanaman::~Tanaman() {}

Tanaman& Tanaman::operator=(const Tanaman& other) {
    if (this != &other) {
        this->id = other.id;
        this->kode_huruf = other.kode_huruf;
        this->nama = other.nama;
        this->harga = other.harga;
        this->umur_panen = other.umur_panen;
        this->umur = other.umur;
    }
    return *this;
}

// Getter & Setter
int Tanaman::dapatkan_umur() {
    return umur;
}

int Tanaman::dapatkan_umur_panen() {
    return umur_panen;
}

void Tanaman::atur_umur(int umur) {
    this->umur = umur;
}

// Method
void Tanaman::tambah_umur() {
    umur++;
}

bool Tanaman::bisa_panen() {
    return umur >= umur_panen;
}

// Print Info
void Tanaman::print_info() {
    cout << "ID: " << id << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Nama: " << nama << endl;
    cout << "Harga: " << harga << endl;
    cout << "Umur: " << umur << endl;
    cout << "Umur Panen: " << umur_panen << endl;
}
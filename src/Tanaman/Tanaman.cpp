#include "Tanaman.hpp"

Tanaman::Tanaman(int umur_panen): umur_panen(umur_panen) {
    umur = 0;
} 

Tanaman::Tanaman(Tanaman &other): umur_panen(other.umur_panen) {
    umur = other.umur;
}

Tanaman::~Tanaman() {}

Tanaman& Tanaman::operator=(const Tanaman &other): umur_panen(other.umur_panen) {
    umur = other.umur;
    return *this
}

int Tanaman::dapatkan_umur() {
    return umur;
}

int Tanaman::dapatkan_umur_panen() {
    return umur_panen;
}

void Tanaman::tambah_umur() {
    umur++;
}

bool Tanaman::bisa_panen() {
    if (umur == umur_panen) {
        return true;
    }
    return false;
} 
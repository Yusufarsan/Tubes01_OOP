#include "TanamanBuah.hpp"

TanamanBuah::TanamanBuah(int umur_panen): Tanaman(umur_panen) {
} 

TanamanBuah::TanamanBuah(TanamanBuah &other): Tanaman(other.umur_panen) {
}

TanamanBuah::~TanamanBuah() {}

TanamanBuah& TanamanBuah::operator=(const TanamanBuah &other): umur_panen(other.umur_panen) {
    umur = other.umur;
    return *this
}
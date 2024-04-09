#include "Walikota.hpp"

Walikota::Walikota(string nama, int uang, int berat_badan): Pemain(nama, uang, berat_badan) {
}

Walikota::Walikota(const Walikota& other): Pemain(other.nama, other.uang, other.berat_badan) {
}

Walikota::~Walikota() {}
#include "Walikota.hpp"

Walikota::Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) : Pemain(nama, uang, berat_badan, ukuran_peti) {}

Walikota::Walikota(const Walikota& other) : Pemain(other.nama, other.uang, other.berat_badan, tuple<int, int>(other.peti.size(), other.peti[0].size())) {}

Walikota::~Walikota() {}
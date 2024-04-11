#include "Walikota.hpp"
#include "../Util/Util.hpp"
#include "petani.hpp"
#include "peternak.hpp"
#include "Petani.hpp"
#include <Algorithm>

Walikota::Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) : Pemain(nama, uang, berat_badan, ukuran_peti) {}

Walikota::Walikota(const Walikota& other) : Pemain(other.nama, other.uang, other.berat_badan, tuple<int, int>(other.peti.dapatkanBaris(), other.peti.dapatkanKolom())) {}

Walikota::~Walikota() {}

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
void Walikota::tambah_petani(string nama) {}
void Walikota::tambah_peternak(string nama) {}
#include "ManajerPermainan.hpp"

int main() {
    ManagerPermainan mp("../config");

    mp.atur_pemain("../state");
    mp.inisialisasi_toko();

    vector<shared_ptr<Pemain>> daftar_pemain = mp.dapatkan_daftar_pemain();

    for (int i = 0; i < daftar_pemain.size(); i++) {
        cout << "Pemain " << i + 1 << endl;
        cout << "Nama: " << daftar_pemain[i]->dapatkan_nama() << endl;
        cout << "Uang: " << daftar_pemain[i]->dapatkan_uang() << endl;
        daftar_pemain[i]->cetak_peti();

        if (Util::instanceof<Petani>(daftar_pemain[i].get())) {
            shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(daftar_pemain[i]);
            petani->cetak_ladang();
        }
        else if (Util::instanceof<Peternak>(daftar_pemain[i].get())) {
            shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(daftar_pemain[i]);
            peternak->cetak_peternakan();
        }

        cout << endl;
    }

    Toko toko = mp.dapatkan_toko();
    toko.cetak_isi_toko();


    return 0;
}
#include "Walikota.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "../Util/Util.hpp"
#include <algorithm>

Walikota::Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) : Pemain(nama, uang, berat_badan, ukuran_peti) {}

Walikota::Walikota(const Walikota& other) : Pemain(other.nama, other.uang, other.berat_badan, tuple<int, int>(other.peti.dapatkanBaris(), other.peti.dapatkanKolom())) {}

Walikota::~Walikota() {}

void Walikota::tambahPemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int, int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan) {
    if (uang >= 50) {
        string namaPemain;
        string jenisPemain;

        cout << "Masukan nama pemain: ";
        cin >> namaPemain;
        cout << "Masukan jenis pemain: ";
        cin >> jenisPemain;

        bool isFound = false;
        int i = 0;
        while (isFound && i < daftarPemain->size()) {
            if ((*daftarPemain)[i]->dapatkan_nama() == namaPemain) {
                isFound = true;
            }
            i++;
        }
        if (!isFound) {
            if (Util::strComp(jenisPemain, "peternak")) {
                shared_ptr<Pemain> pemainBaru = make_unique<Peternak>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_peternakan);
                daftarPemain->push_back(pemainBaru);
                this->uang -= 50;
                cout << "Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
            }
            else if (Util::strComp(jenisPemain, "petani")) {
                shared_ptr<Pemain> pemainBaru = make_unique<Petani>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_lahan);
                daftarPemain->push_back(pemainBaru);
                this->uang -= 50;
                cout << "Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
            }
            else if (Util::strComp(jenisPemain, "walikota")) {
                cout << "Walikota nya satu aja yah, biar ga berantem" << endl;
            }
            else {
                cout << "Role ini tidak tersedia" << endl;
            }
        }
        else {
            cout << "Ups, namanya sudah digunakan nih..." << endl;
        }
    }
    else {
        cout << "Uang tidak cukup!" << endl;
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
        }
        else if (Util::instanceof<Peternak>(daftar_pemain[i].get())) {
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

void Walikota::cetak_resep_semua_bangunan(vector<Bangunan> daftar_bangunan) {
    // Cetak semua resep bangunan yang ada
    cout << "Resep bangunan yang ada adalah sebagai berikut.\n";
    for (int i = 0; i < daftar_bangunan.size(); i++) {
        // Cetak nama dan harga bangunan
        string nama_bangunan = daftar_bangunan.at(i).dapatkan_nama();
        int harga_bangunan = daftar_bangunan.at(i).dapatkan_harga();
        cout << "   " << i + 1 << ". " << nama_bangunan << " (" << harga_bangunan << " gulden, ";

        // Iterasi setiap bahan pada suatu bangunan
        map<string, int> map_resep = daftar_bangunan.at(i).dapatkan_resep();
        bool isFirst = true;
        for (const auto& iterator : map_resep) {
            if (!isFirst) {
                cout << ", ";
            }
            cout << iterator.first << " " << iterator.second;
            isFirst = false;
        }

        cout << ")\n";
    }
}

bool Walikota::cek_bahan(Bangunan bangunan) {
    // Inisialisasi map untuk menghitung jumlah tiap ProdukTanamanMaterial yang dimiliki
    map<string, int> penghitung;    // string -> nama ProdukTanamanMaterial, int -> jumlah yang dimiliki

    // // Inisialisasi map untuk menghitung kekurangan tiap ProdukTanamanMaterial
    // map<string, int> kekurangan_bahan;

    // Inisialisasi jumlah setiap ProdukTanamanMaterial yg dibutuhkan menjadi 0
    for (const pair<string, int>& iterator : bangunan.dapatkan_resep()) {
        penghitung[iterator.first] = 0;
        // kekurangan_bahan[iterator.first] = 0;
    }

    // Mendapatkan jumlah setiap ProdukTanamanMaterial yang dimiliki
    for (int i = 0; i < this->peti.dapatkanBaris(); i++) {
        for (int j = 0; j < this->peti.dapatkanKolom(); j++) {
            if (Util::instanceof<ProdukTanamanMaterial>(this->peti.dapatkanElemen(i, j))) {
                ++penghitung[this->peti.dapatkanElemen(i, j)->dapatkan_nama()];
            }
        }
    }

    // Mengecek tiap bahan apakah mencukupi atau tidak
    bool bahan_cukup = true;
    for (pair<string, int> iterator : penghitung) {
        iterator.second -= bangunan.dapatkan_resep()[iterator.first];
        if (iterator.second < 0) {
            bahan_cukup = false;
        }
    }

    // cek uang walikota cukup apa ga
    if (this->dapatkan_uang() < bangunan.dapatkan_harga()) {
        bahan_cukup = false;
    }

    // Kalo bahan ga cukup, cetak kekurangannya
    if (!bahan_cukup) {
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << (this->dapatkan_uang() < bangunan.dapatkan_harga()) ? abs(this->uang - bangunan.dapatkan_harga()) : 0;
        cout << " gulden, ";

        // Iterasi pada map penghitung
        bool isFirst = true;
        for (pair<string, int> iterator : penghitung) {
            if (!isFirst) {
                cout << ", ";
            }
            cout << (iterator.second < 0) ? abs(iterator.second) : 0;
            cout << " " << iterator.first;
        }
        cout << "!\n\n";

        return bahan_cukup; // Udah pas false
    }
    return bahan_cukup; // udah pasti true
}

void Walikota::bangun(vector<Bangunan> daftar_bangunan) {               // Belom di test
    // Cek masih punya slot kosong atau ga. Kalo ga ada, ya ga bisa bangun
    if (this->jumlah_slot_kosong_peti() == 0) throw "Tidak bisa membangun karena ga punya slot di penyimpanan\n";

    while (true) {
        this->cetak_resep_semua_bangunan(daftar_bangunan);
        cout << "\n";

        // User milih bangunan untuk dibangun
        string pilihan_bangunan;
        cout << "Bangunan yang ingin dibangun: ";
        cin >> pilihan_bangunan;

        // Cek apakah pilihan_bangunan ada dalam daftar_bangunan
        for (int i = 0; i < daftar_bangunan.size(); i++) {
            if (daftar_bangunan.at(i).dapatkan_nama() == pilihan_bangunan) {
                // Cek apakah material yg dimiliki mencukupi untuk membangun sekaligus mencetak kekurangan jika bahan tidak cukup
                if (this->cek_bahan(daftar_bangunan.at(i))) cout << pilihan_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota!\n";
                break;  // untuk break for loop
                continue;   // ke while loop selanjutnya
            }
        }
        cout << "Kamu tidak punya resep bangunan tersebut!\n\n";
    }

}
#include "Walikota.hpp"

// 4 Sekawan
Walikota::Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti) : Pemain(nama, uang, berat_badan, ukuran_peti) {}

Walikota::Walikota(const Walikota& other) : Pemain(other.nama, other.uang, other.berat_badan, tuple<int, int>(other.peti.dapatkanBaris(), other.peti.dapatkanKolom())) {}

Walikota::~Walikota() {}

// Method
bool Walikota::apakah_nama_terdaftar(vector<shared_ptr<Pemain>>* daftarPemain, string namaPemain) {
    bool isFound = false;
    int i = 0;
    while (!isFound && i < daftarPemain->size()) {
        if (Util::strComp((*daftarPemain)[i]->dapatkan_nama(), namaPemain)) {
            isFound = true;
            cout << "Ups, namanya sudah digunakan nih..." << endl;
            break;
        }
        i++;
    }
    return isFound;
}

bool Walikota::jenis_pemain_valid(string jenisPemain) {
    return Util::strComp(jenisPemain, "peternak") || Util::strComp(jenisPemain, "petani");
}

bool Walikota::bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b) {
    int pajak_a = 0;
    int pajak_b = 0;
    if (Util::instanceof<Petani>(a.get())) {
        shared_ptr<Petani> petani_a = dynamic_pointer_cast<Petani>(a);
        pajak_a = petani_a->hitung_pajak();
    }
    else if (Util::instanceof<Peternak>(a.get())) {
        shared_ptr<Peternak> peternak_a = dynamic_pointer_cast<Peternak>(a);
        pajak_a = peternak_a->hitung_pajak();
    }
    if (Util::instanceof<Petani>(b.get())) {
        shared_ptr<Petani> petani_b = dynamic_pointer_cast<Petani>(b);
        pajak_b = petani_b->hitung_pajak();
    }
    else if (Util::instanceof<Peternak>(b.get())) {
        shared_ptr<Peternak> peternak_b = dynamic_pointer_cast<Peternak>(b);
        pajak_b = peternak_b->hitung_pajak();
    }
    return pajak_a > pajak_b;
}

void Walikota::cetak_resep_semua_bangunan(vector<shared_ptr<Bangunan>> daftar_bangunan) {
    // Cetak semua resep bangunan yang ada
    cout << "Resep bangunan yang ada adalah sebagai berikut.\n";
    for (int i = 0; i < daftar_bangunan.size(); i++) {
        // Cetak nama dan harga bangunan
        string nama_bangunan = daftar_bangunan.at(i)->dapatkan_nama();
        cout << "   " << i + 1 << ". " << nama_bangunan << " (";

        // Iterasi setiap bahan pada suatu bangunan
        map<string, int> map_resep = daftar_bangunan.at(i)->dapatkan_resep();
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

bool Walikota::cek_bahan(shared_ptr<Bangunan> bangunan) {       // Nge cek bahan cukup atau ga. Kalo cukup, return true dan bahan nya walkot dikurangi
    // Inisialisasi map untuk menghitung jumlah tiap ProdukTanamanMaterial yang dimiliki
    map<string, int> penghitung;    // string -> nama ProdukTanamanMaterial, int -> jumlah yang dimiliki

    // Inisialisasi jumlah setiap ProdukTanamanMaterial yg dibutuhkan menjadi 0
    for (const pair<string, int>& iterator : bangunan->dapatkan_resep()) {
        // cout << "ini map penghitung\n";
        // cout << iterator.first << endl;
        penghitung[iterator.first] = 0;
        // kekurangan_bahan[iterator.first] = 0;
    }

    // // Inisialisasi array of string slot material
    // vector<string> arr_slot;

    // Mendapatkan jumlah setiap ProdukTanamanMaterial yang dimiliki
    for (int i = 0; i < this->peti.dapatkanBaris(); i++) {
        for (int j = 0; j < this->peti.dapatkanKolom(); j++) {
            if (shared_ptr<ProdukTanamanMaterial> material = dynamic_pointer_cast<ProdukTanamanMaterial>(this->peti.dapatkan_elemen(i, j))) {
                penghitung[material->dapatkan_nama()] += 1;

                // // Membuat array of string slot material untuk dihapus dari peti jika semua bahan cukup
                // arr_slot.push_back(Util::label_slot_tabel(i, j));
            }
        }
    }

    // // Mencetak semua map penghitung
    // cout << "Bahan yang kamu miliki adalah sebagai berikut.\n";
    // for (const pair<string, int>& iterator : penghitung) {
    //     cout << "   " << iterator.first << ": " << iterator.second << "\n";
    // }

    // Mengecek tiap bahan apakah mencukupi atau tidak
    bool bahan_cukup = true;
    for (pair<string, int> iterator : penghitung) {
        penghitung[iterator.first] -= bangunan->dapatkan_resep()[iterator.first];
        if (penghitung[iterator.first] < 0) {
            bahan_cukup = false;
        }
    }

    // // cek uang walikota cukup apa ga
    // if (this->dapatkan_uang() < bangunan->dapatkan_harga()) {
    //     bahan_cukup = false;
    // }

    // Kalo bahan ga cukup, cetak kekurangannya
    if (!bahan_cukup) {
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

        // Iterasi pada map penghitung
        bool isFirst = true;
        for (pair<string, int> iterator : penghitung) {
            if (!isFirst) {
                cout << ", ";
            }
            isFirst = false;
            cout << (iterator.second < 0) ? abs(iterator.second) : 0;
            cout << " " << iterator.first;
        }
        cout << "!\n";

        return bahan_cukup; // Udah pas false
    }

    // Menghapus slot material dari peti
    map<string, int> copy_resep = bangunan->dapatkan_resep();
    // Mengiterasi semua elemen peti
    for (int i = 0; i < this->peti.dapatkanBaris(); i++) {
        for (int j = 0; j < this->peti.dapatkanKolom(); j++) {
            if (shared_ptr<ProdukTanamanMaterial> material = dynamic_pointer_cast<ProdukTanamanMaterial>(this->peti.dapatkan_elemen(i, j))) {
                // Mengecek apakah material.dapatkan_nama() ada pada copy_resep
                if (copy_resep.find(material->dapatkan_nama()) != copy_resep.end()) {
                    // Mengurangi jumlah bahan yang dimiliki
                    if (copy_resep[material->dapatkan_nama()] > 0) {
                        copy_resep[material->dapatkan_nama()] -= 1;
                        // Menghapus elemen dari peti
                        this->peti.hapus(i, j);
                    }
                }
            }
        }
    }

    // Menambahkan Bangunan ke peti walkot
    // peti+=make_shared<Entitas>(bangunan);
    shared_ptr<Entitas> copied_bangunan = make_unique<Bangunan>(*dynamic_pointer_cast<Bangunan>(bangunan));
    peti.tambah_elemen_matriks(copied_bangunan);
    // this->tambah_peti(&bangunan);

    return bahan_cukup; // udah pasti true
}

// Command
void Walikota::tagih_pajak(vector<shared_ptr<Pemain>>& daftar_pemain, vector<shared_ptr<Pemain>> temp_daftar_pemain) {
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;

    int pajak_pemain = 0;
    int jumlah_pajak = 0;
    int j = 1;

    sort(temp_daftar_pemain.begin(), temp_daftar_pemain.end(), bandingkan_pajak);

    for (int i = 0; i < temp_daftar_pemain.size(); i++) {
        auto it = find(daftar_pemain.begin(), daftar_pemain.end(), temp_daftar_pemain[i]);
        if (Util::instanceof<Petani>(temp_daftar_pemain[i].get())) {
            shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(*it);
            pajak_pemain = petani->hitung_pajak();
            petani->atur_uang(petani->dapatkan_uang() - pajak_pemain);
            cout << j << ". " << petani->dapatkan_nama() << " - Petani: " << pajak_pemain << " gulden" << endl;
        }
        else if (Util::instanceof<Peternak>(temp_daftar_pemain[i].get())) {
            shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(*it);
            pajak_pemain = peternak->hitung_pajak();
            peternak->atur_uang(peternak->dapatkan_uang() - pajak_pemain);
            cout << j << ". " << peternak->dapatkan_nama() << " - Peternak: " << pajak_pemain << " gulden" << endl;
        }
        else if (Util::instanceof<Walikota>(temp_daftar_pemain[i].get())) {
            continue;
        }

        jumlah_pajak += pajak_pemain;
        j++;
    }
    this->uang += jumlah_pajak;

    cout << endl;
    cout << "Negara mendapatkan pemasukan sebesar " << jumlah_pajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::bangun(vector<shared_ptr<Bangunan>> daftar_bangunan) {               // Belom di test
    // Ga usah di cek masih ada slot kosong atau ga
    // Karena nanti pasti ada slot material yang berkurang (based on spek docs)

    bool berhasil_bangun = false;
    while (!berhasil_bangun) {
        this->cetak_resep_semua_bangunan(daftar_bangunan);
        cout << "\n";

        // User milih bangunan untuk dibangun
        string pilihan_bangunan;
        cout << "Bangunan yang ingin dibangun: ";
        cin >> pilihan_bangunan;

        // Cek apakah user memasukkan "BATAL", jika iya maka command BANGUN tidak jadi dijalankan
        if (Util::strComp(pilihan_bangunan, "BATAL")) {
            cout << "Kamu membatalkan pembangunan. Labil bgt sih.\n\n";
            return;
        }

        // Cek apakah pilihan_bangunan ada dalam daftar_bangunan
        bool apa_ada = false;
        for (int i = 0; i < daftar_bangunan.size(); i++) {
            // Asumsikan ga ada nama bangunan yang sama
            if (daftar_bangunan.at(i)->dapatkan_nama() == pilihan_bangunan) {
                apa_ada = true;

                // Cek apakah material yg dimiliki mencukupi untuk membangun sekaligus mencetak kekurangan jika bahan tidak cukup
                if (this->cek_bahan(daftar_bangunan.at(i))) {
                    // method cek_bahan akan melakukan hapus peti sekaligus tambah peti
                    cout << pilihan_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota!\n";
                    berhasil_bangun = true;
                }
                break;  // untuk break for loop
            }
        }

        if (berhasil_bangun) {
            break;
        }
        if (!apa_ada) {
            cout << "Bangunan tersebut tidak ada dalam daftar resep bangunan!\n";
        }
        cout << "\n";
    }
}

void Walikota::tambah_pemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int, int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan) {
    if (uang >= 50) {
        string namaPemain;
        string jenisPemain;


        bool namaValid = false;
        while (!namaValid) {
            cout << "Masukan nama pemain: ";
            cin >> namaPemain;

            if (Util::strComp(namaPemain, "BATAL")) {
                break;
            }
            bool jenisValid = false;
            while (!apakah_nama_terdaftar(daftarPemain, namaPemain) && !jenisValid) {
                cout << "Masukan jenis pemain: ";
                cin >> jenisPemain;

                if (Util::strComp(jenisPemain, "BATAL")) {
                    break;
                }
                if (jenis_pemain_valid(jenisPemain)) {
                    jenisValid = true; namaValid = true;
                    if (Util::strComp(jenisPemain, "peternak")) {
                        shared_ptr<Pemain> pemainBaru = make_unique<Peternak>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_peternakan);
                        daftarPemain->push_back(pemainBaru);
                        this->uang -= 50;
                        cout << "Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
                        break;
                    }
                    else { //petani
                        shared_ptr<Pemain> pemainBaru = make_unique<Petani>(namaPemain, 50, beratAwal, ukuranPenyimpanan, besar_lahan);
                        daftarPemain->push_back(pemainBaru);
                        this->uang -= 50;
                        cout << "Berhasil ditambahkan seorang " << jenisPemain << " bernama " << namaPemain << endl;
                        break;
                    }
                }
                else {
                    if (Util::strComp(jenisPemain, "walikota")) {
                        cout << "Walikota nya satu aja yah, biar ga berantem" << endl;
                    }
                    else {
                        cout << "Role ini tidak tersedia" << endl;
                    }
                }
            }
        }
    }
    else {
        cout << "Uang tidak cukup!" << endl;
    }
}

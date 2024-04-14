#include "Peternak.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

int main() {
    // load konfig 
    vector<shared_ptr<Produk>> daftarProduk;
    daftarProduk = InputKonfigurasi::InputKonfigurasiProduk("Pemain/confprod.txt");

    // Membuat objek peternak
    Peternak peternak("NamaPeternak", 1000, 70, {5, 5}, {10, 10});

    // Membuat beberapa hewan
    Herbivora herbivora("1", "COW", "COW" , 20, 6);
    Karnivora karnivora("2", "SNK", "SNAKE", 13, 4);
    Omnivora omnivora("3", "CHK", "CHICKEN", 12, 3);
    herbivora.atur_berat(100);

    // Menambahkan hewan ke peternakan
    peternak.tambah_peternakan("A1", make_shared<Herbivora>(herbivora));
    peternak.tambah_peternakan("B2", make_shared<Karnivora>(karnivora));
    peternak.tambah_peternakan("C3", make_shared<Omnivora>(omnivora));

    // Init Matriks
    cout << "Matriks Awal" << endl;
    gembala.cetak_peti();
    gembala.cetak_peternakan();

    // Memeriksa apakah ladang kosong
    if (gembala.cek_peternakan_kosong()) {
        cout << "Ladang kosong." << endl;
    } else {
        cout << "Ladang tidak kosong." << endl;
    }

    // Menambahkan tanaman ke ladang
    // gembala.tambah_ladang("A1", (tanaman1));
    // gembala.tambah_ladang("A2", (tanaman1));
    // gembala.tambah_ladang("A1", tanaman1);
    // gembala.tambah_ladang("A2", tanaman1);
    // gembala.tambah_ladang("B2", tanaman2);
    // gembala.tambah_ladang("C3", tanaman3);

    // Menambahkan tanaman ke peti
    cout << "Penambahan Tanaman ke Peti" << endl;
    gembala.tambah_peti(hewan1);
    gembala.tambah_peti(hewan2);
    gembala.tambah_peti(hewan3);


    gembala.cetak_peti();

    gembala.cetak_peternakan();
    // Memeriksa apakah ladang penuh
    if (gembala.cek_peternakan_penuh()) {
        cout << "Ladang penuh." << endl;
    } else {
        cout << "Ladang belum penuh." << endl;
    }

    // Memeriksa apakah ladang kosong
    if (gembala.cek_peternakan_kosong()) {
        cout << "Ladang kosong." << endl;
    } else {
        cout << "Ladang tidak kosong." << endl;
    }

    // Menampilkan jumlah slot kosong di ladang
    cout << "Jumlah slot kosong di ladang: " << gembala.jumlah_slot_kosong_peternakan() << endl;

    // Melakukan penghapusan 


    // Memulai proses penanaman
    gembala.ternak();
    gembala.ternak();
    gembala.cetak_peti();
    gembala.cetak_peternakan();

    // gembala.dapatkan_peternakan().dapatkan_elemen(0, 0).get()->atur_umur(300);
    hewan1.get()->atur_berat(8);

    cout << "Perubahan berat Hewan1 = 8/10" << endl;
    gembala.cetak_peternakan();

    cout << "Belum Ada Yg Bisa Dipanen" << endl;
    // Melakukan panen
    gembala.panen();

    cout << gembala.dapatkan_peternakan().dapatkan_elemen(2, 2).get()->dapatkan_berat() << endl;
    cout << "+1x2 Umur" << endl;

    cout << gembala.dapatkan_peternakan().dapatkan_elemen(2, 2).get()->dapatkan_berat() << endl;
    cout << gembala.dapatkan_peternakan().dapatkan_elemen(2, 2).get()->dapatkan_berat() << endl;
    // Melakukan panen
    peternak.panen(daftarProduk);

    // Mencetak ladang setelah operasi
    cout << "Peternakan setelah operasi:" << endl;
    gembala.cetak_peternakan();
    gembala.cetak_peti();

    return 0;
}

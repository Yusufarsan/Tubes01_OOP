#include "Petani.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

int main() {
    // load konfig
    vector<shared_ptr<Produk>> daftarProduk;
    daftarProduk = InputKonfigurasi::InputKonfigurasiProduk("Pemain/confprod.txt");


    // Membuat objek petani
    Petani paktani("NamaPetani", 1000, 70, { 5, 5 }, { 5, 5 });

    // Membuat beberapa tanaman
    TanamanMaterial tanaman1("1", "TEK", "TEAK_TREE", 15, 5);
    TanamanBuah tanaman2("2", "APL", "APPLE_TREE", 13, 4);
    TanamanBuah tanaman3("3", "WOR", "WORTEL_TREE", 75, 15);
    tanaman1.atur_umur(3000);

    // Menambahkan tanaman ke ladang
    petani.tambah_ladang("A1", make_shared<TanamanMaterial>(tanaman1));
    petani.tambah_ladang("B2", make_shared<TanamanBuah>(tanaman2));
    petani.tambah_ladang("C3", make_shared<TanamanBuah>(tanaman3));

    // Menambahkan tanaman ke peti
    cout << "Penambahan Tanaman ke Peti" << endl;
    paktani.tambah_peti(tanaman1);
    paktani.tambah_peti(tanaman2);
    paktani.tambah_peti(tanaman3);


    paktani.cetak_peti();

    paktani.cetak_ladang();
    // Memeriksa apakah ladang penuh
    if (paktani.cek_ladang_penuh()) {
        cout << "Ladang penuh." << endl;
    }
    else {
        cout << "Ladang belum penuh." << endl;
    }

    // Memeriksa apakah ladang kosong
    if (paktani.cek_ladang_kosong()) {
        cout << "Ladang kosong." << endl;
    }
    else {
        cout << "Ladang tidak kosong." << endl;
    }

    // Menampilkan jumlah slot kosong di ladang
    cout << "Jumlah slot kosong di ladang: " << paktani.jumlah_slot_kosong_ladang() << endl;

    // Melakukan penghapusan 


    // Memulai proses penanaman
    paktani.tanam();
    paktani.tanam();
    paktani.cetak_peti();
    paktani.cetak_ladang();

    // paktani.dapatkan_ladang().dapatkan_elemen(0, 0).get()->atur_umur(300);
    tanaman1.get()->atur_umur(8);

    cout << "Perubahan umur Tanaman1 = 8/10" << endl;
    paktani.cetak_ladang();

    cout << "Belum Ada Yg Bisa Dipanen" << endl;
    // Melakukan panen
    paktani.panen();

    cout << paktani.dapatkan_ladang().dapatkan_elemen(2, 2).get()->dapatkan_umur() << endl;
    cout << "+1x2 Umur" << endl;
    paktani.next_umur();

    cout << paktani.dapatkan_ladang().dapatkan_elemen(2, 2).get()->dapatkan_umur() << endl;
    paktani.next_umur();
    cout << paktani.dapatkan_ladang().dapatkan_elemen(2, 2).get()->dapatkan_umur() << endl;
    // Melakukan panen
    petani.panen(daftarProduk);

    // Mencetak ladang setelah operasi
    cout << "Ladang setelah operasi:" << endl;
    paktani.cetak_ladang();
    paktani.cetak_peti();

    return 0;
}

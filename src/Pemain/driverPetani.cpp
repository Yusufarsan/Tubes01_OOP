#include "Petani.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

int main() {
    // load konfig
    vector<shared_ptr<Produk>> daftarProduk;
    daftarProduk = InputKonfigurasi::InputKonfigurasiProduk("Pemain/confprod.txt");


    // Membuat objek petani
    Petani petani("NamaPetani", 1000, 70, {5, 5}, {5, 5});

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
    petani.tambah_peti(make_shared<Tanaman>(tanaman1));

    // Mencetak ladang
    std::cout << "Ladang setelah penambahan tanaman:" << std::endl;
    petani.cetak_ladang();
    std::cout << std::endl;

    // Memeriksa apakah ladang penuh
    if (petani.cek_ladang_penuh()) {
        std::cout << "Ladang penuh." << std::endl;
    } else {
        std::cout << "Ladang belum penuh." << std::endl;
    }

    // Memeriksa apakah ladang kosong
    if (petani.cek_ladang_kosong()) {
        std::cout << "Ladang kosong." << std::endl;
    } else {
        std::cout << "Ladang tidak kosong." << std::endl;
    }

    // Menampilkan jumlah slot kosong di ladang
    std::cout << "Jumlah slot kosong di ladang: " << petani.jumlah_slot_kosong_ladang() << std::endl;

    // Melakukan penghapusan 


    // Memulai proses penanaman
    // petani.tanam();
    petani.cetak_peti();

    // Melakukan panen
    petani.panen(daftarProduk);

    // Mencetak ladang setelah operasi
    std::cout << "Ladang setelah operasi:" << std::endl;
    petani.cetak_ladang();
    petani.cetak_peti();

    return 0;
}

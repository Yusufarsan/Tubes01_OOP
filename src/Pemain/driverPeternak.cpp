#include "Peternak.hpp"
#include "../InputKonfigurasi/InputKonfigurasi.hpp"

int main() {
    // load konfig 
    vector<shared_ptr<Produk>> daftarProduk;
    daftarProduk = InputKonfigurasi::InputKonfigurasiProduk("Pemain/confprod.txt");

    // Membuat objek peternak
    Peternak peternak("NamaPeternak", 1000, 70, { 5, 5 }, { 10, 10 });

    // Membuat beberapa hewan
    Herbivora herbivora("1", "COW", "COW", 20, 6);
    Karnivora karnivora("2", "SNK", "SNAKE", 13, 4);
    Omnivora omnivora("3", "CHK", "CHICKEN", 50, 3);
    herbivora.atur_berat(100);
    omnivora.atur_berat(100);

    // Menambahkan hewan ke peternakan
    peternak.tambah_peternakan("A1", make_shared<Herbivora>(herbivora));
    peternak.tambah_peternakan("B2", make_shared<Karnivora>(karnivora));
    peternak.tambah_peternakan("C3", make_shared<Omnivora>(omnivora));

    // Mencetak peternakan
    std::cout << "Peternakan setelah penambahan hewan:" << std::endl;
    peternak.cetak_peternakan();
    std::cout << std::endl;

    // Memeriksa apakah peternakan penuh
    if (peternak.cek_peternakan_penuh()) {
        std::cout << "Peternakan penuh." << std::endl;
    }
    else {
        std::cout << "Peternakan belum penuh." << std::endl;
    }

    // Memeriksa apakah peternakan kosong
    if (peternak.cek_peternakan_kosong()) {
        std::cout << "Peternakan kosong." << std::endl;
    }
    else {
        std::cout << "Peternakan tidak kosong." << std::endl;
    }

    // Menampilkan jumlah slot kosong di peternakan
    std::cout << "Jumlah slot kosong di peternakan: " << peternak.jumlah_slot_kosong_peternakan() << std::endl;

    // Memulai proses ternak
    peternak.ternak();

    // Memberi makan hewan di peternakan
    peternak.beri_pangan();


    peternak.cetak_peti();
    // Melakukan panen
    peternak.panen(daftarProduk);

    // Mencetak peternakan setelah operasi
    std::cout << "Peternakan setelah operasi:" << std::endl;
    peternak.cetak_peternakan();
    peternak.cetak_peti();

    return 0;
}

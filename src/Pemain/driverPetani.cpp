#include "Petani.hpp"

int main() {
    // Membuat objek petani
    Petani petani("NamaPetani", 1000, 70, {5, 5}, {5, 5});

    // Membuat beberapa tanaman
    Tanaman tanaman1("T1", "PAD", "Padi", 50, 10);
    Tanaman tanaman2("T2", "JAG", "Jagung", 100, 20);
    Tanaman tanaman3("T3", "WOR", "Wortel", 75, 15);

    // Menambahkan tanaman ke ladang
    petani.tambah_ladang("A1", tanaman1);
    petani.tambah_ladang("B2", tanaman2);
    petani.tambah_ladang("C3", tanaman3);

    // Menambahkan tanaman ke peti
    petani.tambah_peti(&tanaman1);

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
    petani.tanam();
    petani.cetak_peti();

    // Melakukan panen
    tanaman1.atur_umur(30);
    petani.panen();

    // Mencetak ladang setelah operasi
    std::cout << "Ladang setelah operasi:" << std::endl;
    petani.cetak_ladang();
    petani.cetak_peti();

    return 0;
}

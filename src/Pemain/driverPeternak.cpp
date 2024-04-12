#include "Peternak.hpp"

int main() {
    // Membuat objek peternak
    Peternak peternak("NamaPeternak", 1000, 70, {5, 5}, {10, 10});

    // Membuat beberapa hewan
    Herbivora herbivora("ID1", "HER", "Herbivora", 50, 10);
    Karnivora karnivora("ID2", "KAR", "Karnivora", 100, 20);
    Omnivora omnivora("ID3", "OMN", "Omnivora", 75, 15);

    // Menambahkan hewan ke peternakan
    peternak.tambah_peternakan("A1", &herbivora);
    peternak.tambah_peternakan("B2", &karnivora);
    peternak.tambah_peternakan("C3", &omnivora);

    // Mencetak peternakan
    std::cout << "Peternakan setelah penambahan hewan:" << std::endl;
    peternak.cetak_peternakan();
    std::cout << std::endl;

    // Memeriksa apakah peternakan penuh
    if (peternak.cek_peternakan_penuh()) {
        std::cout << "Peternakan penuh." << std::endl;
    } else {
        std::cout << "Peternakan belum penuh." << std::endl;
    }

    // Memeriksa apakah peternakan kosong
    if (peternak.cek_peternakan_kosong()) {
        std::cout << "Peternakan kosong." << std::endl;
    } else {
        std::cout << "Peternakan tidak kosong." << std::endl;
    }

    // Menampilkan jumlah slot kosong di peternakan
    std::cout << "Jumlah slot kosong di peternakan: " << peternak.jumlah_slot_kosong_peternakan() << std::endl;

    // Memulai proses ternak
    peternak.ternak();

    // Memberi makan hewan di peternakan
    peternak.beri_pangan();

    omnivora.atur_berat(100);

    // Melakukan panen
    peternak.panen();

    // Mencetak peternakan setelah operasi
    std::cout << "Peternakan setelah operasi:" << std::endl;
    peternak.cetak_peternakan();
    peternak.cetak_peti();

    return 0;
}

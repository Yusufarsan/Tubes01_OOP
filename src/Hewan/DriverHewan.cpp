#include <iostream>
#include "Herbivora.hpp"
#include "Karnivora.hpp"
#include "Omnivora.hpp"
#include "../Produk/Produk.hpp" // Anda perlu memastikan struktur folder Anda sesuai
#include "../Produk/ProdukTanamanBuah.hpp" // Anda perlu memastikan struktur folder Anda sesuai
#include "../Produk/ProdukHewan.hpp" // Anda perlu memastikan struktur folder Anda sesuai

int main() {
    // Membuat objek herbivora
    Herbivora herbivore("001", "H", "Gajah", 100, 500);
    
    // Membuat objek karnivora
    Karnivora carnivore("002", "L", "Singa", 200, 300);
    
    // Membuat objek omnivora
    Omnivora omnivore("003", "T", "Beruang", 150, 400);
    
    // Mencetak informasi masing-masing hewan
    herbivore.print_info();
    carnivore.print_info();
    omnivore.print_info();
    
    // Memberi makanan kepada masing-masing hewan
    ProdukTanamanBuah produk1("1", "R", "rumput", 50, 10, "TanamanBuah");
    ProdukHewan produk2("2", "d", "daging", 80, 20, "sapi");
    
    herbivore.makan(&produk1);
    carnivore.makan(&produk2);
    omnivore.makan(&produk1);
    omnivore.makan(&produk2);
    
    // Mencetak informasi setelah memberi makan
    herbivore.print_info();
    carnivore.print_info();
    omnivore.print_info();
    
    return 0;
}

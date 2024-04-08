#include <iostream>
#include "Herbivora.hpp"
#include "Karnivora.hpp"
#include "Omnivora.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include "../Produk/ProdukTanamanMaterial.hpp"
#include "../Produk/ProdukHewan.hpp"

int main() {
    // Membuat objek herbivora
    Herbivora herbivore("001", "H", "Gajah", 100, 500);
    
    // Membuat objek karnivora
    Karnivora carnivore("002", "L", "Singa", 200, 300);
    
    // Membuat objek omnivora
    Omnivora omnivore("003", "T", "Beruang", 150, 400);
    
    // Mencetak informasi masing-masing hewan
    cout << "Hewan Herbivora" << endl;
    herbivore.print_info(); 
    cout << endl;
    cout << "Hewan Karnivora" << endl;
    carnivore.print_info();
    cout << endl;
    cout << "Hewan Omnivora" << endl;
    omnivore.print_info();
    cout << endl;
    
    // Memberi makanan kepada masing-masing hewan
    ProdukTanamanBuah produk1("1", "R", "rumput", 50, 10, "Tanaman Rumput");
    ProdukHewan produk2("2", "D", "daging", 80, 20, "sapi");
    ProdukTanamanMaterial produk3("3", "J", "jati", 80, 20, "Pohon Jati");
    
    cout << herbivore.dapatkan_nama() << " memakan " << produk1.dapatkan_nama() <<endl;
    herbivore.makan(&produk1);
    cout << herbivore.dapatkan_nama() << " memakan " << produk2.dapatkan_nama() <<endl;
    herbivore.makan(&produk2);
    cout << herbivore.dapatkan_nama() << " memakan " << produk3.dapatkan_nama() <<endl;
    herbivore.makan(&produk3);
    cout << endl;


    cout << carnivore.dapatkan_nama() << " memakan " << produk1.dapatkan_nama() <<endl;
    carnivore.makan(&produk1);
    cout << carnivore.dapatkan_nama() << " memakan " << produk2.dapatkan_nama() <<endl;
    carnivore.makan(&produk2);
    cout << carnivore.dapatkan_nama() << " memakan " << produk3.dapatkan_nama() <<endl;
    carnivore.makan(&produk3);
    cout << endl;


    cout << omnivore.dapatkan_nama() << " memakan " << produk1.dapatkan_nama() <<endl;
    omnivore.makan(&produk1);
    cout << omnivore.dapatkan_nama() << " memakan " << produk2.dapatkan_nama() <<endl;
    omnivore.makan(&produk2);
    cout << omnivore.dapatkan_nama() << " memakan " << produk3.dapatkan_nama() <<endl;
    omnivore.makan(&produk3);
    cout << endl;
    

    // Mencetak informasi setelah memberi makan
    cout << "Hewan Herbivora" << endl;
    herbivore.print_info(); 
    cout << endl;
    cout << "Hewan Karnivora" << endl;
    carnivore.print_info();
    cout << endl;
    cout << "Hewan Omnivora" << endl;
    omnivore.print_info();
    cout << endl;

    
    return 0;
}

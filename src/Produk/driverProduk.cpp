// File testing untuk Produk.cpp ProdukHewan.cpp ProdukTanamanBuah.cpp dan ProdukTanamanMaterial.cpp

#include "Produk.hpp"
#include "ProdukHewan.hpp"
#include "ProdukTanamanBuah.hpp"
#include "ProdukTanamanMaterial.hpp"

int main() {
    // Produk
    cout << "Produk" << endl;
    ProdukHewan produk1("1", "APP", "Apple", 100, 5, "Malang");
    Produk* produkPtr = &produk1;
    ProdukHewan* produkHewanPtr = dynamic_cast<ProdukHewan*>(produkPtr);
    if (produkHewanPtr != nullptr) {
        std::cout << "The Produk object can be downcast to ProdukHewan" << std::endl;
    }
    else {
        std::cout << "The Produk object cannot be downcast to ProdukHewan" << std::endl;
    }
    produkHewanPtr->print_info();
    cout << endl;

    // ProdukHewan
    cout << "ProdukHewan" << endl;
    ProdukHewan produkHewan1("2", "CHK", "Ayam", 200, 10, "Malang");
    produkHewan1.print_info();
    cout << endl;

    // ProdukTanamanBuah
    cout << "ProdukTanamanBuah" << endl;
    ProdukTanamanBuah produkTanamanBuah1("3", "APP", "Apple", 100, 5, "Malang");
    produkTanamanBuah1.print_info();
    cout << endl;

    // ProdukTanamanMaterial
    cout << "ProdukTanamanMaterial" << endl;
    ProdukTanamanMaterial produkTanamanMaterial1("4", "WTR", "Water", 50, 2, "Malang");
    produkTanamanMaterial1.print_info();
    cout << endl;

    return 0;
}
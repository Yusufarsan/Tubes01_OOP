#include <iostream>
#include <vector>
#include "../Entitas/Entitas.hpp"
#include "Matriks.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"

using namespace std;

int main() {
    Matrix<Hewan> peti(3, 3); // Creating a 3x3 matrix

    shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
    shared_ptr<Hewan> ayam = make_shared<Omnivora>("2", "CHK", "ayam", 200, 10);
    shared_ptr<Hewan> sapi = make_shared<Herbivora>("3", "COW", "sapi", 200, 10);
    shared_ptr<Hewan> ular = make_shared<Karnivora>("4", "SNK", "ular", 200, 10);
    shared_ptr<Hewan> beruang = make_shared<Omnivora>("5", "BER", "beruang", 200, 10);
    // Edit an element in the matrix
    
    // Set values in the matrix
    peti.tambah_elemen_matriks(0, 0, ayam);
    peti.tambah_elemen_matriks(0, 1, sapi);
    peti.tambah_elemen_matriks(1, 0, ular);
    peti.tambah_elemen_matriks(2, 1, beruang);

    // Print the matrix
    cout << "Matrix:" << endl;
    peti.cetak();

    // // Get value at position (1, 1)
    // cout << "Value at (1, 1): "<<endl;
    // peti.dapatkan_elemen(1, 1)->print_info();
    // cout << endl;

    // // delete element
    // peti.hapus(0,0);
    
    // // Print the matrix
    // cout << "Matrix:" << endl;

    // // peti+=(sapi);
    // peti.cetak();

    // // Trying to set value at invalid position
    peti.tambah_elemen_matriks(3, 3, kambing);
    peti.cetak();
    // peti.dapatkan_elemen(3, 3);

    return 0;
}

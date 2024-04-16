#include <iostream>
#include <vector>
#include "../Entitas/Entitas.hpp"
#include "Matriks.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include <exception>
#include "../Exception/ExceptionMatrix.hpp"

using namespace std;

int main() {
    Matrix<Hewan> zoo(2, 2); // Creating a 3x3 matrix

    shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
    shared_ptr<Hewan> ayam = make_shared<Omnivora>("2", "CHK", "ayam", 200, 10);
    shared_ptr<Hewan> sapi = make_shared<Herbivora>("3", "COW", "sapi", 200, 10);
    shared_ptr<Hewan> ular = make_shared<Karnivora>("4", "SNK", "ular", 200, 10);
    shared_ptr<Hewan> beruang = make_shared<Omnivora>("5", "BER", "beruang", 200, 10);


    try {
        // Print the matrix
        cout << "Init Matrix:" << endl;
        zoo.cetak();
        cout << "Ukuran matrix: " << zoo.dapatkanBaris() << " x " << zoo.dapatkanKolom();
        cout << endl;

        // Set values in the matrix
        zoo.tambah_elemen_matriks(0, 0, ayam);
        zoo.tambah_elemen_matriks(1, 1, sapi);

        // Print the matrix
        cout << "Matrix:" << endl;
        zoo.cetak();
        cout << endl;


        // Get value at position (1, 1)
        cout << "Value at (1, 1): " << endl;
        zoo.dapatkan_elemen(1, 1).get()->print_info();
        cout << endl;

        // Delete element
        zoo.hapus(1, 1);

        // Print the matrix
        cout << "After Delete Matrix:" << endl;
        zoo.cetak();
        cout << endl;


        zoo += sapi;
        cout << "After Assigment += Matrix:" << endl;
        zoo.cetak();
        cout << endl;

        zoo.tambah_elemen_matriks(ular);
        cout << "After auto insert Matrix:" << endl;
        zoo.cetak();
        cout << endl;


        // Trying to set value at invalid position
        cout << "Not Valid Index Matrix:" << endl;
        zoo.tambah_elemen_matriks(3, 3, kambing);
        zoo.cetak();
        cout << endl;

        // Trying to delete value at invalid position
        cout << "Not Valid Index Matrix:" << endl;
        zoo.hapus(3, 3);
        zoo.cetak();
        cout << endl;

        // Trying to get value at invalid position
        cout << "Not Valid Index Matrix: ";
        cout << zoo.dapatkan_elemen(3, 3) << endl;

        // Check valid slot
        cout << "Check Valid Slot C03 Matrix: ";
        cout << zoo.apakah_slot_valid("C03") << endl;
        cout << "Check Valid Slot B02 Matrix: ";
        cout << zoo.apakah_slot_valid("B02") << endl;

        // Check empty slot
        cout << "Check Empty Slot A01 Matrix: ";
        cout << zoo.apakah_slot_kosong("A01") << endl;
        cout << "Check Empty Slot B02 Matrix: ";
        cout << zoo.apakah_slot_kosong("B02") << endl;

        // Check valid index
        cout << "Check Valid Index 0, 0 Matrix: ";
        cout << zoo.apakah_index_valid(0, 0) << endl;
        cout << "Check Valid Index 1, 1 Matrix: ";
        cout << zoo.apakah_index_valid(1, 1) << endl;
        cout << "Check Valid Index 2, 2 Matrix: ";
        cout << zoo.apakah_index_valid(2, 2) << endl;
        cout << "Check Valid Index -1, -1 Matrix: ";
        cout << zoo.apakah_index_valid(-1, -1) << endl;

        zoo.cetak();
        cout << "Jumlah slot kosong: ";
        cout << zoo.jumlah_slot_kosong() << endl;

        cout << "Jumlah slot terisi: ";
        cout << zoo.jumlahElement() << endl;

        cout << "Apakah penuh: ";
        cout << zoo.apakah_penuh() << endl;

        zoo += kambing;

        zoo.cetak();
        cout << "Apakah penuh: ";
        cout << zoo.apakah_penuh() << endl;

        cout << "Apakah kosong: ";
        cout << zoo.apakah_kosong() << endl;

    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

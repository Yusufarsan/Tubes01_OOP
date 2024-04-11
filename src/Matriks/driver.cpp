#include <iostream>
#include <vector>
#include "Matriks.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"

using namespace std;

int main() {
    Matrix<Hewan> mat(2, 2); // Creating a 3x3 matrix

    Omnivora ayam("1", "S", "ayam", 200, 10);
    Herbivora* sapi = new Herbivora("1", "S", "sapi", 200, 10);
    Karnivora* ular = new Karnivora("1", "S", "ular", 200, 10);
    Omnivora* beruang = new Omnivora("1", "S", "beruang", 200, 10);
    
    // Set values in the matrix
    mat.editElemen(0, 0, &ayam);
    mat.editElemen(0, 1, sapi);
    mat.editElemen(1, 0, ular);
    mat.editElemen(1, 1, beruang);

    // Print the matrix
    cout << "Matrix:" << endl;
    mat.cetak();

    // Get value at position (1, 1)
    cout << "Value at (1, 1): "<<endl;
    mat.dapatkanElemen(1, 1)->print_info();
    cout << endl;

    // delete element
    mat.hapus(0,0);
    
    // Print the matrix
    cout << "Matrix:" << endl;
    mat.cetak();

    // Trying to set value at invalid position
    mat.dapatkanElemen(3, 3);

    return 0;
}

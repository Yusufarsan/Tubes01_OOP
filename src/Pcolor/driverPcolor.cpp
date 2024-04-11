/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include "Pcolor.hpp"

int main() {
    print_red("Haloo ini merah");
    cout << endl;
    print_green("Haloo ini hijau");
    cout << endl;
    print_blue("Haloo ini biru");
    cout << endl;
    cout << "Hello World" << endl;
    return 0;
}

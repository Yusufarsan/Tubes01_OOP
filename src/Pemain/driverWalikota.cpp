#include <iostream>
#include <vector>
#include <memory>
#include "Walikota.hpp"

int main(){
    tuple<int,int> a(5,5);
    Walikota w1("ucok", 100, 70, a);

    vector<shared_ptr<Pemain>> daftarPemain;
    w1.tambahPemain(&daftarPemain, a, 0, a, a);
}
#include <iostream>
#include <vector>
#include <memory>
#include "Walikota.hpp"

int main(){
    tuple<int,int> a(5,5);
    Walikota w1("ucok", 150, 70, a);

    vector<shared_ptr<Pemain>> daftarPemain;
    w1.tambahPemain(&daftarPemain, a, 0, a, a);
    cout<<daftarPemain.size()<<endl;
    w1.tambahPemain(&daftarPemain, a, 0, a, a);
    cout<<daftarPemain.size()<<endl;
    w1.tambahPemain(&daftarPemain, a, 0, a, a);
    cout<<daftarPemain.size()<<endl;
    cout<<daftarPemain.at(0)->dapatkan_nama()<<endl;
    cout<<daftarPemain.at(1)->dapatkan_nama()<<endl;
    cout<<daftarPemain.at(2)->dapatkan_nama()<<endl;
}
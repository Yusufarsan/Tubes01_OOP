#include <iostream>
#include <vector>
#include <memory>
#include "Walikota.hpp"

int main(){
    tuple<int,int> a(5,5);
    Walikota w1("ucok", 150, 70, a);
    Pemain p1("kocu", 150, 70, a);

    cout << w1.dapatkan_uang() << endl;
    cout << w1.dapatkan_nama() << endl;
    cout << w1.dapatkan_berat_badan() << endl;

    cout << p1.dapatkan_uang() << endl;
    cout << p1.dapatkan_nama() << endl;
    cout << p1.dapatkan_berat_badan() << endl;

    vector<shared_ptr<Pemain>> daftarpemain;
    w1.tambah_pemain(&daftarpemain, make_tuple(5,5), 70, make_tuple(5,5), make_tuple(5,5));
    w1.tagih_pajak(daftarpemain);

    cout << w1.dapatkan_uang() << endl;
    cout << w1.dapatkan_nama() << endl;
    cout << w1.dapatkan_berat_badan() << endl;

    cout << p1.dapatkan_uang() << endl;
    cout << p1.dapatkan_nama() << endl;
    cout << p1.dapatkan_berat_badan() << endl;
}
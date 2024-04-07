#include "Herbivora.hpp"
#include "../utils/utils.cpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include <iostream>

using namespace std;

Herbivora::Herbivora(string id, string kode_huruf, string nama, int harga, int berat_panen):Hewan(id, kode_huruf, nama, harga, berat_panen){}

Herbivora::Herbivora(Herbivora& other):Hewan(other){}

Herbivora::~Herbivora(){}

Herbivora& Herbivora::operator=(const Herbivora& other){
    Hewan::operator=(other);
    return *this;
}

void Herbivora::makan(Produk *makanan){
    if(instanceof<ProdukTanamanBuah>(makanan)){
        //melakukan proses makan
        tambah_berat(makanan->dapatkan_berat_tambahan());
        cout << "Berhasil makan" <<endl;
    }else{
        //mengeluarkan pesan error
        cout << "Tidak berhasil makan, masukan makanan yang sesuai" <<endl;
    }
}

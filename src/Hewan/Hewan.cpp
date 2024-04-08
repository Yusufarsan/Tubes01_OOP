#include "Hewan.hpp"

Hewan :: Hewan(string id, string kode_huruf, string nama, int harga, int berat_panen): berat(0), berat_panen(berat_panen), Entitas(id,kode_huruf,nama,harga){};

Hewan :: Hewan(Hewan& other): Entitas(other), berat(other.dapatkan_berat()), berat_panen(other.dapatkan_berat_panen()) {}

Hewan :: ~Hewan(){}

Hewan& Hewan :: operator=(const Hewan& other){
    berat = other.berat;
    berat_panen = other.berat_panen;
    Entitas::operator=(other);
    return *this;
}

int Hewan::dapatkan_berat(){
    return berat;
}

int Hewan::dapatkan_berat_panen(){
    return berat_panen;
}

void Hewan::tambah_berat(int num){
    this->berat+=num;
}

bool Hewan::bisa_panen(){
    return berat>=berat_panen;
}

void Hewan::print_info(){
    cout << Entitas::id << endl;
    cout << Entitas::nama << endl;
    cout << Entitas::kode_huruf << endl;
    cout << Entitas::harga << endl;
    cout << berat << endl;
    cout << berat_panen << endl;
}
#include "Petani.hpp"

int main(){
    cout << "constructor" << endl;
    Petani tani("Bulog", 50, 50, make_tuple(10, 10), make_tuple(5, 5)); // ctor
    // Petani tani("Bulog");

    tani.cetak_ladang();

    

    // cout << tani.jumlah_slot_kosong_ladang() << endl;
    // cout << tani.cek_slot_ladang_valid("A01") << endl;
    // cout << tani.cek_slot_ladang_valid("K11") << endl;

    // tani.tanam();
    // Tanaman* kaktus = new Tanaman(30);
    // tani.tambah_ladang("A01", kaktus);

    // cout << tani.hapus_ladang("A01") << endl;

    // tani.panen();

    // tani.cetak_ladang();
    // cout << player;

    // cout << "dapatkan_nama" << endl;
    // cout << player.dapatkan_nama() << endl;

    // cout << endl << "atur_uang dan dapatkan_uang" << endl;
    // player.atur_uang(999);
    // cout << player.dapatkan_uang() << endl;

    // cout << endl << "atur_berat_badan dan dapatkan_berat_badan" << endl;
    // player.atur_berat_badan(60);
    // cout << player.dapatkan_berat_badan() << endl;


    // cout << endl << "cetak_peti" << endl;
    // player.cetak_peti();

    // player.tambah_peti("AB13");

    // player.jual();
    // player.beli();
    // player.makan();
    
    return 0;
}
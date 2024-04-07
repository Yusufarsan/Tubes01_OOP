#include "Pemain.hpp"

int main(){
    cout << "constructor" << endl;
    Pemain player("Mage Tiktok", 50, 60);
    cout << player;

    cout << "dapatkan_nama" << endl;
    cout << player.dapatkan_nama() << endl;

    cout << endl << "atur_uang dan dapatkan_uang" << endl;
    player.atur_uang(999);
    cout << player.dapatkan_uang() << endl;

    cout << endl << "atur_berat_badan dan dapatkan_berat_badan" << endl;
    player.atur_berat_badan(60);
    cout << player.dapatkan_berat_badan() << endl;


    cout << endl << "cetak_peti" << endl;
    player.cetak_peti();

    // player.tambah_peti("AB13", Entitas* stuff);

    cout << endl << "jualan" << endl;
    player.jual();

    cout << endl << "beli" << endl;
    player.beli();

    cout << endl << "makan" << endl;
    player.makan();
    
    return 0;
}
#include "Pemain.hpp"

int main() {
    shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
    shared_ptr<Hewan> ayam = make_shared<Omnivora>("2", "CHK", "ayam", 200, 10);
    shared_ptr<Hewan> sapi = make_shared<Herbivora>("3", "COW", "sapi", 200, 10);
    shared_ptr<Hewan> ular = make_shared<Karnivora>("4", "SNK", "ular", 200, 10);
    shared_ptr<Hewan> beruang = make_shared<Omnivora>("5", "BER", "beruang", 200, 10);

    cout << "constructor" << endl;
    Pemain player("player", 1000, 50, make_tuple(7, 7));
    // cout << player;

    cout << "dapatkan_nama" << endl;
    cout << player.dapatkan_nama() << endl;

    cout << endl << "atur_uang dan dapatkan_uang" << endl;
    player.atur_uang(999);
    cout << player.dapatkan_uang() << endl;

    cout << endl << "atur_berat_badan dan dapatkan_berat_badan" << endl;
    player.atur_berat_badan(60);
    cout << player.dapatkan_berat_badan() << endl;

    // string slot_masukan;

    // cin >> slot_masukan;


    player.tambah_peti(sapi);
    player.tambah_peti(ayam);
    player.tambah_peti(kambing);
    player.tambah_peti(ular);

    // cout << endl << "cetak_peti" << endl;
    // player.cetak_peti();

    // cin >> slot_masukan;

    // player.tambah_peti(slot_masukan, ular);

    // player.cetak_peti();

    // cout << "hapus" << endl;
    // cin >> slot_masukan;


    // player.hapus_peti(slot_masukan);

    
    player.cetak_peti();

    cout << endl << "jualan" << endl;
    cout << player.dapatkan_uang()<<endl;
    Toko* toko = new Toko();
    player.jual(*toko);
    cout << player.dapatkan_uang()<<endl;

    cout << endl << "Cetak Peti" << endl;
    player.cetak_peti();
    // cout << player << endl;
    // player.beli();

    // cout << endl << "makan" << endl;
    // player.makan();

    return 0;
}
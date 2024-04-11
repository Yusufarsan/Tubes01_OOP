#include "Pemain.hpp"

int main() {
    shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
    shared_ptr<Tanaman> tomat = make_shared<TanamanBuah>("1", "TMT", "Tomat", 30, 20);

    cout << "constructor" << endl;
    Pemain player("player", 1000, 50, make_tuple(2, 2));
    cout << player;

    cout << "dapatkan_nama" << endl;
    cout << player.dapatkan_nama() << endl;

    cout << endl << "atur_uang dan dapatkan_uang" << endl;
    player.atur_uang(999);
    cout << player.dapatkan_uang() << endl;

    cout << endl << "atur_berat_badan dan dapatkan_berat_badan" << endl;
    player.atur_berat_badan(60);
    cout << player.dapatkan_berat_badan() << endl;

    string slot_masukan;

    cin >> slot_masukan;

    player.tambah_peti(slot_masukan, kambing);

    cout << endl << "cetak_peti" << endl;
    player.cetak_peti();

    cin >> slot_masukan;

    player.tambah_peti(slot_masukan, tomat);

    player.cetak_peti();

    cin >> slot_masukan;

    cout << "hapus" << endl;

    player.hapus_peti(slot_masukan);

    player.cetak_peti();

    cout << endl << "jualan" << endl;
    player.jual();

    // cout << endl << "beli" << endl;
    // player.beli();

    // cout << endl << "makan" << endl;
    // player.makan();

    return 0;
}
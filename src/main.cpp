// #include "Pemain/Pemain.hpp"

// int main() {
//     shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
//     shared_ptr<Tanaman> tomat = make_shared<TanamanBuah>("1", "TMT", "Tomat", 30, 20);

//     cout << "constructor" << endl;
//     Pemain player("player", 1000, 50, make_tuple(2, 2));
//     cout << player;

//     cout << "dapatkan_nama" << endl;
//     cout << player.dapatkan_nama() << endl;

//     cout << endl << "atur_uang dan dapatkan_uang" << endl;
//     player.atur_uang(999);
//     cout << player.dapatkan_uang() << endl;

//     cout << endl << "atur_berat_badan dan dapatkan_berat_badan" << endl;
//     player.atur_berat_badan(60);
//     cout << player.dapatkan_berat_badan() << endl;

    // string slot_masukan;

    // cin >> slot_masukan;

    // player.tambah_peti(slot_masukan, kambing);

//     cout << endl << "cetak_peti" << endl;
//     player.cetak_peti();

//     cin >> slot_masukan;

//     player.tambah_peti(slot_masukan, tomat);

//     player.cetak_peti();

//     cin >> slot_masukan;

//     cout << "hapus" << endl;

//     player.hapus_peti(slot_masukan);

//     player.cetak_peti();

//     return 0;
// }


#include "Pemain/Petani.hpp"

int main() {
    // shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
    shared_ptr<Tanaman> tomat = make_shared<TanamanBuah>("1", "TMT", "Tomat", 30, 3);
    shared_ptr<Tanaman> apel = make_shared<TanamanBuah>("2", "APL", "Apel", 30, 2);

    cout << "constructor" << endl;
    Petani tani("Bulog", 50, 50, make_tuple(10, 10), make_tuple(5, 5)); // ctor

    tani.cetak_peti();

    string slot_masukan;

    cin >> slot_masukan;

    tani.tambah_peti(slot_masukan, apel);

    tani.cetak_peti();

    cin >> slot_masukan;

    tani.tambah_peti(slot_masukan, tomat);

    tani.cetak_peti();

    // for (int i = 0; i < 5; i++){
    //     tomat.get()->tambah_umur();
    //     apel.get()->tambah_umur();
    // }

    // cin >> slot_masukan;

    // tani.tambah_ladang(slot_masukan, *(apel.get()));

    // tani.cetak_ladang();

    // cin >> slot_masukan;

    // tani.tambah_ladang(slot_masukan, *(tomat.get()));

    // tani.cetak_ladang();

    tani.tanam();
    tani.cetak_peti();
    tani.cetak_ladang();


    return 0;
}

// #include "Pemain/Peternak.hpp"

// int main() {
//     // shared_ptr<Hewan> kambing = make_shared<Herbivora>("1", "GOT", "mbek", 20, 5);
//     shared_ptr<Hewan> kambing = make_shared<Karnivora>("1", "MBE", "Kambing", 30, 3);
//     shared_ptr<Hewan> kucing = make_shared<Karnivora>("2", "MEO", "Kucing", 30, 2);

//     cout << "constructor" << endl;
//     Peternak gembala("Upin", 50, 50, make_tuple(10, 10), make_tuple(5, 5)); // ctor

//     gembala.cetak_peti();

//     string slot_masukan;

//     cin >> slot_masukan;

//     gembala.tambah_peti(slot_masukan, kambing);

//     gembala.cetak_peti();

//     cin >> slot_masukan;

//     gembala.tambah_peti(slot_masukan, kucing);

//     gembala.cetak_peti();

//     // for (int i = 0; i < 5; i++){
//     //     tomat.get()->tambah_umur();
//     //     apel.get()->tambah_umur();
//     // }

//     // cin >> slot_masukan;

//     // tani.tambah_ladang(slot_masukan, *(apel.get()));

//     // tani.cetak_ladang();

//     // cin >> slot_masukan;

//     // tani.tambah_ladang(slot_masukan, *(tomat.get()));

//     // tani.cetak_ladang();

//     gembala.ternak();
//     gembala.cetak_peti();
//     gembala.cetak_peternakan();


//     return 0;
// }
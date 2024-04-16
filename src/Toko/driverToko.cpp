#include "Toko.hpp"
#include "../Tanaman/TanamanBuah.hpp"
#include "../Tanaman/TanamanMaterial.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukHewan.hpp"
#include "../Produk/ProdukTanamanBuah.hpp"
#include <memory>


int main() {
    // Membuat objek toko
    Toko toko;

    // Membuat beberapa objek tanaman, hewan, produk, dan bangunan
    shared_ptr<Tanaman> tanaman1 = make_shared<TanamanBuah>("1", "PAD", "Padi", 100, 20);
    shared_ptr<Tanaman> tanaman2 = make_shared<TanamanMaterial>("2", "JAT", "Jati", 100, 20);
    shared_ptr<Hewan> hewan1 = make_shared<Karnivora>("3", "CHK", "Ayam", 100, 20);
    shared_ptr<Hewan> hewan2 = make_shared<Omnivora>("4", "COW", "Sapi", 100, 20);
    shared_ptr<Produk> produk1 = make_shared<ProdukHewan>("5", "EGG", "Telur", 100, 10, "Ayam");
    shared_ptr<Produk> produk2 = make_shared<ProdukTanamanBuah>("6", "BRS", "Beras", 100, 10, "Padi");
    shared_ptr<Produk> produk3 = make_shared<ProdukTanamanBuah>("6", "BRS", "Beras", 100, 10, "Padi");
    shared_ptr<Bangunan> bangunan1 = make_shared<Bangunan>("7", "GDG", "Gudang", 1000);
    shared_ptr<Bangunan> bangunan2 = make_shared<Bangunan>("8", "KDG", "Kandang", 1000);

    // Menambahkan tanaman, hewan, produk, dan bangunan ke dalam toko
    vector<shared_ptr<Tanaman>> daftar_tanaman = { tanaman1, tanaman2 };
    toko.atur_tanaman(daftar_tanaman);

    vector<shared_ptr<Hewan>> daftar_hewan = { hewan1, hewan2 };
    toko.atur_hewan(daftar_hewan);

    toko.tambah_produk(produk1);
    toko.tambah_produk(produk2);
    toko.tambah_produk(produk3);

    toko.tambah_bangunan(bangunan1);
    toko.tambah_bangunan(bangunan2);

    // Menampilkan isi toko
    cout << "Isi Toko:" << endl;
    toko.cetak_isi_toko();

    return 0;
}
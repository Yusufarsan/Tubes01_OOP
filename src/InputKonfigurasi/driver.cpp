#include "./InputKonfigurasi.hpp"

int main() {
    // vector<Tanaman*> daftar_tanaman = InputKonfigurasi::InputKonfigurasiTanaman("../../config/plant.txt");
    // vector<Hewan*> daftar_hewan = InputKonfigurasi::InputKonfigurasiHewan("../../config/animal.txt");
    // vector<Produk*> daftar_produk = InputKonfigurasi::InputKonfigurasiProduk("../../config/product.txt");
    vector<Bangunan> daftar_bangunan = InputKonfigurasi::InputKonfigurasiResepBangunan("../../config/recipe.txt");

    for (int i = 0; i < daftar_bangunan.size(); i++) {
        daftar_bangunan[i].print_info();
        cout << endl;
    }


    return 0;
}
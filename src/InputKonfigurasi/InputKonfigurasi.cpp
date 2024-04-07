#include "InputKonfigurasi.hpp"


vector<Tanaman*> InputKonfigurasi::InputKonfigurasiTanaman(string nama_file) {
    vector<Tanaman*> daftar_tanaman;
    ifstream file;
    file.open(nama_file);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> data = Util::SplitString(line, " ");
            string id = data[0];
            string kode_huruf = data[1];
            string nama = data[2];
            string tipe = data[3];
            int umur_panen = stoi(data[4]);
            int harga = stoi(data[5]);

            if (tipe == "MATERIAL_PLANT") {
                Tanaman* tanaman = new TanamanMaterial(id, kode_huruf, nama, umur_panen, harga);
                daftar_tanaman.push_back(tanaman);
            }
            else if (tipe == "FRUIT_PLANT") {
                Tanaman* tanaman = new TanamanBuah(id, kode_huruf, nama, umur_panen, harga);
                daftar_tanaman.push_back(tanaman);
            }
        }

        file.close();
    }

    return daftar_tanaman;
}

vector<Hewan*> InputKonfigurasi::InputKonfigurasiHewan(string nama_file) {
    vector<Hewan*> daftar_hewan;
    ifstream file;
    file.open(nama_file);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> data = Util::SplitString(line, " ");
            string id = data[0];
            string kode_huruf = data[1];
            string nama = data[2];
            string tipe = data[3];
            int berat = stoi(data[4]);
            int harga = stoi(data[5]);

            if (tipe == "HERBIVORE") {
                Hewan* hewan = new Herbivora(id, kode_huruf, nama, berat, harga);
                daftar_hewan.push_back(hewan);
            }
            else if (tipe == "CARNIVORE") {
                Hewan* hewan = new Karnivora(id, kode_huruf, nama, berat, harga);
                daftar_hewan.push_back(hewan);
            }
            else if (tipe == "OMNIVORE") {
                Hewan* hewan = new Omnivora(id, kode_huruf, nama, berat, harga);
                daftar_hewan.push_back(hewan);
            }
        }

        file.close();
    }

    return daftar_hewan;
}

vector<Produk*> InputKonfigurasi::InputKonfigurasiProduk(string nama_file) {
    vector<Produk*> daftar_produk;
    ifstream file;
    file.open(nama_file);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> data = Util::SplitString(line, " ");
            string id = data[0];
            string kode_huruf = data[1];
            string nama = data[2];
            string tipe = data[3];
            string origin = data[4];
            int berat_tambahan = stoi(data[5]);
            int harga = stoi(data[6]);

            if (tipe == "PRODUCT_MATERIAL_PLANT") {
                Produk* produk = new ProdukTanamanMaterial(berat_tambahan, origin, id, kode_huruf, nama, harga);
                daftar_produk.push_back(produk);
            }
            else if (tipe == "PRODUCT_FRUIT_PLANT") {
                Produk* produk = new ProdukTanamanBuah(berat_tambahan, origin, id, kode_huruf, nama, harga);
                daftar_produk.push_back(produk);
            }
            else if (tipe == "PRODUCT_ANIMAL") {
                Produk* produk = new ProdukHewan(berat_tambahan, origin, id, kode_huruf, nama, harga);
                daftar_produk.push_back(produk);
            }
        }

        file.close();
    }

    return daftar_produk;
}
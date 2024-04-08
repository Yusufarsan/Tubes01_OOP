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
                Tanaman* tanaman = new TanamanMaterial(id, kode_huruf, nama, harga, umur_panen);
                daftar_tanaman.push_back(tanaman);
            }
            else if (tipe == "FRUIT_PLANT") {
                Tanaman* tanaman = new TanamanBuah(id, kode_huruf, nama, harga, umur_panen);
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
                Hewan* hewan = new Herbivora(id, kode_huruf, nama, harga, berat);
                daftar_hewan.push_back(hewan);
            }
            else if (tipe == "CARNIVORE") {
                Hewan* hewan = new Karnivora(id, kode_huruf, nama, harga, berat);
                daftar_hewan.push_back(hewan);
            }
            else if (tipe == "OMNIVORE") {
                Hewan* hewan = new Omnivora(id, kode_huruf, nama, harga, berat);
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
                Produk* produk = new ProdukTanamanMaterial(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(produk);
            }
            else if (tipe == "PRODUCT_FRUIT_PLANT") {
                Produk* produk = new ProdukTanamanBuah(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(produk);
            }
            else if (tipe == "PRODUCT_ANIMAL") {
                Produk* produk = new ProdukHewan(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(produk);
            }
        }

        file.close();
    }

    return daftar_produk;
}


vector<Bangunan> InputKonfigurasi::InputKonfigurasiResepBangunan(string nama_file) {
    vector<Bangunan> daftar_bangunan;
    ifstream file;
    file.open(nama_file);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> data = Util::SplitString(line, " ");
            string id = data[0];
            string kode_huruf = data[1];
            string nama = data[2];
            int harga = stoi(data[3]);
            map<string, int> resep_tanaman;
            for (int i = 4; i < data.size(); i += 2) {
                resep_tanaman[data[i]] = stoi(data[i + 1]);
            }

            Bangunan bangunan(id, kode_huruf, nama, harga);
            bangunan.atur_resep_tanaman(resep_tanaman);
            daftar_bangunan.push_back(bangunan);
        }

        file.close();
    }

    return daftar_bangunan;
}
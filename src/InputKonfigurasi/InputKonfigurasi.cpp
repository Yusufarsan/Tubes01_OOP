#include "InputKonfigurasi.hpp"


vector<shared_ptr<Tanaman>> InputKonfigurasi::InputKonfigurasiTanaman(string nama_file) {
    vector<shared_ptr<Tanaman>> daftar_tanaman;
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
                shared_ptr<Tanaman> tanaman = make_unique<TanamanMaterial>(id, kode_huruf, nama, harga, umur_panen);
                daftar_tanaman.push_back(move(tanaman));
            }
            else if (tipe == "FRUIT_PLANT") {
                shared_ptr<Tanaman> tanaman = make_unique<TanamanBuah>(id, kode_huruf, nama, harga, umur_panen);
                daftar_tanaman.push_back(move(tanaman));
            }
        }

        file.close();
    }

    return daftar_tanaman;
}

vector<shared_ptr<Hewan>> InputKonfigurasi::InputKonfigurasiHewan(string nama_file) {
    vector<shared_ptr<Hewan>> daftar_hewan;
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
                shared_ptr<Hewan> hewan = make_unique<Herbivora>(id, kode_huruf, nama, harga, berat);
                daftar_hewan.push_back(move(hewan));
            }
            else if (tipe == "CARNIVORE") {
                shared_ptr<Hewan> hewan = make_unique<Karnivora>(id, kode_huruf, nama, harga, berat);
                daftar_hewan.push_back(move(hewan));
            }
            else if (tipe == "OMNIVORE") {
                shared_ptr<Hewan> hewan = make_unique<Omnivora>(id, kode_huruf, nama, harga, berat);
                daftar_hewan.push_back(move(hewan));
            }
        }

        file.close();
    }

    return daftar_hewan;
}

vector<shared_ptr<Produk>> InputKonfigurasi::InputKonfigurasiProduk(string nama_file) {
    vector<shared_ptr<Produk>> daftar_produk;
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
                shared_ptr<Produk> produk = make_unique<ProdukTanamanMaterial>(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(move(produk));
            }
            else if (tipe == "PRODUCT_FRUIT_PLANT") {
                shared_ptr<Produk> produk = make_unique<ProdukTanamanBuah>(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(move(produk));
            }
            else if (tipe == "PRODUCT_ANIMAL") {
                shared_ptr<Produk> produk = make_unique<ProdukHewan>(id, kode_huruf, nama, harga, berat_tambahan, origin);
                daftar_produk.push_back(move(produk));
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

vector<int> InputKonfigurasi::InputKonfigurasiMisc(string nama_file) {
    vector<int> data;
    ifstream file;
    file.open(nama_file);
    if (file.is_open()) {
        string line;

        // Jumlah uang pemain untuk menang
        getline(file, line);
        int uang_pemenang = stoi(line);
        data.push_back(uang_pemenang);

        // Jumlah berat pemain untuk menang
        getline(file, line);
        int berat_pemenang = stoi(line);
        data.push_back(berat_pemenang);

        // Besar penyimpanan
        getline(file, line);
        vector<string> vector_penyimpanan = Util::SplitString(line, " ");
        int besar_penyimpanan1 = stoi(vector_penyimpanan[0]);
        int besar_penyimpanan2 = stoi(vector_penyimpanan[1]);
        data.push_back(besar_penyimpanan1);
        data.push_back(besar_penyimpanan2);

        // Besar lahan
        getline(file, line);
        vector<string> vector_lahan = Util::SplitString(line, " ");
        int besar_lahan1 = stoi(vector_lahan[0]);
        int besar_lahan2 = stoi(vector_lahan[1]);
        data.push_back(besar_lahan1);
        data.push_back(besar_lahan2);

        // Besar peternakan
        getline(file, line);
        vector<string> vector_peternakan = Util::SplitString(line, " ");
        int besar_peternakan1 = stoi(vector_peternakan[0]);
        int besar_peternakan2 = stoi(vector_peternakan[1]);
        data.push_back(besar_peternakan1);
        data.push_back(besar_peternakan2);
    }

    return data;
}
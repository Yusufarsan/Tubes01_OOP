#include "InputKonfigurasi.hpp"

// Input Konfigurasi
vector<shared_ptr<Tanaman>> InputKonfigurasi::InputKonfigurasiTanaman(string nama_file) {
    vector<shared_ptr<Tanaman>> daftar_tanaman;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;
    while (getline(file, line)) {
        Util::trim(line);
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


    return daftar_tanaman;
}

vector<shared_ptr<Hewan>> InputKonfigurasi::InputKonfigurasiHewan(string nama_file) {
    vector<shared_ptr<Hewan>> daftar_hewan;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;
    while (getline(file, line)) {
        Util::trim(line);
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

    return daftar_hewan;
}

vector<shared_ptr<Produk>> InputKonfigurasi::InputKonfigurasiProduk(string nama_file) {
    vector<shared_ptr<Produk>> daftar_produk;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;
    while (getline(file, line)) {
        Util::trim(line);
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

    return daftar_produk;
}

vector<shared_ptr<Bangunan>> InputKonfigurasi::InputKonfigurasiResepBangunan(string nama_file) {
    vector<shared_ptr<Bangunan>> daftar_bangunan;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;
    while (getline(file, line)) {
        Util::trim(line);
        vector<string> data = Util::SplitString(line, " ");
        string id = data[0];
        string kode_huruf = data[1];
        string nama = data[2];
        int harga = stoi(data[3]);
        map<string, int> resep_tanaman;
        for (int i = 4; i < data.size(); i += 2) {
            resep_tanaman[data[i]] = stoi(data[i + 1]);
        }

        shared_ptr<Bangunan> bangunan = make_unique<Bangunan>(id, kode_huruf, nama, harga);
        bangunan->atur_resep_tanaman(resep_tanaman);
        daftar_bangunan.push_back(bangunan);
    }

    file.close();

    return daftar_bangunan;
}

vector<int> InputKonfigurasi::InputKonfigurasiMisc(string nama_file) {
    vector<int> data;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;

    // Jumlah uang pemain untuk menang
    getline(file, line);
    Util::trim(line);
    int uang_pemenang = stoi(line);
    data.push_back(uang_pemenang);

    // Jumlah berat pemain untuk menang
    getline(file, line);
    Util::trim(line);
    int berat_pemenang = stoi(line);
    data.push_back(berat_pemenang);

    // Besar penyimpanan
    getline(file, line);
    Util::trim(line);
    vector<string> vector_penyimpanan = Util::SplitString(line, " ");
    int besar_penyimpanan1 = stoi(vector_penyimpanan[0]);
    int besar_penyimpanan2 = stoi(vector_penyimpanan[1]);
    data.push_back(besar_penyimpanan1);
    data.push_back(besar_penyimpanan2);

    // Besar lahan
    getline(file, line);
    Util::trim(line);
    vector<string> vector_lahan = Util::SplitString(line, " ");
    int besar_lahan1 = stoi(vector_lahan[0]);
    int besar_lahan2 = stoi(vector_lahan[1]);
    data.push_back(besar_lahan1);
    data.push_back(besar_lahan2);

    // Besar peternakan
    getline(file, line);
    Util::trim(line);
    vector<string> vector_peternakan = Util::SplitString(line, " ");
    int besar_peternakan1 = stoi(vector_peternakan[0]);
    int besar_peternakan2 = stoi(vector_peternakan[1]);
    data.push_back(besar_peternakan1);
    data.push_back(besar_peternakan2);

    return data;
}

// Input State Pemain
vector<shared_ptr<Pemain>> InputKonfigurasi::InputStatePemain(string nama_file, vector<shared_ptr<Tanaman>> daftar_tanaman, vector<shared_ptr<Hewan>> daftar_hewan, vector<shared_ptr<Produk>> daftar_produk, vector<shared_ptr<Bangunan>> daftar_bangunan, tuple<int, int> besar_penyimpanan, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan, Toko& toko) {
    vector<shared_ptr<Pemain>> daftar_pemain;
    ifstream file;
    file.open(nama_file);

    if (!file.is_open()) {
        throw invalid_argument("File tidak ditemukan");
    }

    string line;
    getline(file, line);
    Util::trim(line);
    int jumlah_pemain = stoi(line);

    for (int i = 0; i < jumlah_pemain; i++) {
        getline(file, line);
        Util::trim(line);
        vector<string> data = Util::SplitString(line, " ");
        string nama = data[0];
        string tipe = data[1];
        int berat_badan = stoi(data[2]);
        int uang = stoi(data[3]);
        if (tipe == "Petani") {
            shared_ptr<Pemain> pemain = make_unique<Petani>(nama, uang, berat_badan, besar_penyimpanan, besar_lahan);

            getline(file, line);
            Util::trim(line);
            int jumlah_item = stoi(line);
            for (int j = 0; j < jumlah_item; j++) {
                getline(file, line);
                Util::trim(line);
                bool found = false;

                int k = 0;
                while (!found && k < daftar_tanaman.size()) {
                    if (daftar_tanaman[k]->dapatkan_nama() == line) {
                        shared_ptr<Tanaman> tanaman = make_unique<Tanaman>(*daftar_tanaman[k]);
                        pemain->tambah_peti(tanaman);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_hewan.size()) {
                    if (daftar_hewan[k]->dapatkan_nama() == line) {
                        shared_ptr<Hewan> hewan;
                        if (Util::instanceof<Herbivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Herbivora>(*dynamic_pointer_cast<Herbivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Karnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Karnivora>(*dynamic_pointer_cast<Karnivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Omnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Omnivora>(*dynamic_pointer_cast<Omnivora>(daftar_hewan[k]));
                        }

                        pemain->tambah_peti(hewan);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_produk.size()) {
                    if (daftar_produk[k]->dapatkan_nama() == line) {
                        shared_ptr<Produk> produk;
                        if (Util::instanceof<ProdukHewan>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukHewan>(*dynamic_pointer_cast<ProdukHewan>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanBuah>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanBuah>(*dynamic_pointer_cast<ProdukTanamanBuah>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanMaterial>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanMaterial>(*dynamic_pointer_cast<ProdukTanamanMaterial>(daftar_produk[k]));
                        }

                        pemain->tambah_peti(produk);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_bangunan.size()) {
                    if (daftar_bangunan[k]->dapatkan_nama() == line) {
                        shared_ptr<Bangunan> bangunan = make_unique<Bangunan>(*daftar_bangunan[k]);
                        pemain->tambah_peti(bangunan);
                        found = true;
                    }
                    k++;
                }
            }

            getline(file, line);
            Util::trim(line);
            int jumlah_tanaman_di_ladang = stoi(line);
            for (int j = 0; j < jumlah_tanaman_di_ladang; j++) {
                getline(file, line);
                Util::trim(line);
                vector<string> data = Util::SplitString(line, " ");
                string slot = data[0];
                string nama_tanaman = data[1];
                int umur = stoi(data[2]);

                bool found = false;
                int k = 0;
                while (!found && k < daftar_tanaman.size()) {
                    if (daftar_tanaman[k]->dapatkan_nama() == nama_tanaman) {
                        shared_ptr<Petani> petani = dynamic_pointer_cast<Petani>(pemain);
                        shared_ptr<Tanaman> tanaman = make_unique<Tanaman>(*daftar_tanaman[k]);
                        while (umur > 0) {
                            tanaman->tambah_umur();
                            umur--;
                        }
                        petani->tambah_ladang(slot, tanaman);
                        found = true;
                    }
                    k++;
                }
            }

            daftar_pemain.push_back(pemain);
        }
        else if (tipe == "Peternak") {
            shared_ptr<Pemain> pemain = make_unique<Peternak>(nama, uang, berat_badan, besar_penyimpanan, besar_peternakan);

            getline(file, line);
            Util::trim(line);
            int jumlah_item = stoi(line);
            for (int j = 0; j < jumlah_item; j++) {
                getline(file, line);
                Util::trim(line);
                bool found = false;

                int k = 0;
                while (!found && k < daftar_tanaman.size()) {
                    if (daftar_tanaman[k]->dapatkan_nama() == line) {
                        shared_ptr<Tanaman> tanaman = make_unique<Tanaman>(*daftar_tanaman[k]);
                        pemain->tambah_peti(tanaman);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_hewan.size()) {
                    if (daftar_hewan[k]->dapatkan_nama() == line) {
                        shared_ptr<Hewan> hewan;
                        if (Util::instanceof<Herbivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Herbivora>(*dynamic_pointer_cast<Herbivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Karnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Karnivora>(*dynamic_pointer_cast<Karnivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Omnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Omnivora>(*dynamic_pointer_cast<Omnivora>(daftar_hewan[k]));
                        }
                        pemain->tambah_peti(hewan);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_produk.size()) {
                    if (daftar_produk[k]->dapatkan_nama() == line) {
                        shared_ptr<Produk> produk;
                        if (Util::instanceof<ProdukHewan>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukHewan>(*dynamic_pointer_cast<ProdukHewan>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanBuah>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanBuah>(*dynamic_pointer_cast<ProdukTanamanBuah>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanMaterial>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanMaterial>(*dynamic_pointer_cast<ProdukTanamanMaterial>(daftar_produk[k]));
                        }

                        pemain->tambah_peti(produk);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_bangunan.size()) {
                    if (daftar_bangunan[k]->dapatkan_nama() == line) {
                        shared_ptr<Bangunan> bangunan = make_unique<Bangunan>(*daftar_bangunan[k]);
                        pemain->tambah_peti(bangunan);
                        found = true;
                    }
                    k++;
                }
            }

            getline(file, line);
            Util::trim(line);
            int jumlah_hewan_di_peternakan = stoi(line);
            for (int j = 0; j < jumlah_hewan_di_peternakan; j++) {
                getline(file, line);
                Util::trim(line);
                vector<string> data = Util::SplitString(line, " ");
                string slot = data[0];
                string nama_hewan = data[1];
                int berat = stoi(data[2]);

                bool found = false;
                int k = 0;
                while (!found && k < daftar_hewan.size()) {
                    if (daftar_hewan[k]->dapatkan_nama() == nama_hewan) {
                        shared_ptr<Peternak> peternak = dynamic_pointer_cast<Peternak>(pemain);
                        shared_ptr<Hewan> hewan;
                        if (Util::instanceof<Herbivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Herbivora>(*dynamic_pointer_cast<Herbivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Karnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Karnivora>(*dynamic_pointer_cast<Karnivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Omnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Omnivora>(*dynamic_pointer_cast<Omnivora>(daftar_hewan[k]));
                        }
                        hewan->tambah_berat(berat);
                        peternak->tambah_peternakan(slot, hewan);
                        found = true;
                    }
                    k++;
                }
            }

            daftar_pemain.push_back(pemain);
        }
        else if (tipe == "Walikota") {
            shared_ptr<Pemain> pemain = make_unique<Walikota>(nama, uang, berat_badan, besar_penyimpanan);

            getline(file, line);
            Util::trim(line);
            int jumlah_item = stoi(line);
            for (int j = 0; j < jumlah_item; j++) {
                getline(file, line);
                Util::trim(line);
                bool found = false;

                int k = 0;
                while (!found && k < daftar_tanaman.size()) {
                    if (daftar_tanaman[k]->dapatkan_nama() == line) {
                        shared_ptr<Tanaman> tanaman = make_unique<Tanaman>(*daftar_tanaman[k]);
                        pemain->tambah_peti(tanaman);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_hewan.size()) {
                    if (daftar_hewan[k]->dapatkan_nama() == line) {
                        shared_ptr<Hewan> hewan;
                        if (Util::instanceof<Herbivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Herbivora>(*dynamic_pointer_cast<Herbivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Karnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Karnivora>(*dynamic_pointer_cast<Karnivora>(daftar_hewan[k]));
                        }
                        else if (Util::instanceof<Omnivora>(daftar_hewan[k].get())) {
                            hewan = make_unique<Omnivora>(*dynamic_pointer_cast<Omnivora>(daftar_hewan[k]));
                        }

                        pemain->tambah_peti(hewan);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_produk.size()) {
                    if (daftar_produk[k]->dapatkan_nama() == line) {
                        shared_ptr<Produk> produk;
                        if (Util::instanceof<ProdukHewan>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukHewan>(*dynamic_pointer_cast<ProdukHewan>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanBuah>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanBuah>(*dynamic_pointer_cast<ProdukTanamanBuah>(daftar_produk[k]));
                        }
                        else if (Util::instanceof<ProdukTanamanMaterial>(daftar_produk[k].get())) {
                            produk = make_unique<ProdukTanamanMaterial>(*dynamic_pointer_cast<ProdukTanamanMaterial>(daftar_produk[k]));
                        }

                        pemain->tambah_peti(produk);
                        found = true;
                    }
                    k++;
                }

                k = 0;
                while (!found && k < daftar_bangunan.size()) {
                    if (daftar_bangunan[k]->dapatkan_nama() == line) {
                        shared_ptr<Bangunan> bangunan = make_unique<Bangunan>(*daftar_bangunan[k]);
                        pemain->tambah_peti(bangunan);
                        found = true;
                    }
                    k++;
                }
            }

            daftar_pemain.push_back(pemain);
        }
    }

    getline(file, line);
    Util::trim(line);
    int jumlah_item_toko = stoi(line);

    for (int i = 0; i < jumlah_item_toko; i++) {
        getline(file, line);
        Util::trim(line);
        vector<string> data = Util::SplitString(line, " ");
        string nama = data[0];
        int banyak = stoi(data[1]);

        bool found = false;
        int j = 0;

        j = 0;
        while (!found && j < daftar_produk.size()) {
            if (daftar_produk[j]->dapatkan_nama() == nama) {
                while (banyak > 0) {
                    toko.tambah_produk(daftar_produk[j]);
                    banyak--;
                }
                found = true;
            }
            j++;
        }

        j = 0;
        while (!found && j < daftar_bangunan.size()) {
            if (daftar_bangunan[j]->dapatkan_nama() == nama) {
                while (banyak > 0) {
                    toko.tambah_bangunan(daftar_bangunan[j]);
                    banyak--;
                }
                found = true;
            }
            j++;
        }
    }

    file.close();


    return daftar_pemain;
}
#include "Peternak.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <cmath>

Peternak::Peternak(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_peternakan) : Pemain(nama, uang, berat_badan, ukuran_peti), peternakan(get<0>(ukuran_peternakan), get<1>(ukuran_peternakan)) {}

Peternak::~Peternak() {};

void Peternak::cetak_peternakan() {
    int numRow = peternakan.dapatkanBaris();
    int numCol = peternakan.dapatkanKolom();
    // int emptySlot = 0;


    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // Cetak judul tabel
    cout << "    ================[ Peternakan ]==================\n\n";

    // cetak label kolom
    for (int n = 1; n <= numCol; ++n) {
        if (n == 1) {
            string spaces(maxLengthRowCode + 1, ' ');
            cout << spaces;
        }

        string label_kolom = Util::label_kolom_tabel(n);
        int pad1Length = round(double(6 - label_kolom.length()) / 2);
        int pad2Length;

        if ((6 - label_kolom.length()) % 2 == 1) {
            pad2Length = pad1Length - 1;
        }
        else {
            pad2Length = pad1Length;
        }

        string pad1(pad1Length, ' ');
        string pad2(pad2Length, ' ');
        cout << pad1 << label_kolom << pad2;
    }
    cout << endl;

    // first +---+
    for (int n = 1; n <= numCol; n++) {
        if (n == 1) {
            string spaces(maxLengthRowCode + 1, ' ');
            cout << spaces;
        }

        string dash(5, '-');
        cout << "+" << dash;
    }
    cout << "+\n";

    // cetak label baris dan elemennya
    for (int n = 1; n <= numRow; n++) {
        string label_baris = Util::label_baris_tabel(n);
        string space(maxLengthRowCode + 1 - label_baris.length(), ' ');
        cout << label_baris << space << '|';

        for (int m = 0; m < numCol; m++) {
            if (peternakan.apakahSlotKosong(n - 1, m)) {
                cout << "     |";
                // emptySlot++;
            }
            else {
                Hewan* val = peternakan.dapatkanElemen(n - 1, m);
                if (val->bisa_panen()) {
                    cout << " ";

                    print_green(val->dapatkan_kode_huruf());

                    cout << " |";
                }
                else {
                    cout << " ";

                    print_red(val->dapatkan_kode_huruf());

                    cout << " |";
                }
            }

        }
        cout << endl;

        // +---+
        for (int n = 1; n <= numCol; n++) {
            if (n == 1) {
                string spaces(maxLengthRowCode + 1, ' ');
                cout << spaces;
            }

            string dash(5, '-');
            cout << "+" << dash;
        }
        cout << "+\n";
    };

    cout << endl << "Total slot kosong: " << peternakan.jumlahSlotKosong() << endl;
};

bool Peternak::cek_slot_peternakan_valid(string slot) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    return peternakan.apakahIndexValid(i,j);
};

bool Peternak::cek_peternakan_penuh() {
    return peternakan.penuh();
};

bool Peternak::cek_peternakan_kosong() {
    return peternakan.kosong();
};

int Peternak::jumlah_slot_efektif_peternakan() {
    return peternakan.jumlahElement();
};

int Peternak::jumlah_slot_kosong_peternakan() {
    return peternakan.jumlahSlotKosong();
};

Matrix<Hewan> Peternak::dapatkan_peternakan() {
    return peternakan;
};

void Peternak::ternak() {
    if (peti.kosong()) {
        cout << "Gak punya penyimpanan kok mau ternak!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_peternakan;
        int idxRowPeti, idxColPeti, idxRowPeternakan, idxColPeternakan;
        Entitas* bibit = nullptr;

        while (true) {
            cout << "Silakan pilih hewan yang ingin Anda ternak!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (!cek_slot_peti_valid(slot_masukan_peti)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti.dapatkanElemen(idxRowPeti, idxColPeti);
                if (!Util::instanceof<Hewan>(bibit)) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi bibit hewan." << endl;
                }
                else{
                    cout << "Kamu memilih " << bibit->dapatkan_nama() << " untuk dipelihara." << endl;
                    break;
                }
            }
        }

        cetak_peternakan();

        while (true) {
            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peternakan;

            if (!cek_slot_peti_valid(slot_masukan_peternakan)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeternakan = Util::indeks_baris_slot(slot_masukan_peternakan);
                idxColPeternakan = Util::indeks_kolom_slot(slot_masukan_peternakan);

                shared_ptr<Hewan> kandang(peternakan.dapatkanElemen(idxRowPeternakan, idxColPeternakan));

                if(kandang){
                    cout << "Slot " << slot_masukan_peti << " milik hewan lain." << endl;
                }
                else{
                    // peternakan[idxRowPeternakan][idxColPeternakan] = make_shared<Karnivora>(hewanBibit);
                    Hewan* hewanPtr = dynamic_cast<Hewan*>(bibit);
                    tambah_peternakan(slot_masukan_peternakan, hewanPtr);
                    bibit = peti.hapus(idxRowPeti, idxColPeti);
                    cout << "Ternak, ternak, ternak yang banyak!" << endl;
                    cout << bibit->dapatkan_nama() << " berhasil diternak!" << endl;
                    break;
                }
            }
        }
    };
};

void Peternak::tambah_peternakan(string slot, Hewan* val) {
    int i = Util::indeks_baris_slot(slot);
    int j = Util::indeks_kolom_slot(slot);

    if (peternakan.apakahSlotKosong(i,j)) {
        peternakan.editElemen(i, j, val);
    }
    else {
        cout << "Ada isinya" << endl;
    }
};

Hewan* Peternak::hapus_peternakan(string slot) {
    int idxRow = Util::indeks_baris_slot(slot);
    int idxCol = Util::indeks_kolom_slot(slot);


    return peternakan.hapus(idxRow, idxCol);
};

void Peternak::beri_pangan() {
    if (cek_peternakan_kosong()){
        cout << "Kandangnya kosong semua, mau kasih makan setan?" << endl;
    }
    else {
        if(cek_peti_kosong()){
            cout << "Kamu ga punya apa apa, Mau kasih makan pake angin?" << endl;
        }else{
            cetak_peternakan();

            string slot_masukan_peti, slot_masukan_peternakan;
            int idxRowPeti, idxColPeti, idxRowPeternakan, idxColPeternakan;
            Entitas* produk = nullptr;
            Hewan* hewanLapar;

            while (true) {
                cout << "Pilih kandang yang akan dikasih makan" << endl;
                cout << "Petak : ";
                cin >> slot_masukan_peternakan;

                if (!cek_slot_peti_valid(slot_masukan_peternakan)) {
                    cout << "Slot tidak valid" << endl;
                }
                else {
                    idxRowPeternakan = Util::indeks_baris_slot(slot_masukan_peternakan);
                    idxColPeternakan = Util::indeks_kolom_slot(slot_masukan_peternakan);

                    shared_ptr<Hewan> kandang(peternakan.dapatkanElemen(idxRowPeternakan, idxColPeternakan));

                    if(!kandang){
                        cout << "Slot " << slot_masukan_peti << " gak ada hewannya." << endl;
                    }
                    else{
                        hewanLapar = dynamic_cast<Hewan*>(kandang.get());
                        cout << "Kamu memilih " << hewanLapar->dapatkan_nama() << " untuk dikasih makan." << endl;
                        break;
                    }
                }
            }

            cetak_peti();

            while (true){
                cout << "Silakan pilih pangan yang ingin Anda berikan!" << endl;
                cout << "Petak : ";
                cin >> slot_masukan_peti;

                if (!cek_slot_peti_valid(slot_masukan_peti)) {
                    cout << "Slot tidak valid" << endl;
                }
                else {
                    idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                    idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                    produk = peti.dapatkanElemen(idxRowPeti, idxColPeti);
                    if (!Util::instanceof<Produk>(produk)) {
                        cout << "Slot " << slot_masukan_peti << " tidak berisi makanan." << endl;
                    }
                    else if (Util::instanceof<ProdukTanamanMaterial>(produk)){
                        cout << "Slot " << slot_masukan_peti << " berisi produk tanaman material yang tidak bisa dimakan." << endl;
                    }
                    else{
                        Produk* makanan = dynamic_cast<Produk*>(produk);
                        if(Util::instanceof<Omnivora>(hewanLapar)){
                            hewanLapar->tambah_berat(makanan->dapatkan_berat_tambahan());
                        }
                        else if(Util::instanceof<Karnivora>(hewanLapar)){
                            if (Util::instanceof<ProdukHewan>(makanan)){
                                hewanLapar->tambah_berat(makanan->dapatkan_berat_tambahan());
                            }
                        }
                        else{
                            if (Util::instanceof<ProdukTanamanBuah>(makanan)){
                                hewanLapar->tambah_berat(makanan->dapatkan_berat_tambahan());
                            }
                        }
                        cout << "Kamu memilih " << hewanLapar->dapatkan_nama() << " untuk ditanam." << endl;
                    }
                    
                    break;
                }
            }
        }
    };
};

void Peternak::panen() {
    cetak_peternakan();
};

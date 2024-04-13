#include "Petani.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <utility>
#include <cmath>
#include <tuple>

Petani::Petani(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti, tuple<int, int> ukuran_ladang) : Pemain(nama, uang, berat_badan, ukuran_peti), ladang(get<0>(ukuran_ladang), get<1>(ukuran_ladang)) {}

Petani::~Petani() {};

void Petani::cetak_ladang() {
    int numRow = ladang.dapatkanBaris();
    int numCol = ladang.dapatkanKolom();
    // int emptySlot = 0;

    // dapatkan label terpanjang
    int maxLengthRowCode = Util::label_baris_tabel(numRow).length();
    int maxLengthColCode = Util::label_kolom_tabel(numCol).length();

    // Cetak judul tabel
    cout << "    ================[ Ladang ]==================\n\n";

    // label kolom
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
            if (ladang.apakah_slot_kosong(n - 1, m)) {
                cout << "     |";
                // emptySlot++;
            }
            else {
                shared_ptr<Tanaman> val = ladang.dapatkan_elemen(n - 1, m);
                if (val.get()->bisa_panen()) {
                    cout << " ";

                    print_green(val.get()->dapatkan_kode_huruf());

                    cout << " |";
                }
                else {
                    cout << " ";

                    print_red(val.get()->dapatkan_kode_huruf());

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

    // cout << endl << "Total slot kosong: " << ladang.jumlah_slot_kosong() << endl;
};

// bool Petani::cek_ladang_penuh() {
//     return ladang.penuh();
// };

// bool Petani::cek_ladang_kosong() {
//     return ladang.kosong();
// };

// int Petani::jumlah_slot_efektif_ladang() {
//     return ladang.jumlahElement();
// };

// int Petani::jumlah_slot_kosong_ladang() {
//     return ladang.jumlah_slot_kosong();
// };

Matrix<Tanaman> Petani::dapatkan_ladang() {
    return ladang;
};

// bool Petani::cek_slot_ladang_valid(const string& slot) {
//     int i = Util::indeks_baris_slot(slot);
//     int j = Util::indeks_kolom_slot(slot);

//     return ladang.apakah_index_valid(i,j);
// };

void Petani::tanam() {
    if (peti.apakah_kosong()) {
        cout << "Gak punya penyimpanan kok mau tanam!" << endl;
    }
    else {
        cetak_peti();

        string slot_masukan_peti, slot_masukan_ladang;
        int idxRowPeti, idxColPeti, idxRowLadang, idxColLadang;
        shared_ptr<Entitas> bibit;
        shared_ptr<Tanaman> tanamanBibit;

        while (true) {
            cout << "Silakan pilih tanaman yang ingin Anda tanam!" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_peti;

            if (!peti.apakah_slot_valid(slot_masukan_peti)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                idxRowPeti = Util::indeks_baris_slot(slot_masukan_peti);
                idxColPeti = Util::indeks_kolom_slot(slot_masukan_peti);
                bibit = peti.dapatkan_elemen(idxRowPeti, idxColPeti);
                if (!Util::instanceof<Tanaman>(bibit.get())) {
                    cout << "Slot " << slot_masukan_peti << " tidak berisi tanaman." << endl;
                }
                else{
                    cout << "Kamu memilih " << bibit.get()->dapatkan_nama() << " untuk ditanam." << endl;
                    break;
                }
            }
        }

        cetak_ladang();

        while (true) {
            cout << "Pilih petak tanah yang akan ditanami" << endl;
            cout << "Petak : ";
            cin >> slot_masukan_ladang;

            if (!ladang.apakah_slot_valid(slot_masukan_ladang)) {
                cout << "Slot tidak valid" << endl;
            }
            else {
                if(!ladang.apakah_slot_kosong(slot_masukan_ladang)){
                    cout << "Slot " << slot_masukan_peti << " milik tanaman lain." << endl;
                }
                else{
                    idxColLadang = Util::indeks_baris_slot(slot_masukan_ladang);
                    idxRowLadang = Util::indeks_kolom_slot(slot_masukan_ladang);

                    ladang.tambah_elemen_matriks(idxRowLadang, idxColLadang, dynamic_pointer_cast<Tanaman>(bibit));
                    peti.hapus(idxRowPeti, idxColPeti);
                    cout << "Cangkul, cangkul, cangkul yang dalam!" << endl;
                    cout << tanamanBibit->dapatkan_nama() << " berhasil ditanam!" << endl;
                    break;
                }
            }
        }
    };
};


void Petani::tambah_ladang(string slot, shared_ptr<Tanaman> val) {
    if (ladang.apakah_slot_valid(slot)) {
        int i = Util::indeks_baris_slot(slot);
        int j = Util::indeks_kolom_slot(slot);

        if (ladang.apakah_slot_kosong(slot)) {
            ladang.tambah_elemen_matriks(i, j, val);
        }
        else {
            cout << "Ada isinya" << endl;
        }
    }
    else {
        cout << "index out of bonds" << endl;
    }
}

// Tanaman* Petani::hapus_ladang(string slot) {
//     int idxRow = Util::indeks_baris_slot(slot);
//     int idxCol = Util::indeks_kolom_slot(slot);

//     return ladang.hapus(idxRow, idxCol);
// }

#include <functional> // Untuk menggunakan std::hash

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pair) const {
        // Kombinasi hash dari dua kunci dalam pair
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};


tuple<vector<string>, vector<string>, int> Petani::tampilkanPanen(unordered_map<pair<string,string>, int, pair_hash> frequencyMap){
    // Display the names and frequencies of harvest-ready Tanaman objects
    
    int counter = 1;
    vector<string> nama;
    vector<string> kode;

    // tampilkan kode & nama
    for (const auto& it : frequencyMap) {
        nama.push_back(it.first.second);
        kode.push_back(it.first.first);
        cout << " -> " << it.first.first << " : " << it.first.second << endl;

    }
    cout << "Pilih tanaman siap panen yang kamu miliki:" << endl;
    
    // tampilkan kode & petak
    for (const auto& it : frequencyMap) {
        cout << counter << ". " << it.first.first << " (" << it.second << " petak siap panen)" << endl;
        counter++;

    }
    return make_tuple(kode, nama, counter);
}

void Petani::panen() {
    cetak_ladang();
    unordered_map<pair<string,string>, int, pair_hash> frequencyMap = frekuensi_panen();
    if(frequencyMap.size()!=0){
        auto res = tampilkanPanen(frequencyMap);
        vector<string> kode = get<0>(res);
        vector<string> nama = get<1>(res);
        int counter = get<2>(res);
        bool isNumValid = false;
        int nomor, petak;
        while(!isNumValid){
            bool isJumlahValid = false;
            cout << "Nomor tanaman yang ingin dipanen: ";
            cin >> nomor;
            if(nomor>=counter || nomor <=0){
                cout << "---Masukkan nomor yang valid!---" <<endl;
            }
            while(!isJumlahValid && nomor<counter && nomor>0){
                cout << "Berapa petak yang ingin dipanen: ";
                cin >> petak;
                if (petak<=frequencyMap[make_pair((kode.at(nomor-1)),(nama.at(nomor-1)))] && petak>0){
                    if(peti.jumlah_slot_kosong()>=petak){
                        cout << "Pilih petak yang ingin dipanen: "<<endl;
                        vector<string> succ;
                        int i=0; bool isPetakValid=false;
                        while(i<petak){
                            string slot;
                            cout << "   Petak ke-" << i+1 << " : ";
                            cin >> slot;
                            int row = Util::indeks_baris_slot(slot);
                            int col = Util::indeks_kolom_slot(slot);
                            if(ladang.apakah_index_valid(row,col)){
                                if(!ladang.apakah_slot_kosong(slot)){
                                    if(ladang.dapatkan_elemen(row,col)->bisa_panen()){
                                        if(Util::strComp(nama.at(nomor-1), ladang.dapatkan_elemen(row, col)->dapatkan_nama())){
                                            // hapus dari ladang
                                            // Entitas* tumb = dynamic_cast<Entitas*>(ladang.hapus(row, col).get());
                                            // tambah ke peti penyimpanan
                                            // GAK NGERTI NANTI CEK LAGI
                                            peti.tambah_elemen_matriks(row, col, dynamic_pointer_cast<Entitas>(ladang.hapus(row, col)));
                                            succ.push_back(slot);
                                            i++;
                                            cout<<"----Berhasil----"<<endl;
                                        }else{
                                            cout << "Katanya mau panen " << nama.at(nomor-1) << endl;
                                        }

                                    }else{
                                        cout << "--Itu belum bisa dipanen---"<<endl;
                                    }

                                }else{
                                    cout<<"Kamu ga punya tanaman di situ"<<endl;
                                }
                            }else{
                                cout<<"Weitts kelebihan tu petaknya" << endl;
                            }
                        }
                        cout << petak <<" petak tanaman " << nama.at(nomor-1) << " pada petak ";
                        for(auto &each:succ){
                            cout << each << " " ;
                        }
                        cout << "telah dipanen!" <<endl;
                        isJumlahValid = true;
                        isNumValid = true;
                    }else{
                        cout << "---Penyimpanan kamu ga cukup hey---" << endl;
                        isJumlahValid = true;
                    }
                }else if(petak>frequencyMap[make_pair(kode.at(nomor-1), nama.at(nomor-1))]){
                    cout << "Kamu hanya memiliki " << nama.at(nomor-1) << " sebanyak " << frequencyMap[make_pair(kode.at(nomor-1), nama.at(nomor-1))] << endl;
                }else{
                    if(petak==-1){
                        // kembali ke pemilihan nomor
                        isJumlahValid = true;
                    }else{
                        cout << "---Masukan petak yang valid!--- (-1 for back)"<<endl;
                    }
                }
            }

        }

    }else{
        cout << "Kamu belum punya tanaman siap panen nih, ayo semangat bekerja!" << endl;
    }

}

void Petani::next_umur() {
    if (ladang.apakah_kosong()) return;      // Kalo ladang nya kosong ya udah lah cuk, ga ngapa ngapain
    for (int i = 0; i < this->ladang.dapatkanBaris(); i++) {
        for (int j = 0; j < this->ladang.dapatkanKolom(); j++) {    // Kalo ladang pada petak tertentu tidak kosong (ada tanamannya), maka umur ditambah
            if (this->ladang.dapatkan_elemen(i, j) != nullptr) this->ladang.dapatkan_elemen(i, j)->tambah_umur();   
        }
    }
}

int Petani::hitung_pajak() {
    int KKP, pajak;
    int KTKP = 13;
    int neto_kekayaan = uang;

    if (!ladang.apakah_kosong()) {
        for (int i=0; i<ladang.dapatkanBaris(); i++) {
            for (int j=0; j<ladang.dapatkanKolom(); j++) {
                if (ladang.dapatkan_elemen(i,j) != nullptr) {
                    neto_kekayaan += ladang.dapatkan_elemen(i,j)->dapatkan_harga();
                }
            }
        }
    }

    if (!peti.apakah_kosong()) {
        for (int i=0; i<peti.dapatkanBaris(); i++) {
            for (int j=0; j<peti.dapatkanKolom(); j++) {
                if (peti.dapatkan_elemen(i,j) != nullptr) {
                    neto_kekayaan += peti.dapatkan_elemen(i,j)->dapatkan_harga();
                }
            }
        }
    }

    KKP = neto_kekayaan - KTKP;
    if (KKP <= 0) {
        pajak = 0;
    } else if (KKP <= 6) {
        pajak = round(KKP * 0.05);
    } else if (KKP <= 25) {
        pajak = round(KKP * 0.15);
    } else if (KKP <= 50) {
        pajak = round(KKP * 0.25);
    } else if (KKP <= 500) {
        pajak = round(KKP * 0.3);
    } else {
        pajak = round(KKP * 0.35);
    }

    if (pajak > uang) {
        pajak = uang;
    }

    return pajak;
}
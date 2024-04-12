#include "Peternak.hpp"
#include "../Pcolor/Pcolor.hpp"
#include <cmath>

using namespace std;
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


tuple<vector<string>, vector<string>, int> Peternak::tampilkanPanen(unordered_map<pair<string,string>, int, pair_hash> frequencyMap){
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
    cout << endl << "Pilih hewan siap panen yang kamu miliki:" << endl;
    
    // tampilkan kode & petak
    for (const auto& it : frequencyMap) {
        cout << counter << ". " << it.first.first << " (" << it.second << " petak siap panen)" << endl;
        counter++;

    }
    cout << endl;
    return make_tuple(kode, nama, counter);
}

void Peternak::panen() {
    cetak_peternakan();
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
            cout << "Nomor hewan yang ingin dipanen: ";
            cin >> nomor;
            if(nomor>=counter || nomor <=0){
                cout << "---Masukkan nomor yang valid!---" <<endl;
            }
            while(!isJumlahValid && nomor<counter && nomor>0){
                cout << "Berapa petak yang ingin dipanen: ";
                cin >> petak;
                if (petak<=frequencyMap[make_pair((kode.at(nomor-1)),(nama.at(nomor-1)))] && petak>0){
                    if(peti.jumlahSlotKosong()>=petak){
                        cout << "Pilih petak yang ingin dipanen: "<<endl;
                        vector<string> succ;
                        int i=0; bool isPetakValid=false;
                        while(i<petak){
                            string slot;
                            cout << "   Petak ke-" << i+1 << " : ";
                            cin >> slot;
                            int row = Util::indeks_baris_slot(slot);
                            int col = Util::indeks_kolom_slot(slot);
                            if(peternakan.apakahIndexValid(row,col)){
                                if(!peternakan.apakahSlotKosong(row, col)){
                                    if(peternakan.dapatkanElemen(row,col)->bisa_panen()){
                                        if(Util::strComp(nama.at(nomor-1), peternakan.dapatkanElemen(row, col)->dapatkan_nama())){
                                            // hapus dari peternakan
                                            Entitas* hew = dynamic_cast<Entitas*>(this->peternakan.hapus(row, col));
                                            // tambah ke peti penyimpanan
                                            tambah_peti(slot, hew);
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
        cout << "Kamu belum punya hewan siap panen nih, ayo semangat bekerja!" << endl;
    }

}


int Peternak::hitung_pajak() {
    int KKP, pajak;
    int KTKP = 11;
    int neto_kekayaan = uang;

    if (!cek_peternakan_kosong()) {
        for (int i=0; i<peternakan.dapatkanBaris(); i++) {
            for (int j=0; j<peternakan.dapatkanKolom(); j++) {
                if (peternakan.dapatkanElemen(i,j) != nullptr) {
                    neto_kekayaan += peternakan.dapatkanElemen(i,j)->dapatkan_harga();
                }
            }
        }
    }

    if (!cek_peti_kosong()) {
        for (int i=0; i<peti.dapatkanBaris(); i++) {
            for (int j=0; j<peti.dapatkanKolom(); j++) {
                if (peti.dapatkanElemen(i,j) != nullptr) {
                    neto_kekayaan += peti.dapatkanElemen(i,j)->dapatkan_harga();
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

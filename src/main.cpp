#include "./ManajerPermainan/ManajerPermainan.hpp"

int main() {
    ManagerPermainan mp("../config");

    string input;
    cout << "██████╗  ██████╗███╗   ██╗" << endl;
    cout << "██╔══██╗██╔════╝████╗  ██║" << endl;
    cout << "██████╔╝██║     ██╔██╗ ██║" << endl;
    cout << "██╔══██╗██║     ██║╚██╗██║" << endl;
    cout << "██████╔╝╚██████╗██║ ╚████║" << endl;
    cout << "╚═════╝  ╚═════╝╚═╝  ╚═══╝" << endl;

    cout << "Selamat datang di permainan Kelola Kerajaan Bersama Labpro!\n\n";

    while (true) {
        cout << "Apakah Anda ingin memuat state? (y/n) ";
        cin >> input;
        cout << endl;

        if (input == "y") {
            mp.muat();
            break;
        }
        else if (input == "n") {
            cout << "Inisialisasi pemain..." << endl;
            mp.inisialisasi_pemain();
            cout << "Berhasil menginisialisasi pemain Petani1, Peternak1, dan Walikota\n\n";
            break;
        }
        
        cout << "Ngomong apa si, coba masukkin ulang dah\n\n";
    }

    cout << "Permainan sudah dapat dimulai! Selamat bermain!!" << endl;
    while (true) {
        cout << "Pemain saat ini: " << mp.pemain_skrg()->dapatkan_nama() << endl;
        cout << "> ";
        cin >> input;


        if (input == "NEXT") {
            cout << "Pemain " << mp.pemain_skrg()->dapatkan_nama() << " mengakhiri gilirannya" << endl;
            mp.next();
            cout << "Giliran dilanjut ke pemain " << mp.pemain_skrg()->dapatkan_nama() << endl << endl;
        }
        else if (input == "CETAK_PENYIMPANAN") {
            mp.pemain_skrg()->cetak_peti();
        }
        else if (input == "PUNGUT_PAJAK") {

        }
        else if (input == "SIMPAN") {
            mp.simpan();
        }
        else if (input == "KELUAR") {
            cout << "Terima kasih telah bermain!" << endl;
            break;
        }
        else {
            cout << "Command apa itu? Coba masukin command lain\n";
        }

        cout << endl;
    }

    return 0;
}
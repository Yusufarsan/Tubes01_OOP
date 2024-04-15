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

        try {
            if (Util::strComp(input,"Y")) {
                mp.muat();
                break;
            }
            else if (Util::strComp(input, "N")) {
                cout << "Inisialisasi pemain..." << endl;
                mp.inisialisasi_pemain();
                cout << "Berhasil menginisialisasi pemain Petani1, Peternak1, dan Walikota\n\n";
                break;
            }
            
            cout << "Ngomong apa si, coba masukkin ulang dah\n";
        } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        }
        catch (...) {
            cout << "Terjadi kesalahan dalam memuat state. Silakan coba lagi." << endl;
        }
        cout << endl;
    }

    cout << "Permainan sudah dapat dimulai! Selamat bermain!!" << endl;
    while (true) {
        cout << "Pemain saat ini: " << mp.pemain_skrg()->dapatkan_nama() << endl;
        cout << "> ";
        cin >> input;

        try {
            if (Util::strComp(input, "NEXT")){
                cout << "Pemain " << mp.pemain_skrg()->dapatkan_nama() << " mengakhiri gilirannya" << endl;
                mp.next();
                cout << "Giliran dilanjut ke pemain " << mp.pemain_skrg()->dapatkan_nama() << endl << endl;
            }
            else if (Util::strComp(input, "CETAK_PENYIMPANAN")) {
                mp.cetak_penyimpanan();
            }
            else if (Util::strComp(input, "PUNGUT_PAJAK")) {
                mp.pungut_pajak();  
            }
            else if (Util::strComp(input, "CETAK_LADANG")) {
                mp.cetak_ladang();
            }
            else if (Util::strComp(input, "CETAK_PETERNAKAN")) {
                mp.cetak_peternakan();
            }
            else if (Util::strComp(input, "TANAM")) {
                mp.tanam();
            }
            else if (Util::strComp(input, "TERNAK")) {
                mp.ternak();
            }
            else if (Util::strComp(input, "BANGUN")) {
                mp.bangun();
            }
            else if(Util::strComp(input, "TAMBAH_PEMAIN")){
                mp.tambah_pemain();
            }
            else if (Util::strComp(input, "MAKAN")) {
                mp.makan();
            }
            else if (Util::strComp(input, "KASIH_MAKAN")) {
                mp.kasih_makan();
            }
            else if (Util::strComp(input, "BELI")) {
                mp.beli();
            }
            else if (Util::strComp(input, "JUAL")) {
                mp.jual();
            }
            else if (Util::strComp(input, "PANEN")) {
                mp.panen();
            }
            else if (Util::strComp(input, "SIMPAN")) {
                mp.simpan();
            }
            else if (Util::strComp(input, "KELUAR")) {
                mp.keluar();
                break;
            }else if(Util::strComp(input, "INFO")){
                mp.info_pemain();
            }else if(Util::strComp(input, "HELP")){
                mp.help();
            }
            else {
                cout << "Command apa itu? Coba masukin command lain yg ada di spek\n";
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        // catch (const Saad& e) {     // NANTI LENGKAPIN SEMUA EXCEPTION NYA DISINI
        //     cout << e.what() << endl;
        // }
        // catch (const Iki& e) {
        //     cout << e.what() << endl;
        // }
        // catch (const Dapur& e) {
        //     cout << e.what() << endl;
        // }
        // catch (const Ucup& e) {
        //     cout << e.what() << endl;
        // }
        catch (...) {           // INI KAYAK ELSE NYA EXCEPTION BAGI GW, jadi kalo ada case yg bocor, masuknya kesini   
            cout << "Terjadi kesalahan dalam menjalankan command. Silakan coba lagi." << endl;
        }

        cout << endl;
    }
    
    return 0;
}
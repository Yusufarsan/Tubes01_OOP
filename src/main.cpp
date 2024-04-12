#include "./ManajerPermainan/ManajerPermainan.hpp"

int main() {
    ManagerPermainan mp("../config");

    string input;

    cout << "Apakah Anda ingin memuat state? (y/n) ";
    // cin >> input;
    input = "y";

    if (input == "y") {
        mp.muat();
    }

    cout << "> ";
    // cin >> input;
    input = "SIMPAN";

    if (input == "SIMPAN") {
        mp.simpan();
    }


    return 0;
}
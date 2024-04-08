#include <iostream>
#include "./ManajerPermainan/ManajerPermainan.hpp"

using namespace std;

int main() {
    ManagerPermainan mp = ManagerPermainan("../config");

    mp.print_konfigurasi();
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

void tambahMap(map<string,int>& coba, string nama, int nomor){
    coba[nama] ++;
}

int main() {
    map<string, int> coba;

    // coba[20] = "ayam"; 
    // coba[10] = "bebek"; 
    // coba[5] = "sapi"; 
    // coba[2] = "kuda"; 

    tambahMap(coba, "ucup", 4);
    tambahMap(coba, "ucup", 4);
    tambahMap(coba, "ihsan", 3);
    tambahMap(coba, "saya", 1);
    tambahMap(coba, "laki", 2);

    for (const auto& pair : coba) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}

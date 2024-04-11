#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string input;
    cout << "Masukkan petak (contoh: A01, A02): ";
    getline(cin, input); // Membaca satu baris input dari pengguna

    vector<string> petak;

    istringstream iss(input);
    string token;
    while (getline(iss, token, ',')) { // Memisahkan string berdasarkan koma
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        petak.push_back(token); // Menambahkan token ke dalam vektor
    }

    // Menampilkan petak-petak yang telah dipisahkan
    cout << "Petak yang dimasukkan:" << endl;
    for (const string& p : petak) {
        cout << p << endl;
    }

    return 0;
}

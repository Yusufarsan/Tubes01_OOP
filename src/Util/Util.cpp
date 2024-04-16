#include "Util.hpp"
#include <random>

// String manipulation
vector<string> Util::SplitString(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void Util::ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
        }));
}

void Util::rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
        }).base(), s.end());
}

void Util::trim(string& s) {
    ltrim(s);
    rtrim(s);
}

// Fungsi untuk membandingkan dua string secara case insensitive
bool Util::strComp(const std::string& str1, const std::string& str2) {
    // Jika panjang kedua string tidak sama, maka string tidak sama
    if (str1.length() != str2.length()) {
        return false;
    }

    // Membandingkan karakter per karakter
    for (size_t i = 0; i < str1.length(); ++i) {
        // Mengonversi kedua karakter menjadi huruf kecil sebelum membandingkannya
        if (std::tolower(str1[i]) != std::tolower(str2[i])) {
            return false; // Jika ada karakter yang tidak sama, string tidak sama
        }
    }

    // Jika semua karakter sama, string sama
    return true;
}

// Matrix label conversion
string Util::label_baris_tabel(int indeks) {
    string nama_kolom;
    indeks += 11;

    while (indeks > 0) {
        nama_kolom = char('0' + (indeks - 1) % 10) + nama_kolom;
        indeks = (indeks - 1) / 10;
    }

    return nama_kolom;
}

string Util::label_kolom_tabel(int indeks) {
    string nama_kolom;

    while (indeks > 0) {
        nama_kolom = char('A' + (indeks - 1) % 26) + nama_kolom;
        indeks = (indeks - 1) / 26;
    }

    return nama_kolom;
}

string Util::label_slot_tabel(int baris, int kolom) {
    return label_kolom_tabel(kolom + 1) + label_baris_tabel(baris + 1);
}

int Util::indeks_baris_slot(const string& slot) {
    size_t pos = slot.find_first_of("0123456789");

    string nama_kolom = slot.substr(pos);

    return stoi(nama_kolom) - 1;
};

int Util::indeks_kolom_slot(const string& slot) {
    size_t pos = slot.find_first_of("0123456789");

    string nama_baris = slot.substr(0, pos);

    int index = 0;
    for (char c : nama_baris) {
        if (isalpha(c)) {
            index = index * 26 + (toupper(c) - 'A' + 1);
        }
    }
    return index - 1;
};

bool Util::apakah_vokal(char c) {
    // Mengubah huruf menjadi huruf kecil untuk memudahkan perbandingan
    c = std::tolower(c);

    // Mengecek apakah karakter merupakan vokal
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string Util::dapatkan_kode(string nama) {
    string kode;

    kode += nama[0];
    for (size_t i = 1; i < nama.length(); i++) {
        if (isalpha(nama[i])) {
            if (nama.length() > 3) {
                if (apakah_vokal(nama[i])) {
                    kode += toupper(nama[i + 1]);
                }
                else {
                    kode += toupper(nama[i]);
                }
            }
            else {
                kode += nama[1];
            }
            break;
        }
    }

    return kode;
}

int Util::angka_acak(int awal, int akhir) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(awal, akhir);
    return dis(gen);
}

string Util::dapatkan_nama_tumb(string nama) {
    // Mencari posisi _TREE dalam string
    size_t pos = nama.find("_TREE");

    // Jika _TREE tidak ditemukan atau berada di awal string, kembalikan string kosong
    if (pos == std::string::npos || pos == 0) {
        return "";
    }

    // Ambil substring sebelum _TREE
    return nama.substr(0, pos);

}

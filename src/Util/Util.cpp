#include "Util.hpp"

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

string Util::label_baris_tabel(int indeks){
    string nama_kolom;
    indeks += 11;

    while (indeks > 0){
        nama_kolom = char('0' + (indeks-1) % 10) + nama_kolom;
        indeks = (indeks - 1) / 10;
    }

    return nama_kolom;
}

string Util::label_kolom_tabel(int indeks){
    string nama_kolom;

    while (indeks > 0) {
        nama_kolom = char('A' + (indeks - 1) % 26) + nama_kolom;
        indeks = (indeks - 1) / 26;
    }

    return nama_kolom;
}

int Util::indeks_baris_slot(const string& slot){
    size_t pos = slot.find_first_of("0123456789");

    string nama_kolom = slot.substr(pos);

    return stoi(nama_kolom) - 1;
};

int Util::indeks_kolom_slot(const string& slot){
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
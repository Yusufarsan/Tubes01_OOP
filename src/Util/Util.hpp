#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Util {
public:
    static vector<string> SplitString(string str, string delimiter);

    static string label_baris_tabel(int indeks);
    static string label_kolom_tabel(int indeks);
    static int indeks_baris_slot(const string& nama_baris);
    static int indeks_kolom_slot(const string& nama_kolom);
};

#endif
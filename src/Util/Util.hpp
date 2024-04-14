#ifndef UTIL_HPP
#define UTIL_HPP

// STL
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Util {
public:
    // String manipulation
    static vector<string> SplitString(string str, string delimiter);
    static void ltrim(string& s);
    static void rtrim(string& s);
    static void trim(string& s);
    static bool strComp(const std::string& str1, const std::string& str2);
    static bool apakah_vokal(char c);

    // Matrix label conversion
    static string label_baris_tabel(int indeks);
    static string label_kolom_tabel(int indeks);
    static string label_slot_tabel(int baris, int kolom);
    static int indeks_baris_slot(const string& nama_baris);
    static int indeks_kolom_slot(const string& nama_kolom);

    // Type checking
    template<typename Base, typename T>
    static inline bool instanceof(const T* ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }


    // Generator
    static string dapatkan_kode(string nama);
    static int angka_acak(int awal, int akhir);
    static string dapatkan_nama_tumb(string nama);
};

#endif
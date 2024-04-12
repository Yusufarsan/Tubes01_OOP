#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Util {
public:
    static vector<string> SplitString(string str, string delimiter);
    static void ltrim(string& s);
    static void rtrim(string& s);
    static void trim(string& s);

    static string label_baris_tabel(int indeks);
    static string label_kolom_tabel(int indeks);
    static int indeks_baris_slot(const string& nama_baris);
    static int indeks_kolom_slot(const string& nama_kolom);

    template<typename Base, typename T>
    static inline bool instanceof(const T* ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
    static bool strComp(const std::string& str1, const std::string& str2);
};

#endif
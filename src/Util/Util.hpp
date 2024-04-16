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

    /**
     * @brief Membagi string berdasarkan delimiter
     *
     * @param str
     * @param delimiter
     * @return vector<string>
     */
    static vector<string> SplitString(string str, string delimiter);

    /**
     * @brief Menghapus whitespace di sebelah kiri string
     *
     * @param s
     */
    static void ltrim(string& s);

    /**
     * @brief Menghapus whitespace di sebelah kanan string
     *
     * @param s
     */
    static void rtrim(string& s);

    /**
     * @brief Menghapus whitespace di kedua sisi string
     *
     * @param s
     */
    static void trim(string& s);

    /**
     * @brief Membandingkan dua string
     *
     * @param str1
     * @param str2
     * @return true
     * @return false
     */
    static bool strComp(const std::string& str1, const std::string& str2);

    /**
     * @brief Mengecek apakah karakter adalah huruf vokal
     *
     * @param c
     * @return true
     * @return false
     */
    static bool apakah_vokal(char c);

    // Matrix label conversion

    /**
     * @brief Mengembalikan label baris tabel
     *
     * @param indeks
     * @return string
     */
    static string label_baris_tabel(int indeks);

    /**
     * @brief Mengembalikan label kolom tabel
     *
     * @param indeks
     * @return string
     */
    static string label_kolom_tabel(int indeks);

    /**
     * @brief Mengembalikan label slot tabel
     *
     * @param baris
     * @param kolom
     * @return string
     */
    static string label_slot_tabel(int baris, int kolom);

    /**
     * @brief Mengembalikan indeks baris slot
     *
     * @param nama_baris
     * @return int
     */
    static int indeks_baris_slot(const string& nama_baris);

    /**
     * @brief Mengembalikan indeks kolom slot
     *
     * @param nama_kolom
     * @return int
     */
    static int indeks_kolom_slot(const string& nama_kolom);

    // Type checking
    template<typename Base, typename T>
    /**
     * @brief
     *
     * @param ptr
     * @return true
     * @return false
     */
    static inline bool instanceof(const T* ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }


    // Generator

    /**
     * @brief Mengembalikan kode dari nama
     *
     * @param nama
     * @return string
     */
    static string dapatkan_kode(string nama);

    /**
     * @brief Mengembalikan angka acak dalam rentang tertentu
     *
     * @param awal
     * @param akhir
     * @return int
     */
    static int angka_acak(int awal, int akhir);

    /**
     * @brief Mengembalikan nama tumbuhan dari nama produk
     *
     * @param nama
     * @return string
     */
    static string dapatkan_nama_tumb(string nama);
};

#endif
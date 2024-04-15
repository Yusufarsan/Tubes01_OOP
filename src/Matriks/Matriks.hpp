#ifndef MATRIKS_HPP
#define MATRIKS_HPP


// STL
#include <vector>
#include <iostream>
#include <memory>

// User-defined
#include "../Util/Util.hpp"
#include "../Exception/ExceptionMatrix.hpp"


using namespace std;

template <typename A>
class Matrix {
private:
    vector<vector<shared_ptr<A>>> data;
    int rows;
    int cols;
    int N_element;

public:
    // Constructor & Destructor

    /**
     * @brief Construct a new Matrix object
     *
     * @param rows
     * @param cols
     */
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Initialize the matrix with zeros
        data.assign(rows, vector<shared_ptr<A>>(cols, nullptr));
        N_element = 0;
    }

    /**
     * @brief Destroy the Matrix object
     *
     */
    ~Matrix() {}

    /**
     * @brief Operator overloading untuk menambah element pada slot kosong
     *
     * @param El
     * @return Matrix&
     */
    Matrix& operator+=(shared_ptr<A> El) {
        if (!apakah_penuh()) {
            bool isInserted = false;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (apakah_slot_kosong(i, j)) {
                        tambah_elemen_matriks(i, j, El);
                        isInserted = true;
                        break;
                    }
                }
                if (isInserted) {
                    break;
                }
            }
        }
        else {
            throw tidakBisaTambahElemen(", sudah penuh");
        }

        return *this;
    }

    /**
     * @brief Menambah element pada slot kosong
     *
     * @param val
     */
    void tambah_elemen_matriks(shared_ptr<A> val) {
        if (!apakah_penuh()) {
            bool isInserted = false;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (apakah_slot_kosong(i, j)) {
                        tambah_elemen_matriks(i, j, val);
                        isInserted = true;
                        break;
                    }
                }
                if (isInserted) {
                    break;
                }

            }
        }
        else {
            throw tidakBisaTambahElemen(", sudah penuh");
        }
    }

    /**
     * @brief Menambah element pada kolom dan baris tertentu
     *
     * @param i
     * @param j
     * @param val
     */
    void tambah_elemen_matriks(int i, int j, shared_ptr<A> val) {
        if (!apakah_penuh()) {
            if (apakah_index_valid(i, j)) {
                if (apakah_slot_kosong(i, j)) {
                    data[i][j] = val;
                    N_element += 1;
                }
                else {
                    throw tidakBisaTambahElemen(", sudah terisi");
                }
            }
            else {
                throw aksesTidakValid(i, j);
            }
        }
        else {
            throw tidakBisaTambahElemen(", sudah penuh");
        }
    }

    /**
     * @brief Menghapus element pada baris dan kolom tertentu
     *
     * @param baris
     * @param kolom
     * @return shared_ptr<A>
     */
    shared_ptr<A> hapus(int baris, int kolom) {
        if (apakah_index_valid(baris, kolom)) {
            if (!apakah_slot_kosong(baris, kolom)) {
                shared_ptr<A> delVal = data[baris][kolom];
                data[baris][kolom].reset();
                N_element -= 1;
                return delVal;
            }
        }
        else {
            throw aksesTidakValid(baris, kolom);
        }

        return nullptr;
    }

    /**
     * @brief Mengecek apakah slot valid
     *
     * @param slot
     * @return true
     * @return false
     */
    bool apakah_slot_valid(const string& slot) {
        try {
            int idxRow = Util::indeks_baris_slot(slot);
            int idxCol = Util::indeks_kolom_slot(slot);

            return apakah_index_valid(idxRow, idxCol);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            return false;
        }
    }

    /**
     * @brief Mengecek apakah slot kosong
     *
     * @param idxRow
     * @param idxCol
     * @return true
     * @return false
     */
    bool apakah_slot_kosong(int idxRow, int idxCol) {
        if (apakah_index_valid(idxRow, idxCol)) {
            return data[idxRow][idxCol] == nullptr;
        }

        return false;
    }

    /**
     * @brief Mengecek apakah slot kosong
     *
     * @param slot
     * @return true
     * @return false
     */
    bool apakah_slot_kosong(const string& slot) {
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);

        if (apakah_index_valid(idxRow, idxCol)) {
            return data[idxRow][idxCol] == nullptr;
        }

        return false;
    }

    /**
     * @brief Mengecek apakah index valid
     *
     * @param baris
     * @param kolom
     * @return true
     * @return false
     */
    bool apakah_index_valid(int baris, int kolom) {
        if (baris < 0 || baris >= rows || kolom < 0 || kolom >= cols) {
            return false;
        }
        return true;
    }

    /**
     * @brief Mengembalikan jumlah slot kosong
     *
     * @return int
     */
    int jumlah_slot_kosong() {
        return (rows * cols) - N_element;
    }

    /**
     * @brief Mengecek apakah penuh
     *
     * @return true
     * @return false
     */
    bool apakah_penuh() {
        return jumlah_slot_kosong() == 0;
    }

    /**
     * @brief Mengecek apakah kosong
     *
     * @return true
     * @return false
     */
    bool apakah_kosong() {
        return N_element == 0;
    }

    /**
     * @brief Mengembalikan elemen pada baris dan kolom tertentu
     *
     * @param baris
     * @param kolom
     * @return shared_ptr<A>
     */
    shared_ptr<A> dapatkan_elemen(int baris, int kolom) {
        if (!apakah_index_valid(baris, kolom)) {
            throw aksesTidakValid(baris, kolom);
        }

        return data[baris][kolom];
    }

    /**
     * @brief Mengembalikan ukuran baris dari matriks
     *
     * @return int
     */
    int dapatkanBaris() const {
        return rows;
    }

    /**
     * @brief Mengembalikan ukuran kolom dari matriks
     *
     * @return int
     */
    int dapatkanKolom() const {
        return cols;
    }

    /**
     * @brief Mengembalikan jumlah elemen pada matriks
     *
     * @return int
     */
    int jumlahElement() {
        return N_element;
    }

    /**
     * @brief Mencetak matriks
     *
     */
    void cetak() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!apakah_slot_kosong(i, j)) {
                    cout << data[i][j]->dapatkan_kode_huruf() << " ";
                }
                else {
                    cout << "..." << " ";
                }
            }
            cout << endl;
        }
    }
};

#endif
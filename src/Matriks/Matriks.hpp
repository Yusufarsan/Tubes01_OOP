#ifndef MATRIKS_HPP
#define MATRIKS_HPP

// STL
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

template <typename A>
class Matrix {
private:
    vector<vector<shared_ptr<A>>> data;
    int rows;
    int cols;
    int N_element;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Initialize the matrix with zeros
        data.assign(rows, vector<shared_ptr<A>>(cols, nullptr));
        N_element = 0;
    }

    // Destruktor
    ~Matrix() { //kalo di gw tu dia udh otomatis ngebersiin sndiri si sampahnya
        // for (int i = 0; i < rows; ++i) {
        //     for (int j = 0; j < cols; ++j) {
        //         if(!isSlotKosong(i,j)){
        //             cout << "berhasil menghapus" << data[i][j]->dapatkan_nama();
        //             delete data[i][j];
        //             data[i][j] = nullptr;
        //         }
        //     }
        // }
    }
    // tambahElement pada slot kosong
    Matrix& operator+=(shared_ptr<A> El) {
        if (!apakah_penuh()) {
            bool isInserted = false;

            for(int i = 0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(apakah_slot_kosong(i,j)){
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
            cout << "Ups udah penuh nih" << endl;
        }
        return *this;
    }

    void tambah_elemen_matriks(shared_ptr<A> val) {
        bool isInserted = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (apakah_slot_kosong(i,j)) {
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

    // setElement
    void tambah_elemen_matriks(int i, int j, shared_ptr<A> val) {
        if (!apakah_index_valid(i,j)) {
            cout << "Index out of bounds." << endl;
            return;
        }
        data[i][j] = val;
        N_element+=1;
    }

    // menghapus element objek menjadi nullptr
    shared_ptr<A> hapus(int baris, int kolom){
        if (!apakah_index_valid(baris,kolom)) {
                cout << "Index out of bounds." << endl;
                return nullptr;
        }else{
            if(!apakah_slot_kosong(baris, kolom)){
                shared_ptr<A> delVal = data[baris][kolom];
                data[baris][kolom].reset();
                N_element-=1;
                return delVal ;
            }else{
                return nullptr;
            }
        }
    }

    bool apakah_slot_valid(const string& slot){   
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);
        
        return apakah_index_valid(idxRow, idxCol);
    }

    bool apakah_slot_kosong(int idxRow, int idxCol){        
        if(apakah_index_valid(idxRow, idxCol)){
            return data[idxRow][idxCol] == nullptr;
        }

        return false;
    }

    bool apakah_slot_kosong(const string& slot){
        int idxRow = Util::indeks_baris_slot(slot);
        int idxCol = Util::indeks_kolom_slot(slot);
        
        if(apakah_index_valid(idxRow, idxCol)){
            return data[idxRow][idxCol] == nullptr;
        }

        return false;
    }

    // mengecek apakah index valid
    bool apakah_index_valid(int baris, int kolom){
        return (!(baris < 0 || baris >= rows || kolom < 0 || kolom >= cols));
    }

    // memberikan nilai slot kosong pada matriks
    int jumlah_slot_kosong(){
        return (rows*cols)-N_element;
    }

    bool apakah_penuh(){
        return jumlah_slot_kosong() == 0;
    }

    bool apakah_kosong(){
        return N_element == 0;
    }

    // getElement
    shared_ptr<A> dapatkan_elemen(int baris, int kolom) {
        if (!apakah_index_valid(baris,kolom)) {
            cout << "Index out of bounds." << endl;
            return nullptr; // Return a default value or throw an exception
        }
        return data[baris][kolom];
    }

    // get N row
    int dapatkanBaris() const {
        return rows;
    }

    // get N col
    int dapatkanKolom() const {
        return cols;
    }

    int jumlahElement() {
        return N_element;
    }

    // print
    void cetak() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(!apakah_slot_kosong(i,j)){
                    cout << data[i][j]->dapatkan_kode_huruf() << " ";
                }else{
                    cout << "kosong" << " ";
                }
            }
            cout << endl;
        }
    }
};

#endif
#ifndef MATRIKS_HPP
#define MATRIKS_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename A>
class Matrix {
private:
    vector<vector<A*>> data;
    int rows;
    int cols;
    int N_element;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Initialize the matrix with zeros
        data.assign(rows, vector<A*>(cols, nullptr));
        N_element = 0;
    }

    // Destruktor
    ~Matrix(){ //kalo di gw tu dia udh otomatis ngebersiin sndiri si sampahnya
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

    // setElement
    void editElemen(int i, int j, A* value) {
        if (!apakahIndexValid(i,j)) {
            cout << "Index out of bounds." << endl;
            return;
        }
        data[i][j] = value;
        N_element+=1;
    }

    // menghapus element objek menjadi nullptr
    A* hapus(int baris, int kolom){
        if (!apakahIndexValid(baris,kolom)) {
                cout << "Index out of bounds." << endl;
                return nullptr;
        }else{
            A* el = data[baris][kolom];
            data[baris][kolom] = nullptr;
            N_element-=1;
            return el ;
        }
    }

    // mengecek apakah index valid
    bool apakahIndexValid(int baris, int kolom){
        return (!(baris < 0 || baris >= rows || kolom < 0 || kolom >= cols));
    }

    bool apakahSlotKosong(int baris, int kolom){
        return data[baris][kolom] == nullptr;
    }

    // memberikan nilai slot kosong pada matriks
    int jumlahSlotKosong(){
        return (rows*cols)-N_element;
    }

    bool penuh(){
        return jumlahSlotKosong() == 0;
    }

    bool kosong(){
        return N_element == 0;
    }

    // getElement
    A* dapatkanElemen(int baris, int kolom) {
        if (!apakahIndexValid(baris,kolom)) {
            cout << "Index out of bounds." << endl;
            return nullptr; // Return a default value or throw an exception
        }
        return data[baris][kolom];
    }

    // get N row
    int dapatkanBaris() const{
        return rows;
    }

    // get N col
    int dapatkanKolom() const{
        return cols;
    }

    int jumlahElement(){
        return N_element;
    }

    // print
    void cetak(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(!apakahSlotKosong(i,j)){
                    cout << data[i][j]->dapatkan_nama() << " ";
                }else{
                    cout << "kosong" << " ";
                }
            }
            cout << endl;
        }
    }
};

// #include "Matriks.cpp"

#endif
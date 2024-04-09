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
    void set(int i, int j, A* value) {
        if (!isIndexValid(i,j)) {
            cout << "Index out of bounds." << endl;
            return;
        }
        data[i][j] = value;
        N_element+=1;
    }

    // menghapus element objek menjadi nullptr
    void hapus(int baris, int kolom){
        if (!isIndexValid(baris,kolom)) {
                cout << "Index out of bounds." << endl;
                return;
            }
        // delete data.at(baris).at(kolom);
        data.at(baris).at(kolom) = nullptr;
        N_element-=1;
    }

    // mengecek apakah index valid
    bool isIndexValid(int baris, int kolom){
        return (!(baris < 0 || baris >= rows || kolom < 0 || kolom >= cols));
    }

    bool isSlotKosong(int baris, int kolom){
        return data[baris][kolom] == nullptr;
    }

    // memberikan nilai slot kosong pada matriks
    int slotKosong(){
        return (rows*cols)-N_element;
    }

    // getElement
    A* get(int baris, int kolom) {
        if (!isIndexValid(baris,kolom)) {
            cout << "Index out of bounds." << endl;
            return nullptr; // Return a default value or throw an exception
        }
        return data[baris][kolom];
    }

    // get N row
    int getRow() const{
        return rows;
    }

    // get N col
    int getCol() const{
        return cols;
    }

    int jumlahElement(){
        return N_element;
    }

    // print
    void print(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(!isSlotKosong(i,j)){
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
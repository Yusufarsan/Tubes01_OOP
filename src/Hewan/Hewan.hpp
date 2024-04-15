#ifndef HEWAN_HPP
#define HEWAN_HPP

// STL
#include <iostream>

// User-defined
#include "../Entitas/Entitas.hpp"
#include "../Produk/Produk.hpp"

class Hewan : public Entitas {
protected:
    int berat_panen;
    int berat;
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Hewan object
     * 
     * @param id 
     * @param kode_huruf (Contoh: CHK = Chicken)
     * @param nama 
     * @param harga 
     * @param berat_panen 
     */
    Hewan(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
    
    /**
     * @brief Construct a new Hewan object
     * 
     * @param other 
     */
    Hewan(Hewan& other); // cctor
    
    /**
     * @brief Destroy the Hewan object
     * 
     */
    virtual ~Hewan(); // dtor
    
    /**
     * @brief Men-assign nilai dari objek lain ke objek yang sudah ada
     * 
     * @param other 
     * @return Hewan& 
     */
    Hewan& operator=(const Hewan& other); // operator =

    // Getter & Setter
    
    /**
     * @brief Mengembalikan berat dari hewan
     * 
     * @return int 
     */
    int dapatkan_berat(); // getter
    
    /**
     * @brief Mengembalikan berat panen dari hewan
     * 
     * @return int 
     */
    int dapatkan_berat_panen();
    
    /**
     * @brief Mengatur berat hewan
     * 
     * @param berat 
     */
    void atur_berat(int berat); // setter

    // Method
    
    /**
     * @brief Menambahkan berat hewan
     * 
     * @param num 
     */
    void tambah_berat(int num); // increment berat
    
    /**
     * @brief Mengecek apakah hewan bisa panen atau tidak
     * 
     * @return true 
     * @return false 
     */
    bool bisa_panen();

    // Command

    /**
     * @brief Virtual method untuk melakukan command makan
     * 
     * @param makanan 
     */
    virtual void makan(Produk* makanan) = 0;

    // Print Info

    /**
     * @brief Method untuk menampilkan info hewan
     * 
     */
    void print_info();
};

#endif
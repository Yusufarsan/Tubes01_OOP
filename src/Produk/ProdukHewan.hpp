#ifndef PRODUKHEWAN_HPP
#define PRODUKHEWAN_HPP

// User-defined
#include "Produk.hpp"
#include "../Util/Util.hpp"

class ProdukHewan : public Produk {
public:
    // 4 Sekawan

    /**
     * @brief Construct a new Produk Hewan object
     * 
     * @param id 
     * @param kode_huruf (Contoh: APP = Apple)
     * @param nama 
     * @param harga 
     * @param berat_tambahan 
     * @param origin 
     */
    ProdukHewan(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin); // ctor
    
    /**
     * @brief Construct a new Produk Hewan object
     * 
     * @param origin 
     * @param berat 
     * @param harga 
     */
    ProdukHewan(string origin, int berat, int harga): Produk(origin+"_MEAT", Util::dapatkan_kode(origin)+"M", origin, berat, harga){};
    
    ProdukHewan(string origin, int berat, int harga, bool isTelur): Produk(origin+"_EGG", Util::dapatkan_kode(origin)+"E", origin, berat, harga){};
    
    /**
     * @brief Destroy the Produk Hewan object
     * 
     */
    ~ProdukHewan(); // dtor

    /**
     * @brief Construct a new Produk Hewan object
     * 
     * @param other 
     */
    ProdukHewan(const ProdukHewan& other); // cctor

    /**
     * @brief Men-assign objek produk hewan dengan produk hewan lain
     * 
     * @param other 
     * @return ProdukHewan& 
     */
    ProdukHewan& operator=(const ProdukHewan& other); // operator=

    // Print Info

    /**
     * @brief Menampilkan info produk hewan
     * 
     */
    void print_info(); // print info
};

#endif
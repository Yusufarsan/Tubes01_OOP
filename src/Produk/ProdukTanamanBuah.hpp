#include "Produk.hpp"

class ProdukTanamanBuah : public Produk {
    public:
        ProdukTanamanBuah(string id, string kode_huruf, string nama, int harga, int berat_tambahan, string origin):Produk(id, kode_huruf, nama, harga, berat_tambahan, origin){}; // ctor
        ~ProdukTanamanBuah(); // dtor
        ProdukTanamanBuah(const ProdukTanamanBuah& other); // cctor
        ProdukTanamanBuah& operator=(const ProdukTanamanBuah& other); // operator=
        
        void print_info(); // print info
};
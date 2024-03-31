#include "Produk.hpp"

class ProdukTanamanBuah : Produk {
    public:
        ProdukTanamanBuah(int berat_tambahan, string origin); // ctor
        ~ProdukTanamanBuah(); // dtor
        ProdukTanamanBuah(const ProdukTanamanBuah& other); // cctor
        ProdukTanamanBuah& operator=(const ProdukTanamanBuah& other); // operator=
        
        void print_info(); // print info
};
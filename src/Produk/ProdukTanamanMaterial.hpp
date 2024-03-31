#include "Produk.hpp"

class ProdukTanamanMaterial : Produk {
    public:
        ProdukTanamanMaterial(int berat_tambahan, string origin); // ctor
        ~ProdukTanamanMaterial(); // dtor
        ProdukTanamanMaterial(const ProdukTanamanMaterial& other); // cctor
        ProdukTanamanMaterial& operator=(const ProdukTanamanMaterial& other); // operator=
        
        void print_info(); // print info
};
#include "Produk.hpp"

class ProdukHewan : Produk {
    public:
        ProdukHewan(int berat_tambahan, string origin); // ctor
        ~ProdukHewan(); // dtor
        ProdukHewan(const ProdukHewan& other); // cctor
        ProdukHewan& operator=(const ProdukHewan& other); // operator=
        
        void print_info(); // print info
};
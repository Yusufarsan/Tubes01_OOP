#include "Hewan.hpp"
#include "../Produk/Produk.hpp"

class Herbivora: public Hewan {
    private:

    public:
        Herbivora(string id, string kode_huruf, string nama, int harga, int berat_panen); // ctor (default berat = 0)
        Herbivora(Herbivora &other); // cctor
        ~Herbivora(); // dtor
        Herbivora& operator=(const Herbivora &other); // operator =

        void makan(Produk *makanan);

};
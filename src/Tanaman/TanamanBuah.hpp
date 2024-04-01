#include "Tanaman.hpp"

class TanamanBuah: public Tanaman {
    protected:
    public:
        TanamanBuah(int umur_panen); // ctor
        TanamanBuah(TanamanBuah &other); // cctor
        ~TanamanBuah(); // dtor
        TanamanBuah operator=(const TanamanBuah &other); // operator =
};
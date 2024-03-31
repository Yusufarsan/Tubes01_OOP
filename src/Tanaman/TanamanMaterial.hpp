#include "Tanaman.hpp"

class TanamanMaterial: public Tanaman {
    protected:
    public:
        TanamanMaterial(int umur_panen); // ctor
        TanamanMaterial(TanamanMaterial &other); // cctor
        ~TanamanMaterial(); // dtor
        TanamanMaterial operator=(const TanamanMaterial &other); // operator =
}
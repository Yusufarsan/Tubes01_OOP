#include "Hewan.hpp"

class Herbivora: public Hewan {
    private:

    public:
        Herbivora(int berat_panen); // ctor (default berat = 0)
        Herbivora(Herbivora &other); // cctor
        ~Herbivora(); // dtor
        Herbivora operator=(const Herbivora &other); // operator =

        void makan();
};
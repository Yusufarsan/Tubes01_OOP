#include "Hewan.hpp"

class Omnivora: public Hewan {
    private:

    public:
        Omnivora(int berat_panen); // ctor (default berat = 0)
        Omnivora(Omnivora &other); // cctor
        ~Omnivora(); // dtor
        Omnivora operator=(const Omnivora &other); // operator =

        void makan();
};
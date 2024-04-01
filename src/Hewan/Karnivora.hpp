#include "Hewan.hpp"

class Karnivora: public Hewan {
    private:

    public:
        Karnivora(int berat_panen); // ctor (default berat = 0)
        Karnivora(Karnivora &other); // cctor
        ~Karnivora(); // dtor
        Karnivora operator=(const Karnivora &other); // operator =

        void makan();
};
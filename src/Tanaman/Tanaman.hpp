#include <iostream>
#include "../Entitas/Entitas.hpp"

class Tanaman: public Entitas {
    protected:
        const int umur_panen;
        int umur;
    public:
        Tanaman(int umur_panen); // ctor (default umur = 0)
        Tanaman(Tanaman &other); // cctor
        ~Tanaman(); // dtor
        Tanaman operator=(const Tanaman &other); // operator =

        int dapatkan_umur(); // getter
        int dapatkan_umur_panen();
        void tambah_umur(); // increment umur
        bool bisa_panen(); 
}
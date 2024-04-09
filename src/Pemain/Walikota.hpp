#include "Pemain.hpp"

class Walikota : public Pemain {
public:
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor
    Walikota(const Walikota& other); // cctor
    ~Walikota(); // dtor


    void tagih_pajak();
    void bangun();
    void tambah_petani(string nama);
    void tambah_peternak(string nama);
};
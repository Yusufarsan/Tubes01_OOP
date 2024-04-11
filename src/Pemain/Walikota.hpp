#include "Pemain.hpp"

class Walikota : public Pemain {
public:
    
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor
    Walikota(const Walikota& other); // cctor
    ~Walikota(); // dtor


    void tagihPajak();
    void bangun();
    void tambahPemain(vector<shared_ptr<Pemain>>* daftarPemain, tuple<int,int> ukuranPenyimpanan, int beratAwal, tuple<int, int> besar_lahan, tuple<int, int> besar_peternakan);

};
#include "Pemain.hpp"

class Walikota : public Pemain {
public:
    Walikota(string nama, int uang, int berat_badan, tuple<int, int> ukuran_peti); // ctor
    Walikota(const Walikota& other); // cctor
    ~Walikota(); // dtor

    bool bandingkan_pajak(const std::shared_ptr<Pemain>& a, const std::shared_ptr<Pemain>& b);

    static void tagih_pajak(vector<shared_ptr<Pemain>>);
    void bangun();
    void tambah_petani(string nama);
    void tambah_peternak(string nama);
};
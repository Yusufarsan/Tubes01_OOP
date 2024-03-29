#include <iostream>
using namespace std;

class Entitas {      // ABC

};

class Produk : Entitas {      // ABC
    private:
        int berat_tambahan;
        string origin;
    public:
        Produk(int berat_tambahan, string origin);      // ctor
        ~Produk();                                      // dtor
        Produk& operator=(const Produk &produk);        // operator=
        
        void set_berat_tambahan(int berat_tambahan);    // setter
        void set_origin(string origin);                
        int get_berat_tambahan();                       // getter
        string get_origin();    
        void print_info();                              // print info
};
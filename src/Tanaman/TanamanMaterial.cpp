#include "TanamanMaterial.hpp"

TanamanMaterial::TanamanMaterial(int umur_panen): Tanaman(umur_panen) {
} 

TanamanMaterial::TanamanMaterial(TanamanMaterial &other): Tanaman(other.umur_panen) {
}

TanamanMaterial::~TanamanMaterial() {}

TanamanMaterial& TanamanMaterial::operator=(const TanamanMaterial &other): umur_panen(other.umur_panen) {
    umur = other.umur;
    return *this
}
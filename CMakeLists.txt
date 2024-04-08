cmake_minimum_required(VERSION 3.16)
project(BCN_BacinPunya)

set(CMAKE_CXX_STANDARD 17)

# Add the source in project root directory
add_executable(BCN_BacinPunya 
            src/main.cpp
            src/Bangunan/Bangunan.cpp
            src/Entitas/Entitas.cpp
            src/Hewan/Hewan.cpp
            src/Hewan/Herbivora.cpp
            src/Hewan/Karnivora.cpp
            src/Hewan/Omnivora.cpp
            src/InputKonfigurasi/InputKonfigurasi.cpp
            src/ManajerPermainan/ManajerPermainan.cpp
            # src/Pemain/Pemain.cpp
            # src/Pemain/Petani.cpp
            # src/Pemain/Peternak.cpp
            # src/Pemain/Walikota.cpp
            src/Produk/Produk.cpp
            src/Produk/ProdukHewan.cpp
            src/Produk/ProdukTanamanBuah.cpp
            src/Produk/ProdukTanamanMaterial.cpp
            src/Tanaman/Tanaman.cpp
            src/Tanaman/TanamanBuah.cpp
            src/Tanaman/TanamanMaterial.cpp
            src/Toko/Toko.cpp
            src/Util/Util.cpp
            )
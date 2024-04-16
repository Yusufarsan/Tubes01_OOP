CC = g++
CFLAGS = -std=c++17

# Daftar target
MAIN = driverMain
HEWAN = driverHewan
INPUT = driverInput
MATRIKS = driverMatriks
PCOLOR = driverPcolor
PEMAIN = driverPemain
WALIKOTA = driverWalikota
PETANI = driverPetani
PETERNAK = driverPeternak
MANAJER = driverGM
TOKO = driverToko


# File sumber untuk setiap paket
Bangunan_SRCS = Bangunan/Bangunan.cpp
Entitas_SRCS = Entitas/Entitas.cpp
Hewan_SRCS = Hewan/Herbivora.cpp Hewan/Karnivora.cpp Hewan/Omnivora.cpp Hewan/Hewan.cpp
Input_SRCS = InputKonfigurasi/InputKonfigurasi.cpp
Manajer_SRCS = ManajerPermainan/ManajerPermainan.cpp
Pcolor_SRCS = Pcolor/Pcolor.cpp
Pemain_SRCS = Pemain/Pemain.cpp Pemain/Peternak.cpp Pemain/Petani.cpp Pemain/Walikota.cpp
Walikota_SRCS = Pemain/Pemain.cpp Pemain/Peternak.cpp Pemain/Petani.cpp Pemain/Walikota.cpp
Petani_SRCS = Pemain/Pemain.cpp Pemain/Peternak.cpp Pemain/Petani.cpp Pemain/Walikota.cpp
Peternak_SRCS = Pemain/Pemain.cpp Pemain/Peternak.cpp Pemain/Petani.cpp Pemain/Walikota.cpp
Produk_SRCS = Produk/Produk.cpp Produk/ProdukTanamanBuah.cpp Produk/ProdukTanamanMaterial.cpp Produk/ProdukHewan.cpp
Tanaman_SRCS = Tanaman/Tanaman.cpp Tanaman/TanamanBuah.cpp Tanaman/TanamanMaterial.cpp
Toko_SRCS = Toko/Toko.cpp
Util_SRCS = Util/Util.cpp

# File sumber driver
DriverMain_SRCS = main.cpp 
DriverHewan_SRCS = Hewan/driverHewan.cpp
DriverInput_SRCS = InputKonfigurasi/driverInput.cpp
DriverMatriks_SRCS = Matriks/driverMatriks.cpp
DriverPcolor_SRCS = Pcolor/driverPcolor.cpp
DriverPemain_SRCS = Pemain/driverPemain.cpp
DriverWalikota_SRCS = Pemain/driverWalikota.cpp
DriverPetani_SRCS = Pemain/driverPetani.cpp
DriverPeternak_SRCS = Pemain/driverPeternak.cpp
DriverManajer_SRCS = ManajerPermainan/driverGM.cpp
DriverToko_SRCS = Toko/driverToko.cpp

# File objek untuk setiap paket
Bangunan_OBJS = $(Bangunan_SRCS:.cpp=.o)
Entitas_OBJS = $(Entitas_SRCS:.cpp=.o)
Hewan_OBJS = $(Hewan_SRCS:.cpp=.o)
Input_OBJS = $(Input_SRCS:.cpp=.o)
Manajer_OBJS = $(Manajer_SRCS:.cpp=.o)
Pcolor_OBJS = $(Pcolor_SRCS:.cpp=.o)
Pemain_OBJS = $(Pemain_SRCS:.cpp=.o)
Walikota_OBJS = $(Walikota_SRCS:.cpp=.o)
Petani_OBJS = $(Petani_SRCS:.cpp=.o)
Peternak_OBJS = $(Peternak_SRCS:.cpp=.o)
Produk_OBJS = $(Produk_SRCS:.cpp=.o)
Tanaman_OBJS = $(Tanaman_SRCS:.cpp=.o)
Toko_OBJS = $(Toko_SRCS:.cpp=.o)
Util_OBJS = $(Util_SRCS:.cpp=.o)

# File objek untuk setiap driver
DriverMain_OBJS = $(DriverMain_SRCS:.cpp=.o)
DriverHewan_OBJS = $(DriverHewan_SRCS:.cpp=.o)
DriverInput_OBJS = $(DriverInput_SRCS:.cpp=.o)
DriverMatriks_OBJS = $(DriverMatriks_SRCS:.cpp=.o)
DriverPcolor_OBJS = $(DriverPcolor_SRCS:.cpp=.o)
DriverPemain_OBJS = $(DriverPemain_SRCS:.cpp=.o)
DriverWalikota_OBJS = $(DriverWalikota_SRCS:.cpp=.o)
DriverPetani_OBJS = $(DriverPetani_SRCS:.cpp=.o)
DriverPeternak_OBJS = $(DriverPeternak_SRCS:.cpp=.o)
DriverManajer_OBJS = $(DriverManajer_SRCS:.cpp=.o)
DriverToko_OBJS = $(DriverToko_SRCS:.cpp=.o)

# Target utama
all: $(MAIN)
Hewan: $(HEWAN)
Input: $(INPUT)
Matriks: $(MATRIKS)
Pcolor: $(PCOLOR)
Pemain: $(PEMAIN)
Walikota: $(WALIKOTA)
Petani: $(PETANI)
Peternak: $(PETERNAK)
Manajer: $(MANAJER)
Toko: $(TOKO)

# Target untuk membuat executable driverMain
$(MAIN): $(DriverMain_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS) 
	$(CC) $(CFLAGS) -o ../test/$(MAIN) $^

# Target untuk membuat executable driverHewan
$(HEWAN): $(DriverHewan_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(HEWAN) $^

# Target untuk membuat executable driverInput
$(INPUT): $(DriverInput_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(INPUT) $^

# Target untuk membuat executable driverMatriks
$(MATRIKS): $(DriverMatriks_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(MATRIKS) $^

# Target untuk membuat executable driverPcolor
$(PCOLOR): $(DriverPcolor_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(PCOLOR) $^

# Target untuk membuat executable driverPemain
$(PEMAIN): $(DriverPemain_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(PEMAIN) $^

# Target untuk membuat executable driverPemain
$(WALIKOTA): $(DriverWalikota_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(WALIKOTA) $^

# Target untuk membuat executable driverPemain
$(PETANI): $(DriverPetani_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(PETANI) $^

# Target untuk membuat executable driverPemain
$(PETERNAK): $(DriverPeternak_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(PETERNAK) $^

# Target untuk membuat executable driverManajer
$(MANAJER): $(DriverManajer_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(MANAJER) $^

# Target untuk membuat executable driverManajer
$(TOKO): $(DriverToko_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o ../test/$(TOKO) $^

# Target untuk mengkompilasi file objek untuk setiap paket
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


# Target untuk menjalankan pengujian setiap paket
test: all
	../test/$(MAIN)

test_Hewan: Hewan
	../test/$(HEWAN)

test_Input: Input
	../test/$(INPUT)

test_Matriks: Matriks
	../test/$(MATRIKS)

test_Pcolor: Pcolor
	../test/$(PCOLOR)

test_Pemain: Pemain
	../test/$(PEMAIN)

test_Walikota: Walikota
	../test/$(WALIKOTA)

test_Petani: Petani
	../test/$(PETANI)

test_Peternak: Peternak
	../test/$(PETERNAK)

test_Manajer: Manajer
	../test/$(MANAJER)

test_Toko: Toko
	../test/$(TOKO)

.PHONY: clean

# Target untuk membersihkan file objek dan executable
clean:
	rm -f $(DriverMain_OBJS) $(DriverHewan_OBJS) $(DriverInput_OBJS) $(DriverMatriks_OBJS) $(DriverPcolor_OBJS) $(DriverPemain_OBJS) $(DriverWalikota_OBJS) $(DriverPetani_OBJS) $(DriverPeternak_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)

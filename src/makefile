CC = g++
CFLAGS = -std=c++14

# Daftar target
MAIN = driverMain
HEWAN = driverHewan
INPUT = driverInput
MATRIKS = driverMatriks
PCOLOR = driverPcolor
PEMAIN = driverPemain

# Daftar paket
PACKAGES = Hewan Produk Entitas Util Tanaman

# File sumber untuk setiap paket
Bangunan_SRCS = Bangunan/Bangunan.cpp
Entitas_SRCS = Entitas/Entitas.cpp
Hewan_SRCS = Hewan/Herbivora.cpp Hewan/Karnivora.cpp Hewan/Omnivora.cpp Hewan/Hewan.cpp
Input_SRCS = InputKonfigurasi/InputKonfigurasi.cpp
Manajer_SRCS = ManajerPermainan/ManajerPermainan.cpp
Pcolor_SRCS = Pcolor/Pcolor.cpp
Pemain_SRCS = Pemain/Pemain.cpp Pemain/Peternak.cpp Pemain/Petani.cpp Pemain/Walikota.cpp
Produk_SRCS = Produk/Produk.cpp Produk/ProdukTanamanBuah.cpp Produk/ProdukTanamanMaterial.cpp Produk/ProdukHewan.cpp
Tanaman_SRCS = Tanaman/Tanaman.cpp Tanaman/TanamanBuah.cpp Tanaman/TanamanMaterial.cpp
Toko_SRCS = Toko/Toko.cpp
Util_SRCS = Util/Util.cpp

# File sumber driver
DriverMain_SRCS = driverMain.cpp 
DriverHewan_SRCS = Hewan/driverHewan.cpp
DriverInput_SRCS = InputKonfigurasi/driverInput.cpp
DriverMatriks_SRCS = Matriks/driverMatriks.cpp
DriverPcolor_SRCS = Pcolor/driverPcolor.cpp
DriverPemain_SRCS = Pemain/driverPemain.cpp

# File objek untuk setiap paket
Bangunan_OBJS = $(Bangunan_SRCS:.cpp=.o)
Entitas_OBJS = $(Entitas_SRCS:.cpp=.o)
Hewan_OBJS = $(Hewan_SRCS:.cpp=.o)
Input_OBJS = $(Input_SRCS:.cpp=.o)
Manajer_OBJS = $(Manajer_SRCS:.cpp=.o)
Pcolor_OBJS = $(Pcolor_SRCS:.cpp=.o)
Pemain_OBJS = $(Pemain_SRCS:.cpp=.o)
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

# Target utama
all: $(MAIN)
Hewan: $(HEWAN)
Input: $(INPUT)
Matriks: $(MATRIKS)
Pcolor: $(PCOLOR)
Pemain: $(PEMAIN)

# Target untuk membuat executable driverMain
$(MAIN): $(DriverMain_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk membuat executable driverHewan
$(HEWAN): $(DriverHewan_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk membuat executable driverInput
$(INPUT): $(DriverInput_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk membuat executable driverMatriks
$(MATRIKS): $(DriverMatriks_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk membuat executable driverPcolor
$(PCOLOR): $(DriverPcolor_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk membuat executable driverPemain
$(PEMAIN): $(DriverPemain_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk mengkompilasi file objek untuk setiap paket
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


# Target untuk menjalankan pengujian setiap paket
test: all
	./$(MAIN)

test_Hewan: Hewan
	./$(HEWAN)

test_Input: Input
	./$(INPUT)

test_Matriks: Matriks
	./$(MATRIKS)

test_Pcolor: Pcolor
	./$(PCOLOR)

test_Pemain: Pemain
	./$(PEMAIN)

.PHONY: clean

# Target untuk membersihkan file objek dan executable
clean:
	rm -f $(DriverMain_OBJS) $(DriverHewan_OBJS) $(DriverInput_OBJS) $(DriverMatriks_OBJS) $(DriverPcolor_OBJS) $(DriverPemain_OBJS) $(Bangunan_OBJS) $(Entitas_OBJS) $(Hewan_OBJS) $(Input_OBJS) $(Manajer_OBJS) $(Pcolor_OBJS) $(Pemain_OBJS) $(Produk_OBJS) $(Tanaman_OBJS) $(Toko_OBJS) $(Util_OBJS)

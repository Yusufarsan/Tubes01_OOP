CC = g++
CFLAGS = -std=c++11
TARGET = driverPemain

# Daftar paket
PACKAGES = Hewan Produk Entitas Util Tanaman

# File sumber untuk setiap paket
Hewan_SRCS = ../Hewan/Herbivora.cpp ../Hewan/Karnivora.cpp ../Hewan/Hewan.cpp
Produk_SRCS = ../Produk/Produk.cpp ../Produk/ProdukTanamanBuah.cpp ../Produk/ProdukTanamanMaterial.cpp ../Produk/ProdukHewan.cpp
Entitas_SRCS = ../Entitas/Entitas.cpp
Util_SRCS = ../Util/Util.cpp
Tanaman_SRCS = ../Tanaman/Tanaman.cpp ../Tanaman/TanamanBuah.cpp

# File sumber tambahan
Pemain_SRCS = Pemain.cpp
Driver_SRCS = driverPemain.cpp

# File objek untuk setiap paket
Hewan_OBJS = $(Hewan_SRCS:.cpp=.o)
Produk_OBJS = $(Produk_SRCS:.cpp=.o)
Entitas_OBJS = $(Entitas_SRCS:.cpp=.o)
Util_OBJS = $(Util_SRCS:.cpp=.o)
Tanaman_OBJS = $(Tanaman_SRCS:.cpp=.o)

# File objek tambahan
Pemain_OBJS = $(Pemain_SRCS:.cpp=.o)
Driver_OBJS = $(Driver_SRCS:.cpp=.o)

# Target utama
all: $(TARGET)

# Target untuk membuat executable driver
$(TARGET): $(Hewan_OBJS) $(Produk_OBJS) $(Entitas_OBJS) $(Util_OBJS) $(Tanaman_OBJS) $(Pemain_OBJS) $(Driver_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Target untuk mengkompilasi file objek untuk setiap paket
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Target untuk menjalankan pengujian setiap paket
test: all
	./$(TARGET)

.PHONY: clean

# Target untuk membersihkan file objek dan executable
clean:
	rm -f $(TARGET) $(Hewan_OBJS) $(Produk_OBJS) $(Entitas_OBJS) $(Util_OBJS) $(Tanaman_OBJS) $(Pemain_OBJS) $(Driver_OBJS)

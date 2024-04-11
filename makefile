CC = g++
CFLAGS = -std=c++11
TARGET = driver

# Daftar paket
PACKAGES = Hewan Produk Entitas

# File sumber untuk setiap paket
Hewan_SRCS = DriverHewan.cpp Herbivora.cpp Karnivora.cpp Hewan.cpp Omnivora.cpp
Produk_SRCS = Produk.cpp ProdukTanamanBuah.cpp ProdukHewan.cpp
Entitas_SRCS = Entitas.cpp

# Daftar semua file sumber
SRCS = $(foreach pkg,$(PACKAGES),$($(pkg)_SRCS))
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Target untuk pengujian setiap paket
test: $(foreach pkg,$(PACKAGES),test_$(pkg))

test_Hewan: $(Hewan_SRCS)
	$(CC) $(CFLAGS) -o $@ $^
	./test_Hewan

test_Produk: $(Produk_SRCS)
	$(CC) $(CFLAGS) -o $@ $^
	./test_Produk

test_Entitas: $(Entitas_SRCS)
	$(CC) $(CFLAGS) -o $@ $^
	./test_Entitas

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJS) test_*

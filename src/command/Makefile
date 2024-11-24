# Compiler dan Flags
CC = gcc
CFLAGS = -Wno-implicit-function-declaration

# File Sumber dan Header
SRC = main.c \
    Logout/logout.c \
    Help/help.c \
    animasi/animasi.c \
    load/load.c \
    login/login.c \
    register/register.c \
    save/save.c \
    Start/start.c \
    Store_List/Store_List.c \
    Store_Remove/Store_Remove.c \
    Store_Request/Store_Request.c \
    Store_Supply/Store_Supply.c \
    work/work.c \
    workchallenge/tebakangka/tebakangka.c \
    workchallenge/wordl3/wordl3.c \
    ../ADT/List/list.c \
    ../ADT/Mesin_Baris/mesinbaris.c \
    ../ADT/Mesin_Karakter/mesinkarakter.c \
    ../ADT/Mesin_Kata/mesinkata.c \
    ../ADT/queue/queue.c \
    ../ADT/User_Barang/user.c \
    ../ADT/User_Barang/barang.c

OBJ = $(SRC:.c=.o)

# Target Utama
all: program

# Membuat Program dari Objek
program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o program

# Membuat File Objek
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Menjalankan Program
run: program
	./program ../../save/config.txt

# Membersihkan File Objek dan Program
clean:
	del /f /q *.o program.exe 2>nul
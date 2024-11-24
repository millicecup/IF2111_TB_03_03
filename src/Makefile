# Compiler dan Flags
CC = gcc
CFLAGS = -Wno-implicit-function-declaration

# File Sumber dan Header
SRC = main.c \
    command/handler/handler.c \
    command/Logout/logout.c \
    command/Help/help.c \
    command/animasi/animasi.c \
    command/load/load.c \
    command/login/login.c \
    command/register/register.c \
    command/save/save.c \
    command/Start/start.c \
    command/Store_List/Store_List.c \
    command/Store_Remove/Store_Remove.c \
    command/Store_Request/Store_Request.c \
    command/Store_Supply/Store_Supply.c \
    command/work/work.c \
    command/workchallenge/tebakangka/tebakangka.c \
    command/workchallenge/wordl3/wordl3.c \
    ADT/List/list.c \
    ADT/Mesin_Baris/mesinbaris.c \
    ADT/Mesin_Karakter/mesinkarakter.c \
    ADT/Mesin_Kata/mesinkata.c \
    ADT/queue/queue.c \
    ADT/User_Barang/user.c \
    ADT/User_Barang/barang.c

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

	./program Data/config.txt

# Membersihkan File Objek dan Program
clean:
	del /f /q *.o program.exe 2>nul
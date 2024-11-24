# Compiler and Flags
CC = gcc
CFLAGS = -Wno-implicit-function-declaration

# Source Files (Mimicking the manual command)
SRC = main.c \
    ../ADT/User_Barang/user.c \
    ../ADT/User_Barang/barang.c \
    ../ADT/Mesin_Karakter/mesinkarakter.c \
    ../ADT/Mesin_Kata/mesinkata.c \
    ../ADT/Mesin_Baris/mesinbaris.c \
    Start/start.c \
    login/login.c \
    register/register.c \
    save/save.c \
    load/load.c \
    animasi/animasi.c \
    Store_List/Store_List.c \
    ../ADT/List/list.c \
    ../ADT/queue/queue.c \
    Store_Request/Store_Request.c \
    Store_Remove/Store_Remove.c \
    Store_Supply/Store_Supply.c \
    workchallenge/wordl3/wordl3.c \
    workchallenge/tebakangka/tebakangka.c \
    work/work.c \
    help/help.c \
    logout/logout.c \
    quit/quit.c \
    handler/handler.c

# Output Binary
OUTPUT = program.exe

# Target to build the program
all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)

# Run the program (Optional)
run: $(OUTPUT)
	$(OUTPUT)

# Clean generated files
clean:
	del /f /q $(OUTPUT) 2>nul

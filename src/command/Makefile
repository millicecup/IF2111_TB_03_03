# Compiler dan Flags
CC = gcc
CFLAGS = -Wno-implicit-function-declaration

# Source Files
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
    Help/help.c \
    Logout/logout.c \
    quit/quit.c \
    handler/handler.c

# Output
OUTPUT = program

# untuk pisahin windows linux
ifeq ($(OS),Windows_NT)
    RM = del /f /q
    EXE = .exe
else
    RM = rm -f
    EXE =
endif

# build program
all: $(OUTPUT)$(EXE)

$(OUTPUT)$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)$(EXE)

# Run 
run: $(OUTPUT)$(EXE)
	./$(OUTPUT)$(EXE)

# Clean files
clean:
	$(RM) $(OUTPUT)$(EXE)

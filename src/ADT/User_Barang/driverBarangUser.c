#include <stdio.h>
#include "barang.h"
#include "user.h"

int main() {
    // Inisialisasi List Statis untuk User
    UserList userList;
    CreateUserList(&userList);

    // Menambahkan pengguna secara manual
    char adminName[MAX_LEN] = "admin";
    char adminPassword[MAX_LEN] = "alstrukdatkeren";
    ManualStringCopy(adminName, "admin");
    ManualStringCopy(adminPassword, "alstrukdatkeren");
    AddUser(&userList, adminName, adminPassword, 100);

    char praktikanName[MAX_LEN] = "praktikan";
    char praktikanPassword[MAX_LEN] = "kerenbangetkak";
    ManualStringCopy(praktikanName, "praktikan");
    ManualStringCopy(praktikanPassword, "kerenbangetkak");
    AddUser(&userList, praktikanName, praktikanPassword, 25);

    PrintUsers(&userList);

    // Inisialisasi List Dinamis untuk Barang
    BarangList barangList;
    CreateBarangList(&barangList, 2); // Kapasitas awal 2

    // Menambahkan barang secara manual
    char barang1[MAX_LEN] = "AK47";
    ManualStringCopy(barang1, "AK47");
    AddBarang(&barangList, barang1, 10);

    char barang2[MAX_LEN] = "Lalabu";
    ManualStringCopy(barang2, "Lalabu");
    AddBarang(&barangList, barang2, 20);

    char barang3[MAX_LEN] = "Ayam Goreng Crisbar";
    ManualStringCopy(barang3, "Ayam Goreng Crisbar");
    AddBarang(&barangList, barang3, 30);

    PrintBarang(&barangList);

    // Bebaskan memori yang digunakan oleh list dinamis
    FreeBarangList(&barangList);

    return 0;
}
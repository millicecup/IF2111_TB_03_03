#ifndef LOAD_H
#define LOAD_H
#include "../../ADT/user/user.h"
#include "../../ADT/barang/barang.h"

// Function for the LOAD command
void loadFromFile(FILE *file, Arraybarang *barangArray, ArrayUser *userArray);
/*
{ I.S. : Filename diberikan, program belum memuat save file }
{ F.S. : Membaca file save sesuai nama, menampilkan pesan keberhasilan atau kegagalan }
*/

#endif

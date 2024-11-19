#ifndef SAVE
#define SAVE
#include "../../ADT/barang/barang.h"
#include "../../ADT/user/user.h"
#include "../../ADT/boolean.h"
boolean saveToFile(const char *filename, Arraybarang *barangArray, ArrayUser *userArray);
#endif
#ifndef MESINKAR_H
#define MESINKAR_H

#include "boolean.h"

#define MARK '.'

/* State Mesin */
extern char CC;
extern boolean EOP;

// Deklarasi Fungsi dan Prosedur
void TASTART(void);
void TAADV(void);
char TAGetCC(void);
boolean TAIsEOP(void);
boolean TAIsWhitespace(void);

#endif

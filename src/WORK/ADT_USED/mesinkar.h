#ifndef MESINKAR_H
#define MESINKAR_H

#include "boolean.h"

#define MARK '.'

/* State Mesin */
extern char CC;
extern boolean EOP;

// Deklarasi Fungsi dan Prosedur
void START(void);
void ADV(void);
char GetCC(void);
boolean IsEOP(void);
boolean IsWhitespace(void);

#endif

#ifndef _QUEUE_H
#define _QUEUE_H

#include "boolean.h"

typedef struct {
    int duration;
} Work;

typedef struct {
    Work data;
    boolean isActive;
} Queue;

/* Membuat Queue kosong */
void CreateQueue(Queue *queue);

/* Menambahkan pekerjaan ke Queue */
void StartWork(Queue *queue, int duration);

/* Mengecek apakah pekerjaan selesai */
boolean IsWorkDone(Queue *queue);

#endif

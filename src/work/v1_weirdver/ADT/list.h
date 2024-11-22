#ifndef _LIST_H
#define _LIST_H

#include "boolean.h"

#define MAX 100

typedef struct {
    char name[50];
    int income;
    int duration;
} Job;

typedef struct {
    Job jobs[MAX];
    int count;
} JobList;

/* Konstruktor untuk JobList */
void CreateJobList(JobList *list);

/* Menambahkan pekerjaan ke JobList */
void AddJob(JobList *list, char *name, int income, int duration);

/* Menampilkan daftar pekerjaan */
void DisplayJobs(JobList list);

#endif

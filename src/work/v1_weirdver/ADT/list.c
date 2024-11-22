#include "list.h"
#include <stdio.h>
#include <string.h>

void CreateJobList(JobList *list) {
    list->count = 0;
}

void AddJob(JobList *list, char *name, int income, int duration) {
    Job job;
    strcpy(job.name, name);
    job.income = income;
    job.duration = duration;
    list->jobs[list->count++] = job;
}

void DisplayJobs(JobList list) {
    for (int i = 0; i < list.count; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", 
               i + 1, list.jobs[i].name, list.jobs[i].income, list.jobs[i].duration);
    }
}

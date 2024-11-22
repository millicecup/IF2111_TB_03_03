//Jujur agak gak yakin sm versi ini but f__k it we ball

#include "list.h"
#include "queue.h"
#include "mesinkata.h"
#include <stdio.h>

int main() {
    JobList jobList;
    Queue workQueue;
    char input[50];

    /* Inisialisasi */
    CreateJobList(&jobList);
    CreateQueue(&workQueue);

    /* Menambahkan daftar pekerjaan */
    AddJob(&jobList, "Evil Lab Assistant", 100, 14);
    AddJob(&jobList, "OWCA Hiring Manager", 4200, 21);
    AddJob(&jobList, "Cikapundunginator Caretaker", 7000, 30);
    AddJob(&jobList, "Mewing Specialist", 10000, 22);
    AddJob(&jobList, "Inator Connoisseur", 997, 15);

    printf(">> WORK\n\n");
    printf("Daftar pekerjaan:\n");
    DisplayJobs(jobList);

    printf("\nMasukkan pekerjaan yang dipilih: ");
    ReadInput(input);

    /* Cari pekerjaan berdasarkan input */
    int i;
    boolean found = false;
    for (i = 0; i < jobList.count; i++) {
        if (strcmp(jobList.jobs[i].name, input) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Pekerjaan tidak ditemukan!\n");
        return 0;
    }

    printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", input);
    StartWork(&workQueue, jobList.jobs[i].duration);

    /* Tunggu hingga pekerjaan selesai */
    while (!IsWorkDone(&workQueue));

    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", jobList.jobs[i].income);
    return 0;
}

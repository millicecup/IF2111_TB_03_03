#include "queue.h"
#include <time.h>

static time_t startTime;

void CreateQueue(Queue *queue) {
    queue->isActive = false;
}

void StartWork(Queue *queue, int duration) {
    queue->data.duration = duration;
    queue->isActive = true;
    startTime = time(NULL);
}

boolean IsWorkDone(Queue *queue) {
    if (!queue->isActive) return false;
    time_t currentTime = time(NULL);
    if ((currentTime - startTime) >= queue->data.duration) {
        queue->isActive = false;
        return true;
    }
    return false;
}

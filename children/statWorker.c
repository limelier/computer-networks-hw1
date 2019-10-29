#include "statWorker.h"
#include <stdio.h>
#include <unistd.h>

void statWorker(int socket) {
    printf("Stat worker started, with pid %d, child of %d.\n", getpid(), getppid());
}

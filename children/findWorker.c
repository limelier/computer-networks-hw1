#include <unistd.h>
#include <stdio.h>
#include "findWorker.h"

void findWorker(char* fifoToMaster, char* fifoFromMaster) {
    printf("Find worker started, with pid %d, child of %d.\n", getpid(), getppid());

}

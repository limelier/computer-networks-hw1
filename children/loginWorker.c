#include <unistd.h>
#include <stdio.h>
#include "loginWorker.h"

void loginWorker(int toMaster, int fromMaster) {
    printf("Login worker started, with pid %d, child of %d.\n", getpid(), getppid());
}

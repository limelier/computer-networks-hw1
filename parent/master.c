#include <unistd.h>
#include <stdio.h>
#include "master.h"

void parent(struct parentData data) {
    printf("Parent [%d] initialized. Children: %d, %d, %d.\n", getpid(), data.loginPid, data.findPid, data.statPid);
}
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <fcntl.h>
#include "master.h"

void quit(struct parentData data, int toFindWorker) {
    printf("Closing workers...\n");
    write(data.loginPipeSend, "1", sizeof(struct loginWorkerInput));
    wait(NULL);
    write(data.statSocket, "1", sizeof(struct statWorkerInput));
    wait(NULL);
    write(toFindWorker, "1", sizeof(struct findWorkerInput));
    wait(NULL);

    printf("Doing cleanup...\n");
    remove(data.findFifoSend);
    remove(data.findFifoReceive);
    printf("Cleanup finished. Process exiting.");
}

void parent(struct parentData data) {
    printf("master [%d] init with ", getpid());
    printf("workers: [%d, %d, %d]\n", data.loginPid, data.findPid, data.statPid);

    int toFindWorker = open(data.findFifoSend, O_WRONLY);
    int fromFindWorker = open(data.findFifoReceive, O_RDONLY);

    char command[200];
    printf("Welcome, user. Available commands: login, quit.\n");


    quit(data, toFindWorker);
}

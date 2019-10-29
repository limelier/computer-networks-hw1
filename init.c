#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "util.h"
#include "parent.h"

void init() {
    int pipeFd[2], sockp[2];

    int mkfifoResult = mkfifo("findFifo",  0666);
    int pipeResult = pipe(pipeFd);
    int sockpairResult = socketpair(AF_UNIX, SOCK_STREAM, 0, sockp);

    if (mkfifoResult < 0 || pipeResult < 0 || sockpairResult < 0) {
        perror("Error opening communication channels.\n");
        exit(1);
    }

    int pid1 = 0, pid2 = 0, pid3 = 0;

    pid1 = fork();
    if (pid1) {
        pid2 = fork();
    }
    if (pid1 && pid2) {
        pid3 = fork();
    }

    if (pid1 && pid2 && pid3) {
        struct parentData data;
        data.loginPid = pid1;
        data.findPid = pid2;
        data.statPid = pid3;
        data.loginPipe = pipeFd;
        data.statSockp = sockp;
        parent(data);
    }
}

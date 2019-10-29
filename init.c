#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "util.h"
#include "parent/master.h"
#include "children/loginWorker.h"
#include "children/findWorker.h"
#include "children/statWorker.h"

#define WHICH_PARENT 0
#define WHICH_LOGIN 1
#define WHICH_FIND 2
#define WHICH_STAT 3

#define FIFO_TO_WORKER "findFifoSend"
#define FIFO_FROM_WORKER "findFifoReceive"

void init() {
    int pipeMW[2], pipeWM[2], sockp[2];

    int mkfifoResult1 = mkfifo(FIFO_TO_WORKER, 0666);
    int mkfifoResult2 = mkfifo(FIFO_FROM_WORKER, 0666);
    int pipeResult1 = pipe(pipeMW);
    int pipeResult2 = pipe(pipeWM);
    int sockpairResult = socketpair(AF_UNIX, SOCK_STREAM, 0, sockp);

    if (mkfifoResult1 < 0 || mkfifoResult2 < 0 || pipeResult1 < 0 || pipeResult2 < 0 || sockpairResult < 0) {
        perror("Error opening communication channels.\n");
        exit(1);
    }

    int pid1 = 0, pid2 = 0, pid3 = 0;
    int which = 0;

    pid1 = fork();
    if (!pid1) {
        which = 1;
    } else {
        pid2 = fork();
        if (!pid2) {
            which = 2;
        } else {
            pid3 = fork();
            if (!pid3) {
                which = 3;
            }
        }
    }

    switch (which) {
        case WHICH_PARENT: {
            struct parentData data;
            data.loginPid = pid1;
            data.findPid = pid2;
            data.statPid = pid3;
            data.loginPipeSend = pipeMW[1];
            data.loginPipeReceive = pipeWM[0];
            data.statSocket = sockp[1];
            data.findFifoSend = FIFO_TO_WORKER;
            data.findFifoReceive = FIFO_FROM_WORKER;
            close(sockp[0]); close(pipeMW[0]); close(pipeWM[1]);
            parent(data);
            break;
        }
        case WHICH_LOGIN: {
            close(sockp[0]); close(sockp[1]);
            close(pipeMW[1]); close(pipeWM[0]);
            loginWorker(pipeWM[1], pipeMW[0]);
            break;
        }
        case WHICH_FIND: {
            close(sockp[0]); close(sockp[1]);
            close(pipeMW[0]); close(pipeMW[1]); close(pipeWM[0]); close(pipeWM[1]);
            findWorker(FIFO_FROM_WORKER, FIFO_TO_WORKER);
            break;
        }
        case WHICH_STAT: {
            close(pipeMW[0]); close(pipeMW[1]); close(pipeWM[0]); close(pipeWM[1]);
            close(sockp[1]);
            statWorker(sockp[0]);
            break;
        }
        default:
            perror("Invalid value for 'which'.\n");
            exit(1);
    }

    // cleanup
    remove("findFifoSend");
    remove("findFifoReceive");
}

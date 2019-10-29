#include "statWorker.h"
#include "../util.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void statWorker(int socket) {
    struct statWorkerInput input;
    struct statWorkerOutput output;

    while (1) {
        int readResult = read(socket, &input, sizeof(input));
        if (readResult != sizeof(input)) {
            perror("[worker:stat] Error reading from master.\n");
            exit(1);
        }
        else {
            if (input.quitFlag == '1') {
                printf("[worker:stat] closing\n");
                exit(0);
            }
            else {
                // todo
            }
        }
    }
}

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "loginWorker.h"
#include "../util.h"

void loginWorker(int toMaster, int fromMaster) {
    struct loginWorkerInput input;
    struct loginWorkerOutput output;

    while (1) {
        int readResult = read(fromMaster, &input, sizeof(input));
        if (readResult != sizeof(input)) {
            perror("[worker:login] Error reading from master.\n");
            exit(1);
        }
        else {
            if (input.quitFlag == '1') {
                printf("[worker:login] closing\n");
                exit(0);
            }
            else {
                // todo
            }
        }
    }
}

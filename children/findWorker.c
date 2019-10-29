#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "findWorker.h"
#include "../util.h"

void findWorker(char* fifoToMaster, char* fifoFromMaster) {
    struct findWorkerInput input;
    struct findWorkerOutput output;

    int fromMaster = open(fifoFromMaster, O_RDONLY), toMaster = open(fifoToMaster, O_WRONLY);

    while (1) {
        int readResult = read(fromMaster, &input, sizeof(input));
        if (readResult != sizeof(input)) {
            perror("[worker:find] error reading from master\n");
            exit(1);
        }
        else {
            if (input.quitFlag == '1') {
                printf("[worker:find] closing\n");
                exit(0);
            }
            else {
                // todo
            }
        }
    }
}

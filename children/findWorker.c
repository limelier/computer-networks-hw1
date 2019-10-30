#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "findWorker.h"
#include "../util.h"
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>

char* findFile(char* searchPath, char* targetFileName) {
    struct stat pathStats;
    int statResult = stat(searchPath, &pathStats);
    if (statResult != 0) {
        return NULL;
    }
    if (S_ISDIR(pathStats.st_mode)) {
        DIR *dir;
        dir = opendir(searchPath);
        if (dir == NULL) {
            return NULL;
        }
        struct dirent *de = readdir(dir);
        while (de != NULL) {
            if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) { // ignore ., ..
                char path[2048];
                sprintf(path, "%s/%s", searchPath, de->d_name);
                char *resultPath = findFile(path, targetFileName);
                if (resultPath) {
                    return resultPath;
                }
            }
            de = readdir(dir);
        }
        return NULL;
    } else {
        char *fileName = basename(searchPath);
        if (strcmp(fileName, targetFileName) == 0) {
            return searchPath;
        } else {
            return NULL;
        }
    }
}

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
                char *searchResult = findFile(input.searchPath, input.fileName);
                if (searchResult == NULL) {
                    output.existsFlag = '0';
                } else {
                    output.existsFlag = '1';
                    strcpy(output.filePath, searchResult);
                }
                write(toMaster, &output, sizeof(output));
            }
        }
    }
}

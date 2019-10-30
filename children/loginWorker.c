#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "loginWorker.h"
#include "../util.h"
#include <string.h>

char findUser(char *username) {
    char buffer[8192];
    int file = open("authorized_users.txt", O_CREAT);
    // usernames in file need to be surrounded by <angle_brackets> and not contain any themselves. alpha-numeric recommended.

    char searchString[strlen(username) + 1];
    strcpy(searchString, username);
    searchString[strlen(username)] = '>';
    searchString[strlen(username) + 1] = '\0';
    strcpy(searchString + 1, searchString);
    searchString[0] = '<';

    int bytes = read(file, buffer, 8192);
    if (bytes < 0) {
        perror("[worker:login] Error reading from file.");
        exit(1);
    } else if (bytes > 0) {
        if (strstr(buffer, searchString)) {
            return '1';
        } else {
            return '0';
        }
    } else {
        return '0';
    }
}

void loginWorker(int toMaster, int fromMaster) {
    struct loginWorkerInput input;
    struct loginWorkerOutput output;

    while (1) {
        int readResult = read(fromMaster, &input, sizeof(input));
        if (readResult != sizeof(input)) {
            perror("[worker:login] Error reading from master.\n");
            exit(1);
        } else {
            if (input.quitFlag == '1') {
                printf("[worker:login] closing\n");
                exit(0);
            } else {
                output.acceptedFlag = findUser(input.username);
                write(toMaster, &output, sizeof(output));
            }
        }
    }
}

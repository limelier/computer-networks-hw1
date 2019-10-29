#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <fcntl.h>
#include "master.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CMD_LOGIN 0
#define CMD_QUIT 1
#define CMD_FIND 2
#define CMD_STAT 3

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
    exit(0);
}

int getInput(char *arg1, char *arg2) {
    char command[1024];
    scanf("%s", command);
    if (!strcmp(command, "login")) {
        scanf("%s", arg1);
        arg2 = NULL;
        return CMD_LOGIN;
    } else if (!strcmp(command, "quit")) {
        arg1 = NULL;
        arg2 = NULL;
        return CMD_QUIT;
    } else if (!strcmp(command, "find")) {
        scanf("%s %s", arg1, arg2);
        return CMD_FIND;
    } else if (!strcmp(command, "stat")) {
        scanf("%s", arg1);
        arg2 = NULL;
        return CMD_STAT;
    } else {
        arg1 = NULL;
        arg2 = NULL;
        return -1;
    }
}

bool login(int to, int from, char *username) {
    struct loginWorkerInput toPacket;
    toPacket.quitFlag = '0';
    strcpy(toPacket.username, username);
    write(to, &toPacket, sizeof(toPacket));

    struct loginWorkerOutput fromPacket;
    read(from, &fromPacket, sizeof(fromPacket));

    return (fromPacket.acceptedFlag == '1');
}

void myStat(int socket, char *filePath) {
    struct statWorkerInput toPacket;
    toPacket.quitFlag = '0';
    strcpy(toPacket.filePath, filePath);
    write(socket, &toPacket, sizeof(toPacket));

    struct statWorkerOutput fromPacket;
    read(socket, &fromPacket, sizeof(fromPacket));
    if (fromPacket.successFlag == '1') {
        printf("File size: %ld.\n", fromPacket.stats.st_size);
    } else {
        printf("Stat failed!\n");
    }
    printf("Input another command: find, stat or quit.\n");
}

void parent(struct parentData data) {
    printf("master [%d] init with ", getpid());
    printf("workers: [%d, %d, %d]\n", data.loginPid, data.findPid, data.statPid);

    int toFindWorker = open(data.findFifoSend, O_WRONLY);
    int fromFindWorker = open(data.findFifoReceive, O_RDONLY);

    printf("Hello, please authenticate. Available commands: login, quit.\n");

    char arg1[2048], arg2[2048];

    bool loggedIn = false;

    while (!loggedIn) {
        int command = getInput(arg1, arg2);

        switch (command) {
            case CMD_LOGIN: {
                if (login(data.loginPipeSend, data.loginPipeReceive, arg1)) {
                    loggedIn = true;
                    printf("Welcome, %s. Available commands: find, stat, quit.\n", arg1);
                } else {
                    printf("%s is not a known user. Please try again.\n", arg1);
                }
                break;
            }
            case CMD_QUIT: {
                quit(data, toFindWorker);
                break;
            }
            default: {
                printf("Bad command. Available commands: login, quit.\n");
            }
        }
    }

    while (true) {
        int command = getInput(arg1, arg2);

        switch (command) {
            case CMD_QUIT: {
                quit(data, toFindWorker);
                exit(0); // shouldn't even be able to get here, but CLion won't shut up
                break;
            }
            case CMD_FIND: {
                printf("Not implemented yet...\n");
                break;
            }
            case CMD_STAT: {
                myStat(data.statSocket, arg1);
                break;
            }
            default:
                printf("Bad command. Available commands: find, stat, quit\n");
        }
    }

    exit(1); // not able to get here anyway
}

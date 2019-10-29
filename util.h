#ifndef TEMA_1_UTIL_H
#define TEMA_1_UTIL_H

struct parentData {
    int loginPid;
    int findPid;
    int statPid;
    int loginPipeSend;
    int loginPipeReceive;
    int statSocket;
    char* findFifoSend;
    char* findFifoReceive;
};

struct findWorkerInput {
    char quitFlag;
    char fileName[1023];
    char searchPath[1024];
};

struct findWorkerOutput {
    char existsFlag;
    char filePath[2047];
};

struct statWorkerInput {
    char quitFlag;
    char filePath[2047];
};

struct statWorkerOutput {
    // todo
};

struct loginWorkerInput {
    char quitFlag;
    char username[511];
};

struct loginWorkerOutput {
    char acceptedFlag;
};



#endif //TEMA_1_UTIL_H

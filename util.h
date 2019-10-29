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


#endif //TEMA_1_UTIL_H

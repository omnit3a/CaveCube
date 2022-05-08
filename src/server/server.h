#ifndef SERVER_H
#define SERVER_H

#include <stdbool.h>
#include <chunk.h>

#ifndef SERVER_THREADS
    #define SERVER_THREADS 4
#endif

enum {
    SERVER_MODE_SP,
    SERVER_MODE_MP,
    SERVER_MODE_BRIDGE,
};

enum {
    SERVER_MSG_PING,
    SERVER_MSG_GETCHUNK,
};

struct server_chunk {
    struct chunkdata* chunks;
    int x;
    int y;
    int z;
    int xo;
    int zo;
    struct blockdata data[4096];
};

bool initServer(int);
bool servMsgReady(int);
int servSend(int, void*, bool, bool, void*);

#endif

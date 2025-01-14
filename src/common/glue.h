#ifndef COMMON_GLUE_H
#define COMMON_GLUE_H

#ifndef _WIN32
    #define mkdir(x) mkdir(x, (S_IRWXU) | (S_IRGRP | S_IXGRP) | (S_IROTH | S_IXOTH))
#else
    #define pause() Sleep(INFINITE)
    #define strcasecmp stricmp
    #define realpath(x, y) _fullpath(y, x, MAX_PATH)
#endif

#include <limits.h>

#ifndef MAX_PATH
    #ifdef PATH_MAX
        #define MAX_PATH PATH_MAX
    #else
        #define MAX_PATH 4095
    #endif
#endif

#ifndef _WIN32
    #define PATHSEP '/'
    #define PATHSEPSTR "/"
#else
    #define PATHSEP '\\'
    #define PATHSEPSTR "\\"
#endif

#ifndef _WIN32
    #define PRIdz "zd"
    #define PRIuz "zu"
    #define PRIxz "zx"
    #define PRIXz "zX"
#else
    #define PRIdz "Id"
    #define PRIuz "Iu"
    #define PRIxz "Ix"
    #define PRIXz "IX"
#endif

#endif

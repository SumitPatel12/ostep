#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

inline double get_time() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

inline void spin(int howlong) {
    double t = get_time();
    while ((get_time() - t) < (double) howlong);
}

#endif

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "ICache.h"
#include "LRU_Cache.h"
#include "LFU_Cache.h"

int fibonachi(int n, ICache& cache);

#endif

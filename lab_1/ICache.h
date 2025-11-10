#ifndef ICACHE_H
#define ICACHE_H

#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>
#include <list>

class ICache {
public:
    virtual int get(int key) = 0;
    virtual void put(int key, int value) = 0;
    virtual int operator[](int key) = 0;
};

#endif
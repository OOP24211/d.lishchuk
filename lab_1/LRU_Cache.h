#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>
#include <list>

#include "ICache.h"

class LRU_Cache : public ICache {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map;
    std::list<std::pair<int, int>> cache_list;
    const size_t cache_size;
public:
    explicit LRU_Cache(size_t n);
    int get(int key) override;
    void put(int key, int value) override;
    int operator[](int key) override;
};
#endif
#ifndef LFU_CACHE_H
#define LFU_CACHE_H

#include "ICache.h"

class LFU_Cache : public ICache {
private:
    std::unordered_map<int, std::pair<int, int>> cache_map;
    std::unordered_map<int, std::list<int>> freq_map;
    const size_t cache_size;
    int min_frequency;
    size_t cnt_keys;
public:
    explicit LFU_Cache(size_t n);
    int get(int key) override;
    void put(int key, int value) override;
    int operator[](int key) override;
};

#endif

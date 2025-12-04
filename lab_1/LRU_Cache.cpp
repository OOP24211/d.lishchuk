#include "LRU_Cache.h"

LRU_Cache::LRU_Cache(size_t n) : cache_size(n) {}

int LRU_Cache::get(int key) {
    auto i = cache_map.find(key);
    if (i == cache_map.end()) {
        return -1;
    }
    cache_list.splice(cache_list.begin(), cache_list, i->second);
    return i->second->second;
}

void LRU_Cache::put(int key, int value) {
    if (cache_list.size() == cache_size) {
        cache_map.erase(cache_list.back().first);
        cache_list.pop_back();
    }
    cache_list.push_front({key, value});
    cache_map[key] = cache_list.begin();
}

int LRU_Cache::operator[](int key) {
    return get(key);
}

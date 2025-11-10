#include "LFU_Cache.h"

LFU_Cache::LFU_Cache(size_t n) : cache_size(n), min_frequency(0), cnt_keys(0) {}

int LFU_Cache::get(int key) {
    auto i = cache_map.find(key);
    if (i == cache_map.end()) {
        return -1;
    }
    int value =i->second.first;
    int freq = i->second.second;
    i->second.second += 1;
    freq_map[freq].remove(key);
    if (freq_map[freq].empty()) {
        freq_map.erase(freq);
        if (min_frequency == freq) {
            min_frequency += 1;
        }
    }
    freq_map[freq+1].push_back(key);
    return value;
}

void LFU_Cache::put(int key, int value) {
    if (cnt_keys == cache_size) {
        auto& min_freq_list = freq_map[min_frequency];
        int key_to_remove = min_freq_list.front();
        min_freq_list.pop_front();
        cache_map.erase(key_to_remove);
        if (min_freq_list.empty()) {
            freq_map.erase(min_frequency);
        }
        cnt_keys -= 1;
    };
    cache_map[key] = {value,1};
    freq_map[1].push_back(key);
    min_frequency = 1;
    cnt_keys += 1;
}

int LFU_Cache::operator[](int key) {
    return get(key);
}

#include <iostream>
#include "LRU_Cache.h"
#include "LFU_Cache.h"
#include "fibonachi.h"

int main() {
    std::cout << "Type size of cache: \n";
    int cache_size;
    std::cin >> cache_size;
    if (cache_size < 1) {
        std::cout << "Error";
        return 0;
    }
    std::cout << "Choose: \n 1: LRU-Cache \t 2: LFU-Cache";
    int cache_type;
    std::cin >> cache_type;
    if (cache_type == 1) {
        LRU_Cache cache(cache_size);
        std::cout<<"Type '0' for exit\n";
        int n = 0;
        while(1){
            std::cin >> n;
            if(n==0)return 0;
            n = fibonachi(n,cache);
            std::cout << n;
        }

    } else if (cache_type == 2) {
        LFU_Cache cache(cache_size);
        std::cout<<"Type '0' for exit\n";
        int n = 0;
        while(1){
            std::cin >> n;
            if(n==0)return 0;
            n = fibonachi(n,cache);
            std::cout << n;
        }

    }
    else {
        std::cout << "Error";
        return 0;
    }
}
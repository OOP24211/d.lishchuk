#include <gtest/gtest.h>
#include "LRU_Cache.h"
#include "LFU_Cache.h"

TEST(CacheTest, LRUCacheTest) {
    LRU_Cache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);

    EXPECT_EQ(cache.get(1), 1);


    cache.put(4, 4);
    EXPECT_EQ(cache.get(2), -1);

    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(CacheTest, LRUCacheTest_hard) {
    LRU_Cache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);

    EXPECT_EQ(cache.get(1), 1);
    cache.get(1);
    cache.get(1);
    cache.get(2);
    cache.get(3); //несмотря на то что мы так часто обращаепмся к единичке, вылететь по лру должна именно она
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
}

TEST(CacheTest, LFUCacheTest) {
    LFU_Cache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(3), 3);

    cache.get(1);
    cache.get(3);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(2), -1);

    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(CacheTest, LFUCacheTest_hard) {
    LFU_Cache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);

    EXPECT_EQ(cache.get(1), 1);
    cache.get(1);
    cache.get(2);
    cache.get(2);
    cache.get(3);//несмотря на то что мы последними обращались к тройке, вылетит она первой, т.к. к ней мы обращались редко
    cache.put(4, 4);
    EXPECT_EQ(cache.get(3), -1);
}
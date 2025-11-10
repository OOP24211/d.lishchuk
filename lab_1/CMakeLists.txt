cmake_minimum_required(VERSION 3.10)
project(CacheTests)

set(CMAKE_CXX_STANDARD 17)

# Указываем путь к исходным файлам и библиотекам
add_executable(run_tests test_cache.cpp LRU_Cache.cpp LFU_Cache.cpp fibonachi.cpp)

# Включаем Google Test
add_subdirectory(external/googletest)

# Линкуем с библиотеками
target_link_libraries(run_tests gtest gtest_main)


cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 17)
# Указываем путь к папке с SFML
include_directories("${CMAKE_SOURCE_DIR}/SFML-2.6.2/include")
link_directories("${CMAKE_SOURCE_DIR}/SFML-2.6.2/lib")


# Создаём исполнимый файл
add_executable(lab2 main.cpp Enemy.h Enemy_Manager.h Player.h Enemy.cpp Enemy_Manager.cpp Player.cpp)

# Линковка с библиотеками SFML
target_link_libraries(lab2 sfml-graphics sfml-window sfml-system)

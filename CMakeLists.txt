cmake_minimum_required(VERSION 3.10)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Настройки для Linux
if(UNIX AND NOT APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath,$ORIGIN")
    add_definitions(-DLINUX)
endif()

# Поиск SFML
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Исполняемый файл
add_executable(SnakeGame
    src/main.cpp
    src/Game.cpp
    src/Snake.cpp
    src/Food.cpp
)

# Подключение заголовков
target_include_directories(SnakeGame PRIVATE include)

# Линковка библиотек
target_link_libraries(SnakeGame PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    pthread
)

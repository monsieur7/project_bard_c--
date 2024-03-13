cmake_minimum_required(VERSION 3.0)

project(project_bard)
set(HEADERS headers/case.hpp headers/draw.hpp headers/ncurses_draw.hpp headers/maze.hpp headers/load.hpp headers/load_default.hpp)
set(SRC src/case.cpp src/ncurses_draw.cpp src/maze.cpp src/load_default.cpp)
set(SOURCES main.cpp ${HEADERS} ${SRC})

add_executable(project_bard ${SOURCES})
target_link_libraries(project_bard ncurses)

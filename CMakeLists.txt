cmake_minimum_required(VERSION 3.0)

project(project_bard)
set(HEADERS headers/case.hpp headers/draw.hpp headers/ncurses_draw.hpp headers/maze.hpp)
set(SRC src/case.cpp src/ncurses_draw.cpp src/maze.cpp)
set(SOURCES main.cpp ${HEADERS} ${SRC})

add_executable(project_bard ${SOURCES})
target_link_libraries(project_bard ncurses)

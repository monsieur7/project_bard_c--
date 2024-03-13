#pragma once // same as ifndef, define, endif
#include "maze.hpp"
#include "draw.hpp"
#include <ncurses.h>

class Ncurses_draw : public Draw
{
public:
    Ncurses_draw();
    ~Ncurses_draw();
    void drawMaze(Maze &maze) override;
};

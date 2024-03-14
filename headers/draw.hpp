#ifndef DRAW_HPP
#define DRAW_HPP
#include "maze.hpp"
class Draw
{
    virtual void drawMaze(Maze &maze) = 0;
    virtual void clear() = 0;
};
#endif

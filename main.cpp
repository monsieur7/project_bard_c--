#include <iostream>
#include "headers/maze.hpp"
#include "headers/ncurses_draw.hpp"
#include "headers/load_default.hpp"
#include "headers/sensehat_draw.hpp"
// we are using composition here
// see this video : https://www.youtube.com/watch?v=hxGOiiR9ZKg for more information
int main()
{
    Maze m;
    try
    {
        m = Load_default().loadMaze("../maze.txt");
    }
    catch (const std::exception &e)
    {
        return 1;
    }

    Sensehat_draw senseDraw;
    senseDraw.drawMaze(m);
    m.move(0, 1);
    senseDraw.drawMaze(m);
    getchar();

    return 0;
}

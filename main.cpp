#include <iostream>
#include "headers/maze.hpp"
#include "headers/ncurses_draw.hpp"
// we are using composition here
// see this video : https://www.youtube.com/watch?v=hxGOiiR9ZKg for more information
int main()
{
    Maze m(10, 10);
    m.loadMaze("maze.txt");
    Ncurses_draw d;

    d.drawMaze(m);
    getchar();

    return 0;
}

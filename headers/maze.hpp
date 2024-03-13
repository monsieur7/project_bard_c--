#include <vector>
#include <iostream>
#include "case.hpp"
#include <ncurses.h>
#ifndef MAZE_HPP
#define MAZE_HPP
class Maze
{
private:
    std::vector<std::vector<Case>> cases;
    // see https://www.algosome.com/articles/maze-generation-depth-first.html
    std::vector<Case *> stack;
    int width;
    int height;
    std::vector<Case *> getNeighbours(int x, int y);
    void removeWalls(int x, int y);
    void setVisited(int x, int y, bool value);
    bool getVisited(int x, int y) const;

public:
    Maze(int width, int height);
    Maze(const Maze &m);
    void setWall(int x, int y, bool value);
    bool getWall(int x, int y) const;

    void print();
    int getWidth() const;
    int getHeight() const;
    const Case &getCase(int x, int y) const;
    friend std::ostream &operator<<(std::ostream &os, const Maze &m);
    void generate(int x, int y, int tx, int ty);
    void setStart(int x, int y);
    void setEnd(int x, int y);
};
#endif
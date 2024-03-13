#pragma once
#include "maze.hpp"
#include <string>
// we are using composition here

class Load
{

public:
    Load() = default;
    ~Load() = default;
    virtual Maze loadMaze(const std::string &filename) = 0;
};
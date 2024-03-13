#pragma once
#include "maze.hpp"
#include <string>
#include "load.hpp"

class Load_default : public Load
{
public:
    Load_default() = default;
    ~Load_default() = default;
    Maze loadMaze(const std::string &filename) override;
};
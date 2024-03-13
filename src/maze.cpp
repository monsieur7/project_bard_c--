#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <set>
#include <unistd.h>
#include <fstream>

#include "../headers/maze.hpp"

Maze::Maze(int width, int height)
{
    this->width = width;
    this->height = height;
    cases.resize(height);
    for (int i = 0; i < height; i++)
    {
        cases[i].resize(width);
        for (int j = 0; j < width; j++)
        {
            cases[i][j].setX(j);
            cases[i][j].setY(i);
        }
    }

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            cases[i][j].setWall(true);
            cases[i][j].setWall(true);
            cases[i][j].setWall(true);
            cases[i][j].setWall(true);
        }
    }
}
Maze::Maze(const Maze &m)
{
    this->width = m.width;
    this->height = m.height;
    cases.resize(height);
    for (int i = 0; i < height; i++)
    {
        cases[i].resize(width);
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cases[i][j] = m.cases[i][j];
        }
    }
}
void Maze::setWall(int x, int y, bool value)
{
    cases[y][x].setWall(value);
}
bool Maze::getWall(int x, int y) const
{
    return cases[y][x].getWall();
}
void Maze::setVisited(int x, int y, bool value)
{
    cases[y][x].setVisited(value);
}
bool Maze::getVisited(int x, int y) const
{
    return this->cases[y][x].getVisited();
}
void Maze::print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << cases[i][j];
        }
    }
}
int Maze::getWidth() const
{
    return width;
}
int Maze::getHeight() const
{
    return height;
}
const Case &Maze::getCase(int x, int y) const
{
    return cases[y][x];
}
std::ostream &operator<<(std::ostream &os, const Maze &m)
{
    for (int i = 0; i < m.height; i++)
    {
        for (int j = 0; j < m.width; j++)
        {
            os << m.cases[i][j];
        }
        os << std::endl;
    }
    return os;
}
void Maze::generate(int x, int y, int tx, int ty)
{
    // TODO :
}

std::vector<Case *> Maze::getNeighbours(int x, int y)
{
    std::vector<Case *> neighbours;
    if (x > 0)
    {
        neighbours.push_back(&cases[y][x - 1]);
    }
    if (x < width - 1)
    {
        neighbours.push_back(&cases[y][x + 1]);
    }
    if (y > 0)
    {
        neighbours.push_back(&cases[y - 1][x]);
    }
    if (y < height - 1)
    {
        neighbours.push_back(&cases[y + 1][x]);
    }
    // remove all visited neighbours :
    neighbours.erase(std::remove_if(neighbours.begin(), neighbours.end(), [](Case *c)
                                    { return c->getVisited(); }),
                     neighbours.end());

    std::random_device rd;
    std::mt19937 g(rd());
    // seed the random number generator :
    g.seed(time(0));
    // shuffle the neighbours : (3 times to make it more random)
    std::shuffle(neighbours.begin(), neighbours.end(), g);

    return neighbours;
}

void Maze::removeWalls(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        return;
    }

    this->cases[y][x].setWall(false);
}

void Maze::setStart(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        return;
    }
    cases[y][x].setState(STATE::START);
    return;
}
void Maze::setEnd(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        return;
    }
    cases[y][x].setState(STATE::END);
    return;
}

void Maze::loadMaze(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    int i = 0;
    // set maze size :
    std::getline(file, line);
    this->width = line.size();
    // count the number of lines in the file :
    int count = 0;
    while (std::getline(file, line))
    {
        count++;
    }
    this->height = count + 1;
    // resize the cases vector :
    cases.resize(height);
    for (int i = 0; i < height; i++)
    {
        cases[i].resize(width);
        for (int j = 0; j < width; j++)
        {
            cases[i][j].setX(j);
            cases[i][j].setY(i);
        }
    }
    // reset the file pointer to the beginning of the file :
    file.clear();
    file.seekg(0, std::ios::beg);
    i = 0;
    while (std::getline(file, line))
    {
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] == 'X')
            {
                cases[i][j].setWall(true);
            }
            else if (line[j] == 'S')
            {
                cases[i][j].setState(STATE::START);
            }
            else if (line[j] == 'E')
            {
                cases[i][j].setState(STATE::END);
            }
            else
            {
                cases[i][j].setWall(false);
            }
        }
        i++;
    }
    file.close();
}

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
    this->ball_x = 0;
    this->ball_y = 0;
    this->end_x = 0;
    this->end_y = 0;
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
    //   this->width = m.width;
    //   this->height = m.height;
    // TODO : redo this
    cases.resize(height);
    this->end_x = 0;
    this->end_y = 0;
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
Maze::Maze()
{
    this->width = 0;
    this->height = 0;
    this->cases.resize(0);
    this->ball_x = 0;
    this->ball_y = 0;
    this->end_x = 0;
    this->end_y = 0;
}
void Maze::setWall(int x, int y, bool value)
{
    cases[y][x].setWall(value);
}
bool Maze::getWall(int x, int y) const
{
    if(x < 0 || y < 0 ||y >= width || x >= width){
        return true; // we(ve hit a wall ! THE SCREEN BORDER !

    }
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
    this->ball_x = x;
    this->ball_y = y;
    return;
}
void Maze::setEnd(int x, int y)
{
    this->end_x = x;
    this->end_y = y;
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        return;
    }
    cases[y][x].setState(STATE::END);
    return;
}

void Maze::move(int x, int y) // x and y are relative movement !
{
    // Check for walls in the path of movement
    if (x != 0)
    {
        int step = (x > 0) ? 1 : -1;
        for (int i = ball_x; i != (ball_x+x); i += step)
        {
            if (getWall(i + step, ball_y))
            {
                // Stop before the wall
                ball_x = i;
                return;
            }
        }
    }
    else if (y != 0)
    {
        int step = (y > 0) ? 1 : -1;
        for (int i = ball_y; i != (ball_y + y); i += step)
        {
            if (getWall(ball_x, i + step))
            {
                // Stop before the wall
                ball_y = i;
                return;
            }
        }
    }

    // Update the ball's position if there are no walls blocking the movement
    ball_x += x;
    ball_y += y;

    // Ensure the ball stays within the maze boundaries
    if (ball_x < 0)
        ball_x = 0;
    else if (ball_x >= width)
        ball_x = width - 1;

    if (ball_y < 0)
        ball_y = 0;
    else if (ball_y >= height)
        ball_y = height - 1;
}

int Maze::getBallX() const{
    return ball_x;
}

int Maze::getBallY() const{
    return ball_y;
}
 int Maze::getEndX() const {
    return end_x;
}
int Maze::getEndY() const{
    return end_y;
}
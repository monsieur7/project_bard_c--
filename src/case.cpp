#include "../headers/case.hpp"

Case::Case()
{
    visited = false;
}

void Case::setWall(bool value)
{
    state = value ? STATE::WALL : STATE::EMPTY;
}

bool Case::getWall() const
{
    return state == STATE::WALL;
}

void Case::setVisited(bool value)
{
    visited = value;
}

bool Case::getVisited() const
{
    return visited;
}

void Case::print()
{
    if (state == STATE::WALL)
    {
        std::cout << "X";
    }
    else if (state == STATE::EMPTY)
    {
        std::cout << "\u25A0";
    }
    else if (state == STATE::VISITED)
    {
        std::cout << " ";
    }
    else if (state == STATE::START)
    {
        std::cout << "S";
    }
    else if (state == STATE::END)
    {
        std::cout << "E";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Case &c)
{
    if (c.state == STATE::WALL)
    {
        os << "X";
    }
    else if (c.state == STATE::EMPTY)
    {
        os << "\u25A0";
    }
    else if (c.state == STATE::VISITED)
    {
        os << " ";
    }
    else if (c.state == STATE::START)
    {
        os << "S";
    }
    else if (c.state == STATE::END)
    {
        os << "E";
    }

    return os;
}
void Case::setX(int x)
{
    this->x = x;
}
void Case::setY(int y)
{
    this->y = y;
}
int Case::getX() const
{
    return x;
}
int Case::getY() const
{
    return y;
}

void Case::setState(STATE state)
{
    this->state = state;
}

STATE Case::getState() const
{
    return state;
}
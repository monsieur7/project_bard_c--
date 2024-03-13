#include <array>
#include <ostream>
#include <iostream>
#ifndef CASE_HPP
#define CASE_HPP

enum class STATE
{
    WALL,
    EMPTY,
    VISITED,
    START,
    END
};

class Case
{
private:
    STATE state;
    bool visited;
    int x, y;

public:
    Case();
    void setWall(bool value);
    bool getWall() const;
    void setState(STATE state);
    STATE getState() const;
    void setVisited(bool value);
    bool getVisited() const;
    void print();
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    friend std::ostream &operator<<(std::ostream &os, const Case &c);
};
#endif
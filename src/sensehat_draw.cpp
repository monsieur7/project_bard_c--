#include <exception> // Add missing include
#include "../headers/sensehat_draw.hpp"
Sensehat_draw::Sensehat_draw()
{
    if (!senseInit())
    {
        throw std::runtime_error("could not initialiser senseHat !"); // Replace Exception with std::exception
    }
    this->screen_height = 8;
    this->screen_width = 8;
}

Sensehat_draw::~Sensehat_draw()
{
    senseShutdown();
}
void Sensehat_draw::drawMaze(const Maze &m)
{
    if (m.getHeight() != this->screen_height || m.getWidth() != this->screen_width)
    {
        throw std::runtime_error("maze size does not match screen size");
    }
    for (int i = 0; i < this->screen_height; i++)
    {
        for (int j = 0; j < this->screen_width; j++)
        {
            if (m.getWall(j, i))
            {
                senseSetPixel(i, j, this->red.color[_R], this->red.color[_G], this->red.color[_B]);
            }
            else if (m.getCase(j, i).getState() == STATE::START)
            {
                senseSetPixel(i, j, this->green.color[_R], this->green.color[_G], this->green.color[_B]);
            }
            else if (m.getCase(j, i).getState() == STATE::END)
            {
                senseSetPixel(i, j, this->pink.color[_R], this->pink.color[_G], this->pink.color[_B]);
            }
            else
            {
                senseSetPixel(i, j, this->blue.color[_R], this->blue.color[_G], this->blue.color[_B]);
            }
        }
    }
    // draw ball
    senseSetPixel(m.getBallY(), m.getBallX(), this->orange.color[_R], this->orange.color[_G], this->orange.color[_B]);
}

void Sensehat_draw::clear()
{
    senseClear();
}
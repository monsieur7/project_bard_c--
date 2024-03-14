#include "draw.hpp"
#include <sensehat.h>
#include "maze.hpp"

class Sensehat_draw
{
private:
    int screen_height;
    int screen_width;
    const rgb_pixel_t red = {.color = {255, 0, 0}};
    const rgb_pixel_t orange = {.color = {255, 128, 0}};
    const rgb_pixel_t yellow = {.color = {255, 255, 0}};
    const rgb_pixel_t green = {.color = {0, 255, 0}};
    const rgb_pixel_t cyan = {.color = {0, 255, 255}};
    const rgb_pixel_t blue = {.color = {0, 0, 255}};
    const rgb_pixel_t purple = {.color = {255, 0, 255}};
    const rgb_pixel_t pink = {.color = {255, 128, 128}};

public:
    Sensehat_draw();
    ~Sensehat_draw();
    void drawMaze(const Maze &m);
    void clear();
};
#include <iostream>
#include "headers/maze.hpp"
#include "headers/ncurses_draw.hpp"
#include "headers/load_default.hpp"
#include "headers/sensehat_draw.hpp"
#include "headers/gyro.hpp"

#include <chrono>
#include <thread>

// we are using composition here
// see this video : https://www.youtube.com/watch?v=hxGOiiR9ZKg for more information
int main()
{
    Maze m;
    try
    {
        m = Load_default().loadMaze("../maze1.txt");
    }
    catch (const std::exception &e)
    {
        return 1;
    }

    Sensehat_draw senseDraw;
    senseDraw.drawMaze(m);
    Gyro myGyro;
    int score = 0;
    while (1)
    {
        Orientation orientation = myGyro.getOrientation();
        std::string orientationStr;
        switch (orientation)
        {
        case Orientation::Up:
            orientationStr = "Up";
            m.move(1, 0);
            break;
        case Orientation::Down:
            orientationStr = "Down";
            m.move(-1, 0);
            break;
        case Orientation::Left:
            orientationStr = "Left";
            m.move(0, -1);
            break;
        case Orientation::Right:
            orientationStr = "Right";
            m.move(0, 1);
            break;
        default:
            orientationStr = "Unknown";
            break;
        }
        std::cout << orientationStr << std::endl;
        // sleep for 100ms :
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        myGyro.updateValues();
        senseDraw.drawMaze(m);
        if (m.getBallX() == m.getEndX() && m.getBallY() == m.getEndY())
        {
            score++;
            try
            {
                m = Load_default().loadMaze("../maze" + std::to_string((score % 3)+1 ) + ".txt");
            }
            catch (const std::exception &e)
            {
                return 1;
            }
        }
    }
    getchar();

    return 0;
}
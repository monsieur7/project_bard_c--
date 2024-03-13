#include "../headers/load_default.hpp"
#include <fstream>
#include <iostream>

Maze Load_default::loadMaze(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        throw std::runtime_error("Error: could not open file " + filename);
    }
    std::string line;
    std::getline(file, line);
    int width = line.size();

    // count the number of lines in the file :
    int count = 0;
    while (std::getline(file, line))
    {
        count++;
    }
    int height = count + 1; // we add 1 because we already read the first line
    Maze m(width, height);

    // reset the file pointer to the beginning of the file :
    file.clear();
    file.seekg(0, std::ios::beg);
    int i = 0;
    while (std::getline(file, line))
    {
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] == 'X')
            {
                m.setWall(j, i, true);
            }
            else if (line[j] == 'S')
            {
                m.setStart(j, i);
            }
            else if (line[j] == 'E')
            {
                m.setEnd(j, i);
            }
            else
            {
                m.setWall(j, i, false);
            }
        }
        i++;
    }
    file.close();
    return m;
}

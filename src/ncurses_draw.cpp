#include "../headers/ncurses_draw.hpp"

Ncurses_draw::Ncurses_draw()
{
    // Start ncurses
    initscr();
    // Don't echo any keypresses
    noecho();
    // Don't display the cursor
    curs_set(0);
    // Enable keypad mode
    keypad(stdscr, TRUE);
    // Start color
    start_color();
    // Initialize color pairs
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    //...
}

Ncurses_draw::~Ncurses_draw()
{
    // restore the terminal to its original operating mode
    curs_set(1);
    echo();
    // End ncurses
    endwin();
}

void Ncurses_draw::drawMaze(Maze &maze)
{
    for (int i = 0; i < maze.getHeight(); i++)
    {
        for (int j = 0; j < maze.getWidth(); j++)
        {
            if (maze.getWall(j, i))
            {
                attron(COLOR_PAIR(1));
                mvprintw(i, j, " ");
                attroff(COLOR_PAIR(1));
            }
            else if (maze.getCase(j, i).getState() == STATE::START || maze.getCase(j, i).getState() == STATE::END)
            {
                attron(COLOR_PAIR(3));
                mvprintw(i, j, " ");
                attroff(COLOR_PAIR(3));
            }
            else
            {
                attron(COLOR_PAIR(2));
                mvprintw(i, j, " ");
                attroff(COLOR_PAIR(2));
            }
        }
    }
    refresh();
}
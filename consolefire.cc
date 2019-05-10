#include <cstdlib>
#include <curses.h>
#include <unistd.h>

#include "fire.hh"

int main()
{
    std::system("clear");
    initscr();
    curs_set(0);
    Fire fire;
    fire.start();
    for (int i = 0; i < 1000; i++)
    {
        fire.spread();
        wmove(stdscr, 0, 0);
        wrefresh(stdscr);
        fire.draw();
        usleep(25000);
    }
    fire.stop();
    for (int i = 0; i < 100; i++)
    {
        fire.spread();
        wmove(stdscr, 0, 0);
        wrefresh(stdscr);
        fire.draw();
        usleep(9000);
    }
    endwin();
    return 0;
}

#include <cstdlib>
#include <curses.h>
#include <unistd.h>

#include "fire.hh"

int main()
{
    std::system("clear");
    initscr();
    use_default_colors();
    noecho();
    cbreak();
    timeout(0);
    curs_set(0);
    Fire fire(COLS, LINES);
    fire.init_colors();
    fire.start();
    //for (int i = 0; i < 1000; i++)
    while (getch() != 'a')
    {
        fire.spread();
        wmove(stdscr, 0, 0);
        wrefresh(stdscr);
        fire.draw();
        usleep(25000);
    }
    fire.stop();
    for (int i = 0; i < 80; i++)
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

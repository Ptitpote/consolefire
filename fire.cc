#include <iostream>
#include <curses.h>

#include "fire.hh"

#define WIDTH 80
#define HEIGHT 50

// Index = Row * Width + Column

Fire::Fire()
    : f_(WIDTH * HEIGHT, 0)
{
    for (size_t j = 0; j < WIDTH; j++)
    {
        f_[(HEIGHT - 1) * WIDTH + j] = 36;
    }
}

void Fire::start()
{
    for (size_t j = 0; j < WIDTH; ++j)
    {
        f_[(HEIGHT - 1) * WIDTH + j] = 36;
    }
}


void Fire::stop()
{
    for (size_t j = 0; j < WIDTH; ++j)
    {
        f_[(HEIGHT - 1) * WIDTH + j] = 0;
    }
}

void Fire::draw()
{
    //a bit dirty but keep it this way for now
    for (size_t i = 1; i < HEIGHT - 1; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            if (f_[i * WIDTH + j] > 0 && f_[i * WIDTH + j] <= 36)
                print_flame(f_[i * WIDTH + j]);
            else
                waddch(stdscr, ' ');
        }
        wmove(stdscr, i - 1, 0);
        wrefresh(stdscr);
    }
}

void Fire::spread()
{
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            compute_spread(i * WIDTH + j);
        }
    }
}

void Fire::compute_spread(size_t src)
{
    auto random = (std::rand()) & 3;
    auto dst = src - random + 1;
    if (dst > HEIGHT * WIDTH or dst < WIDTH)
        return;
    f_.at(dst - WIDTH) = f_[src] - random;
}


void Fire::print_flame(int flame)
{
    if (flame <= 9)
    {
        waddch(stdscr, flame + '0');
    }
    else
    {
        waddch(stdscr, flame - 10 + 'A');
    }
}

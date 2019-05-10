#include <iostream>
#include <curses.h>

#include "fire.hh"

// Index = Row * Width + Column

Fire::Fire(std::size_t width, std::size_t height)
    : width_(width)
    , height_(height)
    , f_(width_ * height_, 0)
{
    for (size_t j = 0; j < width_; j++)
    {
        f_[(height_ - 1) * width_ + j] = 36;
    }
}

void Fire::start()
{
    for (size_t j = 0; j < width_; ++j)
    {
        f_[(height_ - 1) * width_ + j] = 36;
    }
}


void Fire::stop()
{
    for (size_t j = 0; j < width_; ++j)
    {
        f_[(height_ - 1) * width_ + j] = 0;
    }
}

void Fire::draw()
{
    //a bit dirty but keep it this way for now
    for (size_t i = 1; i < height_ - 1; i++)
    {
        for (size_t j = 0; j < width_; j++)
        {
            if (f_[i * width_ + j] > 0 && f_[i * width_ + j] <= 36)
                print_flame(f_[i * width_ + j]);
            else
                waddch(stdscr, ' ');
        }
        wmove(stdscr, i - 1, 0);
        wrefresh(stdscr);
    }
}

void Fire::spread()
{
    for (size_t i = 0; i < height_; i++)
    {
        for (size_t j = 0; j < width_; j++)
        {
            compute_spread(i * width_ + j);
        }
    }
}

void Fire::compute_spread(size_t src)
{
    auto random = (std::rand()) & 3;
    auto dst = src - random + 1;
    if (dst > height_ * width_ or dst < width_)
        return;
    f_.at(dst - width_) = f_[src] - random;
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

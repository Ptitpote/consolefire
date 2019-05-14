#pragma once

#include <vector>

class Fire {
public:
    Fire(std::size_t width, std::size_t height);

    ~Fire() = default;

    void spread();

    void draw();

    void start();

    void stop();

    void init_colors();

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<int> f_;

    void compute_spread(size_t src);

    void print_flame(int flame);
};

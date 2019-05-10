#pragma once

#include <vector>

class Fire
{
    public:
        Fire();
        ~Fire() = default;
        void spread();
        void draw();
        void start();
        void stop();

    private:
        std::vector<int> f_;
        void compute_spread(size_t src);
        void print_flame(int flame);
};

#ifndef LAPSE_H
#define LAPSE_H

#include <chrono>

namespace lapse {
    class Lapse {
    private:
        int total;
        int current;
        int width;
        std::chrono::steady_clock::time_point start_time;

    public:
        Lapse(int total, int width = 50);
        void update(int N = 1);
    };
}

#endif
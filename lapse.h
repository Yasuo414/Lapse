#ifndef LAPSE_H
#define LAPSE_H

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

namespace lapse {

class Lapse {
private:
    int total;
    int current;
    int width;
    std::chrono::steady_clock::time_point start_time;

public:
    Lapse(int total, int width = 50) : total(total), current(0), width(width) {
        start_time = std::chrono::steady_clock::now();
    }

    void update(int n = 1) {
        current += n;
        if (current > total) current = total;

        float progress = static_cast<float>(current) / total;
        int pos = static_cast<int>(width * progress);

        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();

        std::cout << "[";
        for (int i = 0; i < width; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << "% "
                  << current << "/" << total
                  << " (" << elapsed << "s)\r";
        std::cout.flush();

        if (current == total) std::cout << std::endl;
    }
};

}

#endif
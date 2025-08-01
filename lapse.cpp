#include "lapse.h"
#include <iostream>

namespace lapse {
    Lapse::Lapse(int total, int width) : total(total), current(0), width(width) {
        start_time = std::chrono::steady_clock::now();
    }

    void Lapse::update(int N) {
        current += N;

        if (current > total) {
            current = total;
        }

        float progress = static_cast<float>(current) / total;
        int position = static_cast<int>(width * progress);

        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();

        std::cout << "[";
        for (int i = 0; i < width; ++i) {
            if (i < position) {
                std::cout << "=";
            } else if (i == position) {
                std::cout << ">";
            } else {
                std::cout << " ";
            }
        }

        std::cout << "] " << int(progress * 100.0) << "% " << current << "/" << total << " (" << elapsed << "s)\r";
        std::cout.flush();

        if (current == total) {
            std::cout << std::endl;
        }
    }
}
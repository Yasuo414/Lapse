#include <thread>
#include "lapse.h"

int main() {
    int total = 100;
    lapse::Lapse width(total);

    for (int i = 0; i < total; ++i) {
        width.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
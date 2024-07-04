# TQDM in C++
Lapse is a simple library for creating a progress bar, like the TQDM library in Python.

# Open-Source
Lapse is a full open-source library.
Edit, tweak at will, but please leave credit for me.

# Include in your project
In the example.cpp file or here you can see how you can implement Lapse in your project.
´´
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
´´

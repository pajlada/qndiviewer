#include "ndifinder.hpp"

#include <functional>
#include <iostream>
#include <stdexcept>

NDIFinder::NDIFinder(std::function<void()> _cb)
    : cb(_cb)
{
    NDIlib_find_create_t createConfig;

    this->instance = NDIlib_find_create_v2(&createConfig);

    if (!this->instance) {
        throw std::runtime_error("Error creating NDI Finder");
    }

    this->instanceThread =
        std::make_unique<std::thread>(std::bind(&NDIFinder::RunThread, this));
}

NDIFinder::~NDIFinder()
{
    if (this->instance) {
        NDIlib_find_destroy(this->instance);
    }
}

void
NDIFinder::RunThread()
{
    while (true) {
        std::cout << "run thread xd\n";
    }
}

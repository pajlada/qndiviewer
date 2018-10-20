#pragma once

#include <Processing.NDI.Lib.h>

#include <functional>
#include <memory>
#include <thread>

class NDIFinder
{
public:
    NDIFinder(std::function<void()> _cb);
    ~NDIFinder();

private:
    void RunThread();

    std::function<void()> cb;

    NDIlib_find_instance_t instance;

    std::unique_ptr<std::thread> instanceThread;
};

#pragma once

#include <functional>
#include <mutex>
#include <vector>

class MessageQueue
{
public:
    MessageQueue();

    void Consume();

    void Append(std::function<void()> &&cb);

private:
    std::vector<std::function<void()>> cbs;
    std::mutex cbsMutex;
};

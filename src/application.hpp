#pragma once

#include "messagequeue.hpp"

#include <functional>

class Application
{
public:
    Application();

    void Run();

    void Send(std::function<void()> &&cb);

    bool quit{};

private:
    void ConstructCTRLCHandler();

    MessageQueue messageQueue;
};

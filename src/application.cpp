#include "application.hpp"

#include "ndifinder.hpp"

#include <Processing.NDI.Lib.h>

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

bool sendQuit = false;

void
my_handler(int s)
{
    sendQuit = true;
}

Application::Application()
{
    this->ConstructCTRLCHandler();
}

void
Application::Run()
{
    NDIFinder finder([this] { this->Send() });

    std::cout << "Application running\n";
    while (!this->quit) {
        this->messageQueue.Consume();

        if (sendQuit) {
            this->Send([this] { this->quit = true; });
        }
    }

    std::cout << "Application quitting\n";
}

void
Application::Send(std::function<void()> &&cb)
{
    this->messageQueue.Append(std::move(cb));
}

void
Application::ConstructCTRLCHandler()
{
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
}

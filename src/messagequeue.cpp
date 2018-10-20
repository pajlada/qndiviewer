#include "messagequeue.hpp"

#include <iostream>

MessageQueue::MessageQueue()
{
    // ???
}

void
MessageQueue::Consume()
{
    static std::vector<std::function<void()>> tmp;
    // this might be locking for too long. maybe just swap the vector
    // std::cout << "consume lock\n";
    this->cbsMutex.lock();
    // std::lock_guard<std::mutex> lock(this->cbsMutex);

    if (!this->cbs.empty()) {
        std::cout << "swap\n";
        this->cbs.swap(tmp);
    }

    // std::cout << "consume unlocked\n";

    for (const auto &cb : tmp) {
        std::cout << "run a lambda\n";
        cb();
    }

    tmp.clear();
    this->cbsMutex.unlock();
}

void
MessageQueue::Append(std::function<void()> &&cb)
{
    std::lock_guard<std::mutex> lock(this->cbsMutex);
    this->cbs.emplace_back(cb);
}

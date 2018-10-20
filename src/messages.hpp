#pragma once

enum class MessageType {
    Unknown,
    NDIFinderUpdate,
};

struct Message {
    MessageType messageType = MessageType::Unknown;
};

#include "EchoCommand.hpp"

#include <iostream>

EchoCommand::EchoCommand(const CommandLine& commandLine) : ICommand(commandLine) {}

void EchoCommand::parse() {
    bool isNextLine = true;
    size_t i = 0;

    for (;i < commandLine_.arguments.size() && commandLine_.arguments[i] == "-n"; ++i) {
        isNextLine = false;
    }

    for (; i < commandLine_.arguments.size(); ++i) {
        if (!commandLine_.arguments[i].empty()) {
            outputLine_ += commandLine_.arguments[i] + " ";
        }
    }

    for (const auto& other : commandLine_.other) {
        if (!other.empty()) {
            outputLine_ += other + " ";
        }
    }

    if (!outputLine_.empty()) {
        outputLine_.resize(outputLine_.size() - 1);
    }

    if (isNextLine) {
        outputLine_ += "\n";
    }
}

void EchoCommand::handle() {
    std::cout << outputLine_;
}
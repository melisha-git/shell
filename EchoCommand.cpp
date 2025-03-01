#include "EchoCommand.hpp"

#include <iostream>

EchoCommand::EchoCommand(CommandLine commandLine) : ICommand(commandLine) {}

void EchoCommand::handle() {
    std::string outputLine;

    bool isNextLine = true;
    size_t i = 0;

    for (;i < commandLine_.arguments.size() && commandLine_.arguments[i] == "-n"; ++i) {
        isNextLine = false;
    }

    for (; i < commandLine_.arguments.size(); ++i) {
        if (!commandLine_.arguments[i].empty()) {
            outputLine += commandLine_.arguments[i] + " ";
        }
    }

    for (const auto& other : commandLine_.other) {
        if (!other.empty()) {
            outputLine += other + " ";
        }
    }

    outputLine.resize(outputLine.size() - 1);

    if (isNextLine) {
        outputLine += "\n";
    }

    std::cout << outputLine;
}
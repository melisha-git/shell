#include "CommandLine.hpp"
#include "utility.h"
#include "ICommand.hpp"
#include "EchoCommand.hpp"

#include <iostream>
#include <string>
#include <memory>

std::unique_ptr<ICommand> getCommandClass(const CommandLine& commandLine) {
    switch (commandLine.type)
    {
    case CommandType::ECHO:
        return std::make_unique<EchoCommand>(commandLine);
    default:
        break;
    }
    return nullptr;
}

int main() {
    CommandLine cmd;
    std::string line;

    while (getline(std::cin, line)) {
        std::vector<std::string> strLines = utility::split(line);
        for (const auto& strCommand : strLines) {
            cmd.reinit(strCommand);
            std::unique_ptr<ICommand> command = getCommandClass(cmd);

            if (command != nullptr) {
                command->handle();
            }
        }
    }
}
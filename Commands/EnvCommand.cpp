#include "EnvCommand.hpp"

#include <unistd.h>
#include <iostream>

extern char** environ;

EnvCommand::EnvCommand(const CommandLine& commandLine) : ICommand(commandLine) {}

void EnvCommand::parse() {
    bool isDeclare = false;

    for (const auto& argument : commandLine_.arguments) {
        if (argument == "-x") {
            isDeclare = true;
            break;
        }
    }

    for (char** env = environ; *env != nullptr; ++env) {

        if (isDeclare) {
            outputLine_ += "declare -x \"";
        }

        outputLine_ += std::string(*env);

        if (isDeclare) {
            outputLine_ += "\"";
        }

        outputLine_ += "\n";
    }
}

void EnvCommand::handle() {
    std::cout << outputLine_;
}
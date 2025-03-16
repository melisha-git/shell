#include "ExitCommand.hpp"

#include <iostream>

ExitCommand::ExitCommand(const CommandLine& commandLine) : ICommand(std::move(commandLine)) {}

void ExitCommand::parse() {}

void ExitCommand::handle() {
    std::cout << "exit" << std::endl;
    exit(0);
}
#include "ICommand.hpp"

ICommand::ICommand(const CommandLine& commandLine) : commandLine_(std::move(commandLine)) {}

#include "UnsetCommand.hpp"

#include <cstdlib>

UnsetCommand::UnsetCommand(const CommandLine& commandLine) : ICommand(commandLine) {

}

void UnsetCommand::parse() {
    for (const auto& var : commandLine_.other) {
        unsetVariables_.push_back(var);
    }
}

void UnsetCommand::handle() {
    for (const auto& var : unsetVariables_) {
        unsetenv(var.c_str());
    }
}
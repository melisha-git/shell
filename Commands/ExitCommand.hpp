#pragma once

#include "ICommand.hpp"

class ExitCommand : public ICommand {
public:
    explicit ExitCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
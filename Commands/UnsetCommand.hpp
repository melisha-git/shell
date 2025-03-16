#pragma once

#include "ICommand.hpp"

class UnsetCommand : public ICommand {
public:
    explicit UnsetCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
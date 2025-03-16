#pragma once

#include "ICommand.hpp"

class PwdCommand : public ICommand {
public:
    explicit PwdCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
#pragma once

#include "ICommand.hpp"

class CdCommand : public ICommand {
public:
    explicit CdCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
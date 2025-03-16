#pragma once

#include "ICommand.hpp"

class EnvCommand : public ICommand {
public:
    explicit EnvCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
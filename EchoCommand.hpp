#pragma once

#include "ICommand.hpp"

class EchoCommand : public ICommand {
public:
    explicit EchoCommand(CommandLine commandLine);

    void handle() override final;
};
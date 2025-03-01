#pragma once

#include "CommandLine.hpp"

class ICommand {
public:
    explicit ICommand(CommandLine commandLine);

    virtual void handle() = 0;

    virtual ~ICommand() = default;
protected:
    CommandLine commandLine_;
};
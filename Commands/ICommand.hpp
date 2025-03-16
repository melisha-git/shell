#pragma once

#include "../CommandLine.hpp"

class ICommand {
public:
    explicit ICommand(const CommandLine& commandLine);

    virtual void parse() = 0;
    virtual void handle() = 0;

    virtual ~ICommand() = default;
protected:
    CommandLine commandLine_;
};
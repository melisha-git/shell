#pragma once

#include "ICommand.hpp"
#include <string>

class EchoCommand : public ICommand {
public:
    explicit EchoCommand(const CommandLine& commandLine);

    void handle() override final;
    void parse() override final;
private:
    std::string outputLine_;
};
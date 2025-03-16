#pragma once

#include "ICommand.hpp"

#include <string>
#include <vector>

class LsCommand : public ICommand {
public:
    explicit LsCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
private:
    std::vector<std::string> files_;
};
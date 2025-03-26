#pragma once

#include "ICommand.hpp"
#include <unordered_map>

class ExportCommand : public ICommand {
public:
    explicit ExportCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
private:
    std::unordered_map<std::string, std::string> newEnviroments_;
    std::unordered_map<std::string, bool> envIsEmpty_;
};
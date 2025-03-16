#pragma once

#include "ICommand.hpp"

class ExportCommand : public ICommand {
public:
    explicit ExportCommand(const CommandLine& commandLine);

    void parse() override final;
    void handle() override final;
};
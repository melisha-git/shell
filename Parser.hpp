#pragma once

#include "CommandLine.hpp"
#include "Commands/ICommand.hpp"

#include <string>
#include <memory>

class Parser {
public:
    Parser() = default;

    void init(const std::string& line);
    void init(const CommandLine& commandLine);

    void parse();

    void handle();

private:
    std::unique_ptr<ICommand> getCommandClass() const;
    static void replacingEnviroment(std::vector<std::string>& vc);

    CommandLine commandLine_;
};
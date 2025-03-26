#include "ExportCommand.hpp"
#include "../Parser.hpp"
#include "../utility.h"

#include <cstdlib>
#include <iostream>

ExportCommand::ExportCommand(const CommandLine& commandLine) : ICommand(commandLine) {}

void ExportCommand::parse() {
    for (const std::string& env : commandLine_.other) {
        std::vector<std::string> parseEnv = utility::split(env, '=');
        if (parseEnv.empty()) {
            continue;
        }

        newEnviroments_[parseEnv[0]];
        envIsEmpty_[parseEnv[0]] = false;

        if (parseEnv.size() == 1) {
            envIsEmpty_[parseEnv[0]] = true;
            continue;
        }

        newEnviroments_[parseEnv[0]] = parseEnv[1];
    }
}

void ExportCommand::handle() {
    if (!commandLine_.arguments.empty() || !commandLine_.other.empty()) {
        for (const auto& [key, value] : newEnviroments_) {
            if (value.empty() && envIsEmpty_[key] != true) {
                continue;
            }

            if (setenv(key.c_str(), value.c_str(), 1) != 0) {
                std::cerr << "Ошибка при установке переменной " << key << std::endl;
            }
        }

        return;
    }

    Parser parser;
    
    commandLine_.reinit("env -x");
    parser.init(commandLine_);
    parser.parse();
    parser.handle();
}
#include "Parser.hpp"
#include "Commands/EchoCommand.hpp"
#include "Commands/LsCommand.hpp"
#include "Commands/CdCommand.hpp"
#include "Commands/PwdCommand.hpp"
#include "Commands/ExportCommand.hpp"
#include "Commands/UnsetCommand.hpp"
#include "Commands/EnvCommand.hpp"
#include "Commands/ExitCommand.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

void Parser::init(const std::string& line) {
    commandLine_.reinit(line);
}

void Parser::init(const CommandLine& commandLine) {
    commandLine_ = commandLine;
}

void Parser::parse() {
    Parser::replacingEnviroment(commandLine_.arguments);
    Parser::replacingEnviroment(commandLine_.other);
}

void Parser::handle() {
    std::unique_ptr<ICommand> command = getCommandClass();
    if (command != nullptr) {
        command->parse();
        command->handle();
    }
}

std::unique_ptr<ICommand> Parser::getCommandClass() const {
    switch (commandLine_.type)
    {
    case CommandType::ECHO:
        return std::make_unique<EchoCommand>(commandLine_);
    case CommandType::LS:
        return std::make_unique<LsCommand>(commandLine_);
    case CommandType::CD:
        return std::make_unique<CdCommand>(commandLine_);
    case CommandType::PWD:
        return std::make_unique<PwdCommand>(commandLine_);
    case CommandType::EXPORT:
        return std::make_unique<ExportCommand>(commandLine_);
    case CommandType::UNSET:
        return std::make_unique<UnsetCommand>(commandLine_);
    case CommandType::ENV:
        return std::make_unique<EnvCommand>(commandLine_);
    case CommandType::EXIT:
        return std::make_unique<ExitCommand>(commandLine_);
    default:
        assert(false && "Command not processed");
    }
    return nullptr;
}

void Parser::replacingEnviroment(std::vector<std::string>& vc) {
    auto findEnviroment = [](std::string& value) {
        return std::find(value.begin(), value.end(), '$');
    };

    auto isReplace = [](const std::string::iterator& pos, const std::string& argument) {
        return  pos != argument.end() && std::next(pos) != argument.end() &&
                std::find(argument.begin(), argument.end(), '"') == argument.end() &&
                std::find(argument.begin(), argument.end(), '\'') == argument.end();
    };

    for (auto& argument : vc) {
        for (auto pos = findEnviroment(argument); isReplace(pos, argument); pos = findEnviroment(argument)) {
            std::string oldValue(std::next(pos), argument.end());
            char* enviromentVariable = std::getenv(oldValue.c_str());
            auto dist1 = std::distance(argument.begin(), pos);
            auto dist2 = std::distance(pos, argument.end());
            argument.replace(dist1, dist2, enviromentVariable == nullptr ? "" : enviromentVariable);
        }
    }
}
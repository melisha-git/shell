#include "PwdCommand.hpp"
#include "EchoCommand.hpp"
#include "../Parser.hpp"

PwdCommand::PwdCommand(const CommandLine& commandLine) : ICommand(std::move(commandLine)) {}

void PwdCommand::parse() {
    commandLine_.deinit();
    commandLine_.type = CommandType::ECHO;
    commandLine_.other.push_back("$PWD");
}

void PwdCommand::handle() {
    Parser parser;

    parser.init(commandLine_);
    parser.parse();
    parser.handle();
}
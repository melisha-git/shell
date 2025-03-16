#include "CommandLine.hpp"

#include <strstream>
#include <string>
#include "utility.h"

void CommandLine::init(const std::string& strCommand) {
    std::vector<std::string> words = utility::split(strCommand, ' ');

    if (words.empty()) {
        return;
    }

    if (words[0] == "echo") {
        type = CommandType::ECHO;
    } else if (words[0] == "cd") {
        type = CommandType::CD;
    } else if (words[0] == "pwd") {
        type = CommandType::PWD;
    } else if (words[0] == "export") {
        type = CommandType::EXPORT;
    } else if (words[0] == "unset") {
        type = CommandType::UNSET;
    } else if (words[0] == "env") {
        type = CommandType::ENV;
    } else if (words[0] == "exit") {
        type = CommandType::EXIT;
    } else if (words[0] == "ls") {
        type = CommandType::LS;
    } else {
        throw std::logic_error(words[0] + ": command not found");
    }

    size_t i = 1;

    for (; i < words.size() && words[i][0] == '-'; ++i) {   
        arguments.push_back(words[i]);
    }

    for (; i < words.size(); ++i) {   
        other.push_back(words[i]);
    }
}

void CommandLine::deinit() {
    type = CommandType::UNDEFINED;
    arguments.clear();
    other.clear();
}
    
void CommandLine::reinit(const std::string& strCommand) {
    deinit();
    init(strCommand);
}
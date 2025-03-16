#include "LsCommand.hpp"

#include <filesystem>
#include <iostream>
#include <algorithm>

LsCommand::LsCommand(const CommandLine& commandLine) : ICommand(commandLine) {}

void LsCommand::parse() {
    bool isAll = false;

    for (const auto& argument : commandLine_.arguments) {
        if (argument == "-a" || argument == "--all") {
            isAll = true;
            break;
        }
    }

    if (isAll) {
        files_.push_back(".");
        files_.push_back("..");
    }

    std::string path = std::getenv("PWD");
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string fileName = std::string(entry.path()).substr(path.size() + 1);
        if (!isAll && !fileName.empty() && fileName[0] == '.') {
            continue;
        }
        files_.push_back(fileName);
    }

    std::sort(files_.begin(), files_.end());
}

void LsCommand::handle() {
    for (const auto& fileName : files_) {
        std::cout << fileName << "  ";
    }
    std::cout << std::endl;
}
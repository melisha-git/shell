#pragma once

#include <string>
#include <vector>
#include <optional>

enum class CommandType : int {
    UNDEFINED = 0,
    ECHO,
    LS,
    CD,
    PWD,
    EXPORT,
    UNSET,
    ENV,
    EXIT
};

struct CommandLine {
    CommandType type = CommandType::UNDEFINED;
    std::vector<std::string> arguments;
    std::vector<std::string> other;

    void init(const std::string& strCommand);
    void deinit();
    void reinit(const std::string& strCommand);
};
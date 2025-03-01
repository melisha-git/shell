#pragma once

#include <vector>
#include <string>

namespace utility {
    std::vector<std::string> split(const std::string& line, char delim = '\n');
};
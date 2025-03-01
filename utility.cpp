#include "utility.h"

#include <sstream>

std::vector<std::string> utility::split(const std::string& line, char delim) {
    std::istringstream strStream(line.c_str());
    std::vector<std::string> result;

    std::string str;
    while (getline(strStream, str, delim)) {
        result.push_back(str);
    }
    
    return result;
}
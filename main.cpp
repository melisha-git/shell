#include "utility.h"
#include "Parser.hpp"

#include <iostream>
#include <string>
#include <memory>

int main() {
    Parser parser;
    std::string line;
    std::cout << "%: ";

    while (getline(std::cin, line)) {
        std::vector<std::string> strLines = utility::split(line);
        for (const auto& strCommand : strLines) {
            try {
                parser.init(line);
                parser.parse();
                parser.handle();
            } catch (const std::exception& ex) {
                std::cerr << ex.what() << std::endl;
            }
        }
        std::cout << "%: ";
        std::cout.flush();
    }
}
#include <iostream>
#include <string>

#include "config.hpp"

int main() {
    std::cout << "Console Apps" << std::endl;

    // implicit conversion and structured binding (C++17)
    Config::Version version = Config::GetVersion();
    std::string version_str = version;
    double version_double = version;
    auto [version_major, version_minor] = version;

    std::cout
        << "Version: " << version.major << "." << version.minor << std::endl
        << "Version: " << version_str << std::endl
        << "Version: " << version_double << std::endl;

    std::cout << "Input anything." << std::endl;
    std::string input_line;
    while(std::getline(std::cin, input_line)) {
        std::cout << "Your input is: " << input_line << std::endl;
    }

    std::cout << "Good-Bye!" << std::endl;
}

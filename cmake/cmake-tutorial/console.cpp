#include <iostream>
#include <string>
#include "config.hpp"

int main() {
    std::cout << "Console Apps" << std::endl;
    std::cout << "Version: " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Input anything." << std::endl;

    std::string input_line;
    while(std::getline(std::cin, input_line)) {
        std::cout << "Your input is: " << input_line << std::endl;
    }

    std::cout << "Good-Bye!" << std::endl;
}

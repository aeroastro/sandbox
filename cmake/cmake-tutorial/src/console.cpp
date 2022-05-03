#include <iostream>
#include <string>

int main() {
    std::cout << "Input anything." << std::endl;

    std::string input_line;
    while(std::getline(std::cin, input_line)) {
        std::cout << "Your input is: " << input_line << std::endl;
    }

    std::cout << "Good-Bye!" << std::endl;
}

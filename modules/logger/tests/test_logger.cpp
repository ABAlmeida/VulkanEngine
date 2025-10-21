#include "logger.hpp"

#include <iostream>
#include <cassert>

int main() {
    std::cout << "[LoggerTests] Running Logger module test..." << std::endl;
    try {
        Log("Logger test message");
    } catch (...) {
        std::cerr << "[LoggerTests] Exception thrown from Log()" << std::endl;
        return 1;
    }

    std::cout << "[LoggerTests] Logger module test passed." << std::endl;
    return 0;
}

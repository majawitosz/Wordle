#include <vector>
#include "Controller.h"

/**
 * @file main.cpp
 *
 * @brief This file contains the main() function which serves as the entry point of the program.
 */
int main(int argc, const char * argv[]) {
    std::vector<std::string> arguments;
    for (int i = 1; i<argc; i++) {
        arguments.push_back(std::string(argv[i]));
    }
    Controller controller;
    controller.controlArguments(arguments);
    system("pause");
    return 0;
}

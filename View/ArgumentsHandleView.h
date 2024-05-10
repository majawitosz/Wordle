//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_ARGUMENTSHANDLEVIEW_H
#define WORDLE_ARGUMENTSHANDLEVIEW_H


#include <iostream>
#include <string>
#include "../Data/ArgumentsDataMessage.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"

using namespace ftxui;
using namespace std::chrono_literals;

/**
 * @file ArgumentsHandleView.h
 * @brief Header file containing the ArgumentsHandleView class.
 */

/**
 * @class ArgumentsHandleView
 * @brief Responsible for displaying argument-related information to the user.
 */
class ArgumentsHandleView {
public:
    /**
     * @brief Displays help information.
     * @details static function is responsible for presenting help or usage information
     * to the user. It shows the correct way to use the application and describes
     * what each command-line argument does. The information is retrieved from the provided
     * ArgumentsData object.
     * @param newArgumentsData An ArgumentsData object containing information about the command-line arguments.
     */
    static void displayHelp(ArgumentsData &newArgumentsData);

    /**
     * @brief Displays loading screen.
     * @param newArgumentsData An ArgumentsData object containing information about the chosen method of representation for dictionary.
     */
    static void displayView(ArgumentsData &newArgumentsData);
};
#endif //WORDLE_ARGUMENTSHANDLEVIEW_H

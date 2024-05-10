//
// Created by Maja on 5/9/2024.
//
#pragma once
#ifndef WORDLE_ARGUMENTSDATAMESSAGE_H
#define WORDLE_ARGUMENTSDATAMESSAGE_H

#include <stdio.h>
#include <string>
/**
 * @file ArgumentsDataMessage.h
 * @brief Header file containing the ArgumentsData struct.
 */

/**
 * @struct ArgumentsData
 * @brief Holds data related to the command-line arguments.
 * @details structure is used to store information about the command-line arguments passed to the program.
 * It includes details about the file path, any message to be displayed, the result of argument processing,
 * and the chosen method of representation for the game.
 */
struct ArgumentsData {
    /**
     * @enum MethodOfRepresentation
     * @brief Defines the available methods of word representation in the game.
     */
    enum MethodOfRepresentation { vectorLinear, vectorBinary, set, unorderedSet };

    std::string filePath; /**< The file path provided as a command-line argument. */
    std::string message; /**< A message to be displayed, related to the processing of command-line arguments. */
    bool result; /**< The result of command-line argument processing (e.g., true if processing was successful). */
    MethodOfRepresentation methodOfRepresentation; /**< The chosen method of word representation. */
};

#endif //WORDLE_ARGUMENTSDATAMESSAGE_H

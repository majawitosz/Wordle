//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_ARGUMENTSHANDLELOGIC_H
#define WORDLE_ARGUMENTSHANDLELOGIC_H

#include "../Data/ArgumentsDataMessage.h"
#include "../View/ArgumentsHandleView.h"
#include <cstdio>
#include <vector>
#include <fstream>
/**
 * @file ArgumentsHandleLogic.h
 * @brief Header file containing the ArgumentsHandleLogic class.
 */

/**
 * @class ArgumentsHandleLogic
 * @brief This class is responsible for handling and validating command line arguments.
 */
class ArgumentsHandleLogic{
private:
    bool foundFirst; /**< Flag indicating whether the -p argument has been found. */
    bool foundSecond; /**< Flag indicating whether the -d argument has been found. */
    ArgumentsData aData; /**< Structure to hold and manage the data related to command-line arguments. */
public:
    /**
     * @brief Handles and validates command line arguments.
     * @details function handles and validates command line arguments passed as a vector of strings.
     * It checks for the presence of required arguments and sets the representation scheme based
     * on the provided arguments. If any validation fails, it throws an exception with the error message.
     * @param arguments The command line arguments passed as a vector of strings.
     * @throw ArgumentsData An exception containing the error message if any validation fails.
     */
    void handleArguments(const std::vector<std::string> &arguments);
    /**
     * @brief Sets the representation scheme in the ArgumentsData structure.
     * @details function sets the methodOfRepresentation field in the ArgumentsData structure
     * based on the provided methodOfRepresentation parameter.
     * @param data The ArgumentsData structure to set the representation scheme in.
     * @param methodOfRepresentation The character representing the method of representation.
     *     Possible values are 'v' (vectorLinear), 'b' (vectorBinary), 's' (set), 'u' (unorderedSet).
     */
    static void setRepresentationScheme(ArgumentsData &data, char methodOfRepresentation);
};


#endif //WORDLE_ARGUMENTSHANDLELOGIC_H

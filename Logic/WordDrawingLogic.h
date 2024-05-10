//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_WORDDRAWINGLOGIC_H
#define WORDLE_WORDDRAWINGLOGIC_H


#include <random>
#include <iostream>
/**
 * @file WordDrawingLogic.h
 * @brief Header file containing the WordDrawingLogic class.
 */

/**
 * @class WordDrawingLogic
 * @brief Responsible for logic related to drawing words for the game.
 */
class WordDrawingLogic {
public:
    /**
     * @brief Generates a random integer between a given range.
     * @param low The lower bound of the range.
     * @param high The upper bound of the range.
     * @return An integer representing the randomly generated number within the specified range.
     */
    static int rand_int(int low, int high);
};

#endif //WORDLE_WORDDRAWINGLOGIC_H

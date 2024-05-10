//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_LETTERSPOSITIONDATA_H
#define WORDLE_LETTERSPOSITIONDATA_H

#include <stdio.h>
/**
 * @file LettersPositionData.h
 * @brief Header file containing the LettersPositionData enum.
 */

/**
 * @enum LettersPositionData
 * @brief Represents the possible states of a letter in the guessed word.
 * @details enumeration is used to provide feedback on each letter that the user guesses in the game.
 * It indicates whether each letter is in the correct position, in the wrong position, or not existing
 * in the target word at all.
 */
enum LettersPositionData {
    inPlace, /**< Indicates that the letter is in the correct position. */
    wrongPlace, /**< Indicates that the letter is in the word but in the wrong position. */
    notExisting /**< Indicates that the letter does not exist in the word. */
};


#endif //WORDLE_LETTERSPOSITIONDATA_H

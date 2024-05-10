//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_ENDGAMEVIEW_H
#define WORDLE_ENDGAMEVIEW_H


#include "GameScreen.h"
using namespace ftxui;
/**
 * @file EndGameView.h
 * @brief Header file containing the EndGameView class.
 */

/**
 * @class EndGameView
 * @brief Responsible for displaying the final game state to the user.
 * @details class handles the presentation of the end screen of the game, showing the result (win/loss),
 * the word that was drawn, and the number of attempts the user made.
 */
class EndGameView {
public:
    /**
     * @brief Displays the end game view.
     *
     * @details static function is responsible for displaying the final state of the game. It shows
     * whether the user won or lost, the word that was drawn, and the number of attempts made.
     *
     * @param isGameWon Indicates whether the game was won or not.
     * @param drawedWord The word that was drawn for the game.
     * @param currentRow The number of attempts (rows) the user took to guess the word.
     */
    static void displayEndView(bool isGameWon, std::string drawedWord, int currentRow);
};


#endif //WORDLE_ENDGAMEVIEW_H

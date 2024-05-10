//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_GAMESCREEN_H
#define WORDLE_GAMESCREEN_H

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/mouse.hpp"
#include <ftxui/component/screen_interactive.hpp>
#include "../Data/LettersPositionData.h"
#include "ftxui/dom/elements.hpp"

using namespace ftxui;
/**
 * @file GameScreen.h
 * @brief Header file containing the GameScreen class.
 */

/**
 * @class GameScreen
 * @brief The GameScreen class represents the game screen where the user can input letters and view the game progress.
 */
class GameScreen {
private:
    std::vector<std::vector<std::pair<std::string, LettersPositionData>>> letters; /**< 2D vector holding pairs of letters and their position data. */
    int currentRow = 0; /**< Tracks the current row of the game, indicating the user's progress. */
    std::string firstLetter; /**< Temporary storage for the first letter input by the user. */
    std::string secondLetter; /**< Temporary storage for the second letter input by the user. */
    std::string thirdLetter; /**< Temporary storage for the third letter input by the user. */
    std::string fourthLetter; /**< Temporary storage for the fourth letter input by the user. */
    std::string fifthLetter; /**< Temporary storage for the fifth letter input by the user. */
    std::vector<std::string> userWord; /**< Stores the word input by the user. */
public:
    /**
     * @brief Constructor for the GameScreen class.
     * Initializes a new instance of the GameScreen class with default values.
     */
    GameScreen();
    /**
     * @brief The game function in the GameScreen class allows the user to input letters and view the game progress.
     * @param lettersPosition - The position data for the letters.
     */
    void game(std::vector<LettersPositionData> lettersPosition);
    /**
    * @brief Gets the current row.
    * @return The current row.
    */
    int getCurrentRow() const;

};
#endif //WORDLE_GAMESCREEN_H

//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_STARTSCREEN_H
#define WORDLE_STARTSCREEN_H


#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"

#include "ftxui/component/event.hpp"
#include "ftxui/component/mouse.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

using namespace ftxui;

/**
 * @file StartScreen.h
 * @brief Header file containing the StartScreen class.
 */

/**
 * @class StartScreen
 * @brief The StartScreen class represents the screen displayed at the beginning of the game.
 * @details provides a displayHowToPlay() function which displays information on how to play the game.
 * The function returns a bool indicating whether the game should be started or not.
 */
class StartScreen {
private:
    bool startGame; /**< Flag to indicate whether the game should be started or not. */
public:
    /**
     * @brief Displays the instructions on how to play the game.
     * @return true if the game should be started, false otherwise.
     */
    bool displayHowToPlay();
};

#endif //WORDLE_STARTSCREEN_H

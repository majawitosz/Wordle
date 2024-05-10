//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_CONTROLLER_H
#define WORDLE_CONTROLLER_H

#include <vector>
#include <fstream>
#include "Logic/RepresentationScheme.h"
#include "Logic/ArgumentsHandleLogic.h"
#include "View/ArgumentsHandleView.h"
#include "Data/ArgumentsDataMessage.h"
#include "View/StartScreen.h"
#include "View/GameScreen.h"
#include "Data/LettersPositionData.h"
#include "View/EndGameView.h"

/**
 * @file Controller.hpp
 * @brief Plik nagłówkowy zawierający deklarację klasy Controller.
 */

/**
 * @class Controller
 * @brief Class responsible for controlling the entire game.
 * @details The Controller class regulates the interaction between the Data and View, and serves
 * as the main driving force, dictating the overall flow of the application.
 */
class Controller {
private:
    std::string word; /**< The drawed word that is being processed in the game. */
    ArgumentsHandleLogic newArgumentsHandleLogic; /**< Logic handler for processing command-line arguments. */
    ArgumentsData aData; /**< Data structure to hold the processed arguments and results of argument handling. */
    StartScreen startScreen; /**< The initial screen displayed at the beginning of the game, providing game instructions. */
    GameScreen gameScreen; /**< The main game screen responsible for displaying the game state and handling user interactions. */
    std::shared_ptr<RepresentationScheme> representation; /**< Pointer to the representation scheme used for processing the dictionary. */
    bool gameInProgress = false; /**< Flag to indicate whether the game is currently in progress. */
    bool isGameWon = false; /**< Flag to indicate whether the game has been won by the player. */

public:
    /**
     * @brief Controls the arguments provided to the controller
     *
     * @details This function handles the logic for the provided arguments. It calls the handleArguments function of the ArgumentsHandleLogic class.
     * If an exception of type ArgumentsData is caught, it updates the aData member variable with the exception data and proceeds accordingly.
     * If the result value of aData is true, it chooses the appropriate representation scheme based on the methodOfRepresentation value and
     * assigns it to the word and representation member variables. It then calls the chosenRepresentation function of the chosen representation
     * scheme and assigns the returned word to the word member variable. It prints the word to the console and calls the measureTime function of
     * the chosen representation scheme. Finally, it calls the controlGame function.
     * If the result value of aData is false, it calls the displayHelp function of the ArgumentsHandleView class.
     *
     * @param arguments The vector of string arguments provided to the controller
     */
    void controlArguments(const std::vector<std::string> &arguments);
    /**
     * @brief Controls the game flow and handles user input.
     *
     * @details This function controls the game flow by displaying the view, handling user input,
     * and updating the game state based on the user's actions. It uses a while loop to
     * continuously execute the game logic until the game is no longer in progress or
     * the game screen has reached the maximum number of rows.
     */
    void controlGame();
};

#endif //WORDLE_CONTROLLER_H

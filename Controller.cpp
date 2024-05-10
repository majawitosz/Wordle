//
// Created by Maja on 5/9/2024.
//

#include "Controller.h"


void Controller::controlArguments(const std::vector<std::string> &arguments){
    try {
        newArgumentsHandleLogic.handleArguments(arguments);
    } catch (const ArgumentsData& data) {
        this->aData = data;
        if(aData.result){
            std::shared_ptr<RepresentationScheme> chosenRepresentationScheme;
            switch (aData.methodOfRepresentation) {
                case ArgumentsData::vectorLinear:
                    chosenRepresentationScheme = std::make_shared<VectorLinearSearch>();
                    break;
                case ArgumentsData::vectorBinary:
                    chosenRepresentationScheme = std::make_shared<VectorBinarySearch>();
                    break;
                case ArgumentsData::set:
                    chosenRepresentationScheme = std::make_shared<SetSearch>();
                    break;
                case ArgumentsData::unorderedSet:
                    chosenRepresentationScheme = std::make_shared<UnorderedSetSearch>();
                    break;
                default:
                    break;
            }
            this->word = chosenRepresentationScheme->chosenRepresentation(this->aData.filePath);
            std::cout<<this->word<<std::endl;
            this->representation = chosenRepresentationScheme;
            chosenRepresentationScheme->measureTime();
            controlGame();
        } else {
            ArgumentsHandleView::displayHelp(this->aData);
        }
    }
}


void Controller::controlGame(){

    ArgumentsHandleView::displayView(this->aData);

    gameInProgress = startScreen.displayHowToPlay();
    std::vector<LettersPositionData> data ={};

    while(gameInProgress && gameScreen.getCurrentRow() != 5){
        try {
            gameScreen.game(data);
        } catch(std::vector<std::string> letters){
            data = this->representation->checkingWord(letters);
            for (int i = 0; i < data.size(); i++) {
                if(data[i] != inPlace){
                    isGameWon = false;
                    break;
                }
                else if(i==data.size()-1 && data[i] == inPlace ){
                    isGameWon = true;
                    EndGameView::displayEndView(isGameWon, this->word, gameScreen.getCurrentRow());
                }
            }
        }
    }
    EndGameView::displayEndView(isGameWon, this->word, gameScreen.getCurrentRow());
}
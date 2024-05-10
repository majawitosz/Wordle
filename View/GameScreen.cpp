//
// Created by Maja on 5/9/2024.
//

#include "GameScreen.h"
GameScreen::GameScreen() {
    for (int i = 0; i < 6; i++) {
        this->letters.push_back({});
        for (int j = 0; j < 5; j++){
            LettersPositionData position;
            std::pair<std::string, LettersPositionData> pair;
            pair.first = " ";
            pair.second = position;


            letters[i].push_back(pair);
        }
    }
}


void GameScreen::game(std::vector<LettersPositionData> lettersPosition){
    auto screen = ScreenInteractive::TerminalOutput();
    // The data:
    if(!lettersPosition.empty()){
        this->currentRow += 1;
        for (int i = 0; i < 5; i++){
            letters[currentRow-1][i].first = this->userWord[i];
            letters[currentRow-1][i].second = lettersPosition[i];
        }
    }
    firstLetter = {};
    secondLetter = {};
    thirdLetter = {};
    fourthLetter = {};
    fifthLetter = {};



    Component input_first = Input(&firstLetter);

    input_first |= CatchEvent([&](Event event) {
        return event.is_character() && firstLetter.size() >0;
    });

    Component input_second = Input(&secondLetter);

    input_second |= CatchEvent([&](Event event) {
        return event.is_character() && secondLetter.size() >0;
    });

    Component input_third = Input(&thirdLetter);

    input_third |= CatchEvent([&](Event event) {
        return event.is_character() && thirdLetter.size() >0;
    });

    Component input_fourth = Input(&fourthLetter);

    input_fourth |= CatchEvent([&](Event event) {
        return event.is_character() && fourthLetter.size() >0;
    });

    Component input_fifth = Input(&fifthLetter);

    input_fifth |= CatchEvent([&](Event event) {
        return event.is_character() && fifthLetter.size() >0;
    });


    auto exit_button = Button("enter", [&screen, this]() {

        screen.ExitLoopClosure()();
        this->userWord = {firstLetter,secondLetter,thirdLetter,fourthLetter,fifthLetter};
        throw userWord;

    }, ButtonOption::Border());

    // The component tree:
    auto component = Container::Horizontal({
                                                   input_first,
                                                   input_second,
                                                   input_third,
                                                   input_fourth,
                                                   input_fifth,
                                                   exit_button
                                           });

    std::vector<std::shared_ptr<Node>> hboxContainers;

    for (int i = 0; i < 6; i++){
        std::vector<std::shared_ptr<Node>> textVector = {};
        for (int j = 0; j < 5; j++) {
            if(this->letters[i][0].first != " "){
                if(this->letters[i][j].second == inPlace){
                    textVector.push_back(text(this->letters[i][j].first) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green));
                }
                else if(this->letters[i][j].second == wrongPlace){
                    textVector.push_back(text(this->letters[i][j].first) | color(Color::Yellow1) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Yellow1));
                }
                else{
                    textVector.push_back(text(this->letters[i][j].first) | color(Color::Grey46) | hcenter | size(WIDTH, EQUAL, 3)| borderStyled(Color::Grey46));
                }
            }
            else {
                textVector.push_back(text(" ") | border | size(WIDTH, EQUAL, 5));
            }
        }
        std::shared_ptr<Node> row = hbox({
                                                 textVector[0],
                                                 textVector[1],
                                                 textVector[2],
                                                 textVector[3],
                                                 textVector[4],

                                         });
        hboxContainers.push_back(row);
    }


    // Tweak how the component tree is rendered:
    auto renderer = Renderer(component, [&] {
        return vbox({
                            hbox({
                                         input_first->Render()| size(WIDTH, EQUAL, 3) | border | hcenter ,
                                         input_second->Render() | size(WIDTH, EQUAL, 3) | border | hcenter,
                                         input_third->Render() | size(WIDTH, EQUAL, 3) | border | hcenter,
                                         input_fourth->Render() | size(WIDTH, EQUAL, 3) | border  | hcenter,
                                         input_fifth->Render() | size(WIDTH, EQUAL, 3) | border | hcenter,
                                         text(" "),
                                         exit_button->Render() ,
                                 }),
                            separatorEmpty(),
                            hboxContainers[0],
                            hboxContainers[1],
                            hboxContainers[2],
                            hboxContainers[3],
                            hboxContainers[4],
                            hboxContainers[5],
                            separatorEmpty() |size(HEIGHT, EQUAL, 5),

                    }) | hcenter ;
    });


    screen.Loop(renderer);
}

int GameScreen::getCurrentRow() const {
    return this->currentRow;
}

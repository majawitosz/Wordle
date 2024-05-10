//
// Created by Maja on 5/9/2024.
//

#include "EndGameView.h"
void EndGameView::displayEndView(bool isGameWon, std::string drawedWord, int currentRow) {

    auto screen = ScreenInteractive::TerminalOutput();

    auto style = ButtonOption::Animated(Color::Default, Color::White,
                                        Color::Default, Color::White);



    auto stop_button = Button("EXIT", [&screen]() {
        screen.ExitLoopClosure()();
    }, ButtonOption::Border());


    auto component = stop_button;

    std::shared_ptr<Node> information;

    if(isGameWon){
        information = hbox({
                                   text(" You guessed the word in ") | bold,
                                   text(std::to_string(currentRow+1))| bold,
                                   text(" tries") | bold
                           });
    } else {
        information = vbox({
                                   text(" You didn't guess the word, you lose :(") | bold,
                                   text(" "),
                                   text(" The answer was: ") | bold | center
                           });
    }

    std::string firstLetter = " ";
    firstLetter.push_back(drawedWord[0]);
    std::string secondLetter = " ";
    secondLetter.push_back(drawedWord[1]);
    std::string thirdLetter = " ";
    thirdLetter.push_back(drawedWord[2]);
    std::string fourthLetter = " ";
    fourthLetter.push_back(drawedWord[3]);
    std::string fifthLetter = " ";
    fifthLetter.push_back(drawedWord[4]);

    auto renderer = Renderer(component, [&] {
        return window(text(" STATISTICS "),
                      vbox({

                                   text(" "),
                                   information,
                                   separatorEmpty() |size(HEIGHT, EQUAL, 2),
                                   hbox({
                                                text(firstLetter) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green),
                                                text(secondLetter) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green),
                                                text(thirdLetter) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green),
                                                text(fourthLetter) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green),
                                                text(fifthLetter) | color(Color::Green) | hcenter | size(WIDTH, EQUAL, 3) | borderStyled(Color::Green),
                                        }) |center,
                                   separatorEmpty() |size(HEIGHT, EQUAL, 2),
                                   stop_button->Render()|center


                           })| hcenter);
    });

    screen.Loop(renderer);

}
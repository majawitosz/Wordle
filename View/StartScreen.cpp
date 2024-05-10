//
// Created by Maja on 5/9/2024.
//

#include "StartScreen.h"
bool StartScreen::displayHowToPlay(){

    auto screen = ScreenInteractive::TerminalOutput();
    auto start_button = Button("START", [&screen, this]() {
        screen.ExitLoopClosure()();
        this->startGame = true;
    }, ButtonOption::Border());

    auto component = start_button;

    auto renderer = Renderer(component, [&] {
        return window(text(" HOW TO PLAY "),
                      vbox({
                                   text(" "),
                                   text(" You have to guess the word in 6 tries") | bold,
                                   text(" "),
                                   text("• Each guess must be a valid 5-letter word"),
                                   paragraph(
                                           "• The color of the tiles will change to show how close your guess was to the word"),
                                   text(" "),
                                   text("EXAMPLES") | bold,
                                   hbox({
                                                text(" W ") | color(Color::Green) | borderStyled(ROUNDED, Color::Green),
                                                text(" O ") | border,
                                                text(" R ") | border,
                                                text(" D ") | border,
                                                text(" S ") | border,
                                        }),
                                   text(" 𝗪 is in the word and in the correct spot") | bold,
                                   text(" "),
                                   hbox({
                                                text(" S ") | border,
                                                text(" P ") | border,
                                                text(" O ") | color(Color::Yellow1) |
                                                borderStyled(ROUNDED, Color::Yellow1),
                                                text(" O ") | border,
                                                text(" N ") | border,
                                        }),
                                   text(" 𝗢 is in the word but in the wrong spot") | bold,
                                   text(" "),
                                   hbox({
                                                text(" S ") | border,
                                                text(" O ") | border,
                                                text(" U ") | border,
                                                text(" N ") | border,
                                                text(" D ") | color(Color::Grey46) |
                                                borderStyled(ROUNDED, Color::Grey46),
                                        }),
                                   text(" 𝗗 is in the word but in the wrong spot") | bold,
                                   text(" "),
                                   start_button->Render() |size(WIDTH, EQUAL, 10) |hcenter
                           }));
    });

    screen.Loop(renderer);

    if (!this->startGame)
        return false;
    else
        return true;

}
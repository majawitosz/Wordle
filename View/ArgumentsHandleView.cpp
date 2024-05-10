//
// Created by Maja on 5/9/2024.
//

#include "ArgumentsHandleView.h"
void ArgumentsHandleView::displayHelp(ArgumentsData &newArgumentsData){

    Element document =

            vbox({
                         text("HELP") | bold | color(Color::Blue) | hcenter,
                         separatorLight(),
                         text(newArgumentsData.message)| bold | color(Color::Red)| hcenter,
                         text(" "),
                         paragraph("To run game you need to provide parameter with the name of the file:"),
                         text("• -d <dictionary path name> ") |bold,
                         text(" "),
                         paragraph("Additionally you can choose the way data is going to be represented from the following options:"),
                         text("• \"v\" vector with linear search"),
                         text("• \"b\" vector with binary search"),
                         text("• \"s\" set"),
                         text("• \"u\" unordered set"),
                         text(" "),
                         paragraph("To run game with chosen option, provide one additional parameter like following:"),
                         text("• -p <chosen data representation> ") |bold,
                         paragraph("If the parameter -p won't be provided, the application will run with default settings"),

                 });
    document = border(document);

    auto screen = Screen::Create(
            Dimension::Full(),       // Width
            Dimension::Fit(document) // Height
    );

    Render(screen, document);
    screen.Print();
    std::cout<<std::endl;

}


void ArgumentsHandleView::displayView(ArgumentsData &newArgumentsData){

    std::string reset_position;
    for (float percentage = 0.0f; percentage <= 1.0f; percentage += 0.01f) {
        std::string data_downloaded =
                std::to_string(int(percentage * 100 +1)) + "%";
        auto document = vbox({
                                     text(newArgumentsData.message)| bold | color(Color::Blue)| hcenter,
                                     text(""),
                                     text("Game will start in a few seconds")| hcenter,

                                     border(gauge(percentage)),
                                     text(" " + data_downloaded)
                             });
        document = border(document);
        auto screen = Screen::Create(
                Dimension::Full(),
                Dimension::Fit(document)
        );
        Render(screen, document);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << std::endl;

}
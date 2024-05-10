cmake_minimum_required(VERSION 3.28)
# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
#set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
        GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)
# ------------------------------------------------------------------------------
project(Wordle LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wordle main.cpp
        Controller.cpp
        Controller.h
        Data/ArgumentsDataMessage.cpp
        Data/ArgumentsDataMessage.h
        Data/LettersPositionData.cpp
        Data/LettersPositionData.h
        Logic/ArgumentsHandleLogic.cpp
        Logic/ArgumentsHandleLogic.h
        Logic/RepresentationScheme.cpp
        Logic/RepresentationScheme.h
        Logic/WordDrawingLogic.cpp
        Logic/WordDrawingLogic.h
        View/ArgumentsHandleView.cpp
        View/ArgumentsHandleView.h
        View/EndGameView.cpp
        View/EndGameView.h
        View/GameScreen.cpp
        View/GameScreen.h
        View/StartScreen.cpp
        View/StartScreen.h
)

target_link_libraries(Wordle
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
)
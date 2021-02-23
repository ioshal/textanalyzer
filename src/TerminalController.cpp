//
// Created by Igor on 21.02.2021.
//

#include <iostream>
#include <mutex>
#include <utility>

#include "../include/TerminalController.h"
#include "../include/TerminalView.h"
#include "../include/TextModel.h"

void TerminalController::acceptCommandFromStdout() {
    isRunning = true;

    std::thread th1([&]() {
        int input;

        while (isRunning) {
            std::cin >> input;

            auto command = static_cast<Config::Commands>(input);

            std::thread th2([&]() {
                handleCommand(command);
            });

            th2.join();
        }
    });

    th1.detach();
}

void TerminalController::handleCommand(const Config::Commands command) {
    std::unique_lock<std::mutex> lock(_commandMutex);

    _commandCv.wait(lock);

    switch (command) {
        case Config::Commands::MOST_COMMON_LETTERS: {

            const std::vector<Config::LETTER_PAIR> &frequency = _textModel.constructLettersFrequency(Config::LettersFrequencyType::MOST_COMMON);

            TerminalView::displayCharsFrequency(frequency);
            break;
        }
        case Config::Commands::OCCURRENCE_PROBABILITY: {
            TerminalView::promptCharacter();

            char c;

            std::cin >> c;

            const auto&[character, probability] = _textModel.constructOccurrenceProbability(c);

            TerminalView::displayOccurrenceProbability(character, probability);
            break;
        }
        case Config::Commands::RAREST_LETTERS: {
            const std::vector<Config::LETTER_PAIR> &frequency = _textModel.constructLettersFrequency(Config::LettersFrequencyType::RAREST);

            break;
        }
        default: {
            std::cout << "Invalid command";
        }
    }

}

void TerminalController::appendTextData(const std::string &text) {
    _textData += text;
}

TerminalController::TerminalController(const TextModel &model, const TerminalView &view) : _textModel(model),
                                                                                           _terminalView(view) {
}

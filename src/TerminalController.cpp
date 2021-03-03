//
// Created by Igor on 21.02.2021.
//

#include <iostream>
#include <mutex>

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

    th1.join();
}

void TerminalController::handleCommand(const Config::Commands command) {
    std::unique_lock<std::mutex> lock(_commandMutex);

    _commandCv.wait(lock);

    switch (command) {
        case Config::Commands::MOST_COMMON_LETTERS: {

            const std::vector<Config::LETTER_PAIR> &frequency = _textModel.constructLettersFrequency(Config::LettersFrequencyType::MOST_COMMON);

            _terminalView.displayCharsFrequency(frequency);
            break;
        }
        case Config::Commands::OCCURRENCE_PROBABILITY: {
            const char c = _terminalView.getCharacter();

            const auto&[character, probability] = _textModel.constructCharOccurrenceProbability(c);

            _terminalView.displayOccurrenceProbability(character, probability);
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

TerminalController::TerminalController(const TextModel &model, const TerminalView &view) : _textModel(model),
                                                                                           _terminalView(view) {
}

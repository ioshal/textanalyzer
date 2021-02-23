
#include "../include/TerminalView.h"

void TerminalView::printUsage() {
    int commandNumber = 1;

    for (const auto&[key, val] : Config::availableCommands) {
        std::cout << commandNumber++ << ". " << val.name << " (" << val.description << ")" << std::endl;
    }
}

void TerminalView::displayCharsFrequency(const std::vector<Config::LETTER_PAIR> &frequencies) {
    for (const auto&[letter, frequency] : frequencies) {
        std::cout << "[letter: " << letter << ", frequency: " << frequency << "]" << std::endl;
    }
}

void TerminalView::promptCharacter() {
    std::cout << "Input a character: " << std::endl;
}

void TerminalView::displayOccurrenceProbability(const char c, const int &probability) {
    std::cout << "[letter: " << c << ", occurrence_probability: " << probability << std::endl;
}
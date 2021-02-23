
#include <iomanip>

#include "../include/TerminalView.h"

void TerminalView::printUsage() const {
    int commandNumber = 1;

    for (const auto&[key, val] : Config::availableCommands) {
        std::cout << commandNumber++ << ". " << val.name << " (" << val.description << ")" << std::endl;
    }
}

void TerminalView::displayCharsFrequency(const std::vector<Config::LETTER_PAIR> &frequencies) const {
    for (const auto&[letter, frequency] : frequencies) {
        std::cout << "[letter: " << letter << ", frequency: " << frequency << "]" << std::endl;
    }
}

char TerminalView::getCharacter() const {
    std::cout << "Input a character to find it's occurrence probability: " << std::endl;

    char c;

    std::cin >> c;

    return c;
}

void TerminalView::displayOccurrenceProbability(const char c, const float &probability) const {
    const int PRECISION = 10;

    std::cout << "[letter: " << c << ", occurrence_probability: " << probability << "] " << std::setprecision(PRECISION) << std::endl;
}
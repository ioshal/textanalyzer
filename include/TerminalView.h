//
// Created by Igor on 21.02.2021.
//

#ifndef THREADEDFILES_TERMINALVIEW_H
#define THREADEDFILES_TERMINALVIEW_H

#include <iostream>
#include <vector>
#include <utility>
#include <map>

#include "Config.h"

class TerminalView {
public:
    void printUsage() const;

    void displayCharsFrequency(const std::vector<Config::LETTER_PAIR> &) const;

    char getCharacter() const;

    void displayOccurrenceProbability(const char, const float &) const;
};

#endif //THREADEDFILES_TERMINALVIEW_H

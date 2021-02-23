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
    TerminalView() = default;

    static void printUsage();

    static void displayCharsFrequency(const std::vector<Config::LETTER_PAIR> &);

    static void promptCharacter();

    static void displayOccurrenceProbability(const char, const int &);
};

#endif //THREADEDFILES_TERMINALVIEW_H

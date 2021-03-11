
#ifndef THREADEDFILES_CONFIG_H
#define THREADEDFILES_CONFIG_H

#include <iostream>
#include <map>
#include <utility>
#include <vector>

namespace Config {
    enum class Commands {
        MOST_COMMON_LETTERS = 1,
        RAREST_LETTERS,
        OCCURRENCE_PROBABILITY,
        HELP
    };

    struct Command {
        std::string name;
        std::string description;
    };

    static std::map<Commands, Command> availableCommands = {
            {Commands::MOST_COMMON_LETTERS,    {"5 most common letters",  "Prints 5 most common letters from the provided text"}},
            {Commands::OCCURRENCE_PROBABILITY, {"probability occurrence", "Probability of a letter occurring in a text"}},
            {Commands::RAREST_LETTERS,         {"3 rarest letters",       "Prints 3 rarest letters from the provided text"}},
            {Commands::HELP,         {"help",       "помагите"}}
    };

    using LETTER_PAIR = std::pair<char, int>;

    using LettersFrequency = std::vector<LETTER_PAIR>;

    enum class LettersFrequencyType {
        MOST_COMMON = 1,
        RAREST
    };
}

#endif //THREADEDFILES_CONFIG_H

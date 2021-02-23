//
// Created by Igor on 22.02.2021.
//

#ifndef THREADEDFILES_TEXTMODEL_H
#define THREADEDFILES_TEXTMODEL_H

#include <string>
#include <map>
#include <vector>
#include <queue>
#include <utility>

#include "Config.h"

namespace {
    struct CmpHighest {
        constexpr bool operator()(const Config::LETTER_PAIR &a, const Config::LETTER_PAIR &b) {
            return a.second < b.second;
        }
    };
    constexpr auto cmpHighest = [](const Config::LETTER_PAIR &a, const Config::LETTER_PAIR &b) {
        return a.second < b.second;
    };

    constexpr auto cmpLowest = [](const Config::LETTER_PAIR &a, const Config::LETTER_PAIR &b) {
        return a.second > b.second;
    };

    struct CmpLowest {
        constexpr bool operator()(const Config::LETTER_PAIR &a, const Config::LETTER_PAIR &b) {
            return a.second > b.second;
        }
    };

    const int NUMBER_OF_MOST_COMMON_LETTERS = 5;
}

class TextModel {
public:
    void appendText(const std::string& text);
    [[nodiscard]] std::string getCurrentTextData() const;

    [[nodiscard]] Config::LettersFrequency constructLettersFrequency(const Config::LettersFrequencyType) const;

    [[nodiscard]] Config::LETTER_PAIR constructOccurrenceProbability(const char i) const;

private:
    std::string _text;

    std::map<char, int> _lettersMap;
};

#endif //THREADEDFILES_TEXTMODEL_H

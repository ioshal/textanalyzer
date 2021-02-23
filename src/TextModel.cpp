//
// Created by Igor on 23.02.2021.
//

#include <utility>

#include "../include/TextModel.h"

void TextModel::appendText(const std::string& text) {
    int entry;

    for (const char &c : text) {
        entry = _lettersMap[c];

        _lettersMap[c] = entry ? entry + 1 : 1;
    }

    _text += text;
}

std::string TextModel::getCurrentTextData() const {
    return _text;
}

Config::LettersFrequency TextModel::constructLettersFrequency(Config::LettersFrequencyType type) const {
    auto comparator = type == Config::LettersFrequencyType::MOST_COMMON ? cmpHighest : cmpLowest;

    std::priority_queue<Config::LETTER_PAIR, Config::LettersFrequency, decltype(comparator)> lettersFrequency;

    for (const auto&[letter, frequency] : _lettersMap) {
        lettersFrequency.push(std::make_pair(letter, frequency));
    }

    Config::LettersFrequency vec;
    vec.reserve(NUMBER_OF_MOST_COMMON_LETTERS);

    for (int i = 0; i < NUMBER_OF_MOST_COMMON_LETTERS; ++i) {
        const Config::LETTER_PAIR &entry = lettersFrequency.top();
        lettersFrequency.pop();

        vec.push_back(entry);
    }

    return vec;
}

Config::LETTER_PAIR TextModel::constructOccurrenceProbability(const char c) const {
    auto mapEntry = _lettersMap.find(c);

    if (mapEntry == _lettersMap.end()) {
        return std::make_pair(c, 0);
    }

    auto probability = mapEntry->second / _text.length();

    return std::make_pair(c, probability);
}

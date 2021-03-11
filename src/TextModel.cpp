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

    _textData += text;
}

std::string TextModel::getCurrentTextData() const {
    return _textData;
}

Config::LettersFrequency TextModel::constructLettersFrequency(Config::LettersFrequencyType type, const int& numberOfLettersForCalculation) const {
    auto comparator = type == Config::LettersFrequencyType::MOST_COMMON ? cmpHighest : cmpLowest;

    std::priority_queue<Config::LETTER_PAIR, Config::LettersFrequency, decltype(comparator)> lettersFrequency(comparator);

    for (const auto&[letter, frequency] : _lettersMap) {
        lettersFrequency.push(std::make_pair(letter, frequency));
    }

    const int MAX_NUMBER_OF_LETTERS = numberOfLettersForCalculation > _lettersMap.size() ? _lettersMap.size() : numberOfLettersForCalculation;

    Config::LettersFrequency vec;
    vec.reserve(MAX_NUMBER_OF_LETTERS);

    for (int i = 0; i < MAX_NUMBER_OF_LETTERS; ++i) {
        const Config::LETTER_PAIR &entry = lettersFrequency.top();
        lettersFrequency.pop();

        vec.push_back(entry);
    }

    return vec;
}

std::pair<char, float> TextModel::constructCharOccurrenceProbability(const char c) const {
    auto mapEntry = _lettersMap.find(c);

    if (mapEntry == _lettersMap.end()) {
        return std::make_pair(c, 0);
    }

    float probability  = static_cast<float>(mapEntry->second) / static_cast<float>(_textData.length());

    return std::make_pair(c, probability);
}

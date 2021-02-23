//
// Created by Igor on 21.02.2021.
//

#include <fstream>
#include <utility>

#include "../include/FileReader.h"
#include "../include/TextModel.h"

FileReader::FileReader(std::string filename, TextModel& m, const int &numOfWorkers) :
                                                                        _filename(std::move(filename)),
                                                                        _textModel(m),
                                                                        _numOfWorkers(numOfWorkers) {
}

void FileReader::read() {
    if (isReading) {
        return;
    }

    isReading = true;

    for (int i = 0; i < _numOfWorkers; ++i) {
        _workers.push_back(std::thread([&]() {
            std::fstream file(_filename);

            std::string input;

            while (!file.eof()) {
                file >> input;

                std::cout << input;
                _textModel.appendText(input);
            }
        }));
    }

    for (std::thread& worker : _workers) {
        worker.detach();
    }
}

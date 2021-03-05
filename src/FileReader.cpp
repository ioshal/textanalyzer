//
// Created by Igor on 21.02.2021.
//

#include <fstream>
#include <utility>
#include <filesystem>
#include <vector>

#include "../include/FileReader.h"
#include "../include/TextModel.h"

FileReader::FileReader(std::string dataPath, TextModel& m) :
                                                                        _dataPath(std::move(dataPath)),
                                                                        _textModel(m)
                                                                        {
}

void FileReader::read() {
    if (isReading) {
        return;
    }

    isReading = true;

    std::vector<std::string> filenames;

    for (const auto& file : std::filesystem::directory_iterator(_dataPath)) {
        _workers.push_back(std::thread([&]() {
            auto& path = file.path();

            std::fstream f(path);

            std::string input;
            std::string result = "";

            while (!f.eof()) {
                f >> input;

                result += input;
            }

            std::scoped_lock<std::mutex> lock(_mutex);

            _textModel.appendText(result);
        }));
    }

    for (std::thread& worker : _workers) {
        worker.detach();
    }
}

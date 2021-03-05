//
// Created by Igor on 21.02.2021.
//

#ifndef THREADEDFILES_FILEREADER_H
#define THREADEDFILES_FILEREADER_H

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>

#include "Reader.h"

class TextModel;

class FileReader: public Reader {
public:
    FileReader(std::string, TextModel&);

    ~FileReader() = default;

    virtual void read() override;
private:
    bool isReading = false;
    std::string _dataPath;
    TextModel& _textModel;

    std::vector<std::thread> _workers;
    std::mutex _mutex;
};


#endif //THREADEDFILES_FILEREADER_H

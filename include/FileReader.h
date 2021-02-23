//
// Created by Igor on 21.02.2021.
//

#ifndef THREADEDFILES_FILEREADER_H
#define THREADEDFILES_FILEREADER_H

#include <iostream>
#include <thread>
#include <vector>

#include "Reader.h"

class FileReader: public Reader {
public:
    explicit FileReader() = default;
    FileReader(std::string filename, const int& numOfWorkers = 2);

    ~FileReader() = default;

    virtual void read() override;

private:
    std::string _filename;
    int _numOfWorkers;
    bool isReading = false;

    std::vector<std::thread> _workers;
};


#endif //THREADEDFILES_FILEREADER_H

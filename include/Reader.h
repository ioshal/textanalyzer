//
// Created by Igor on 21.02.2021.
//

#ifndef THREADEDFILES_READER_H
#define THREADEDFILES_READER_H

#include <iostream>
#include <functional>
#include <list>

class Reader {
public:
    virtual void read() = 0;

    virtual ~Reader() = default;
protected:
    std::string buffer;
};


#endif //THREADEDFILES_READER_H

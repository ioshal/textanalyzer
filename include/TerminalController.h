//
// Created by Igor on 21.02.2021.
//

#ifndef THREADEDFILES_TERMINALCONTROLLER_H
#define THREADEDFILES_TERMINALCONTROLLER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Config.h"

class TextModel;
class TerminalView;

class TerminalController {
public:
    TerminalController(const TextModel&, const TerminalView&);

    void acceptCommandFromStdout();

    void appendTextData(const std::string&);

private:
    std::mutex _commandMutex;
    std::condition_variable _commandCv;

    std::string _textData;

    void handleCommand(const Config::Commands command);

    bool isRunning = false;

    const TextModel& _textModel;
    const TerminalView& _terminalView;
};


#endif //THREADEDFILES_TERMINALCONTROLLER_H
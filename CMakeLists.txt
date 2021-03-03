cmake_minimum_required(VERSION 3.17)
project(threadedfiles)

set(CMAKE_CXX_STANDARD 20)

add_executable(threadedfiles src/main.cpp include/Reader.h src/FileReader.cpp include/FileReader.h include/TerminalView.h include/Config.h src/TerminalController.cpp include/TerminalController.h include/TextModel.h src/TextModel.cpp src/TerminalView.cpp)
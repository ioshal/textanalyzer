#include <iostream>
#include <string>

#include "../include/TerminalView.h"
#include "../include/TerminalController.h"
#include "../include/TextModel.h"
#include "../include/FileReader.h"

using namespace std;

int main() {
    TextModel model;
    TerminalView view;
    TerminalController controller(model, view);

    string filename;

    cout << "Enter a filename: ";

    cin >> filename;

    FileReader reader(filename, model);

    reader.read();

    view.printUsage();

    controller.acceptCommandFromStdout();

    return 0;
}

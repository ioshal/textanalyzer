#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/TerminalView.h"
#include "../include/TerminalController.h"
#include "../include/TextModel.h"
#include "../include/FileReader.h"

using namespace std;

void handler(int s){
    printf("Caught signal %d\n",s);
    exit(1);
}

int main() {
    signal (SIGINT, handler);

    TextModel model;
    TerminalView view;
    TerminalController controller(model, view);

    FileReader reader("../data", model);

    reader.read();

    view.printUsage();

    controller.acceptCommandFromStdout();

    return 0;
}

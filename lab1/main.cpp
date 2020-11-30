
#include "init.h"
//#include "draw.h"

void startLab1();

void startLab1() {
    Init initLab1;
    //Draw triangle;

    initLab1.initOpenGL();
    initLab1.initWindow(1080, 720, "lab1");

    initLab1.rendering();

    initLab1.deleteInitOpenGL();
}

int main() {

    startLab1();
    return 0;
}
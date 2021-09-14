#include <iostream>
#include "factory.h"
int main() {

    Shape* shape;
    Tetris tetris;

    shape = tetris.createShape(1);
    shape->printShape();
    shape->getName();

    shape = tetris.createShape(3);
    shape->printShape();
    shape->getName();


    shape = tetris.createShape(2);
    shape->printShape();
    shape->getName();
    return 0;
}

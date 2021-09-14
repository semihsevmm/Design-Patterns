#include <iostream>
#include "decorator.h"
int main() {
    Drone *myQuadcopter = new Quadcopter();
    myQuadcopter->fly();

    Drone *myOctacopter = new Octocopter();
    myOctacopter->fly();

    CameraDecorator *cameraDec = new CameraDecorator(myQuadcopter);
    NavigationDecorator *navigateDec = new NavigationDecorator(myOctacopter);

    cameraDec->operation();
    cameraDec->fly();
    navigateDec->operation();
}

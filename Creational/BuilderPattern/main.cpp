#include <iostream>
#include "builder.h"
int main() {
    LevelDesign *kolay = new KolaySeviye();
    Designer *designer1 = new Designer(kolay);

    designer1->levelOlustur();
    GameLevel *level = designer1->getOyunLevel();

    level->getoyunLevelInfo();
}

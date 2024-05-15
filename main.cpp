#include <iostream>
#include "Siren.h"
#include "SmokeDetector.h"
#include <ctime>
#include "Exceptions.h"
#include "InfraredSensor.h"
#include "Building.h"


int main() {

    std::srand(std::time(nullptr));

    Building building(3);


    building.addSensor(1, new SmokeDetector());

    building.addSensor(1, new InfraredSensor());


    building.checkSensors();


    return 0;
}

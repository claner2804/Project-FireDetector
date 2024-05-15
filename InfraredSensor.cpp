//
// Created by Claudia Steiner on 14.05.24.
//

#include "InfraredSensor.h"

bool InfraredSensor::isFire() {
    //Entdeckt mit einer Wahrscheinlichkeit von 5% Feuer
    if (rand() % 100 < 5) {
        return true;
    } else {
        return false;
    }
}

bool InfraredSensor::isDefect() {
    //Mit einer Wahrscheinlichkeit von 4% kann ein Fehler auftreten.
    if (rand() % 100 < 4) {
        return true;
    } else {
        return false;
    }
}

int InfraredSensor::getType() {
    return 2;
}

void InfraredSensor::checkSensor() {
    if (isFire()) {
        throw FireDetectedException("InfraredSensor::checkSensor - FEUUUERRRRR!!!!");
    }
    if (isDefect()) {
        throw ErrorDetectedException("InfraredSensor::checkSensor - Fehler - Hausmeister wird benachrichtigt");
    }
    else {
        std::cout << "InfraredSensor::checkSensor - alles ok" << std::endl;
    }
}

InfraredSensor::InfraredSensor() {
    std::cout << "InfraredSensor montiert" << std::endl;

}

InfraredSensor::~InfraredSensor() {
    std::cout << "InfraredSensor wird abmontiert!" << std::endl;

}

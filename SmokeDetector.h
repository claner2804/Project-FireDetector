//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_SMOKEDETECTOR_H
#define BRANDMELDER_SMOKEDETECTOR_H

#include "Siren.h"
#include "Sensor.h"
#include  <iostream>

/*
 * • SmokeDetector:
▪ Entdeckt mit einer Wahrscheinlichkeit von 3% Feuer
▪ Mit einer Wahrscheinlichkeit von 2% kann ein Fehler auftreten.
▪ getType() gibt 1 zurück.
 */
class SmokeDetector : public Sensor {

public:

    SmokeDetector();
    ~SmokeDetector();

    int getType() override;

    bool isFire() override;

    bool isDefect() override;

    void checkSensor() override;


    //std::string getName() override;


};


#endif //BRANDMELDER_SMOKEDETECTOR_H

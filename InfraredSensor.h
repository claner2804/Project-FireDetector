//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_INFRAREDSENSOR_H
#define BRANDMELDER_INFRAREDSENSOR_H

#include <iostream>
#include <string>
#include "Sensor.h"


/*
 * • InfraredSensor:
▪ Entdeckt mit einer Wahrscheinlichkeit von 5% Feuer
▪ Mit einer Wahrscheinlichkeit von 4% kann ein Fehler auftreten.
▪ getType() gibt 2 zurück.
 */
class InfraredSensor : public Sensor{

public:

    InfraredSensor();
    ~InfraredSensor();

    int getType() override;

    bool isFire() override;

    bool isDefect() override;

    //std::string getName() override;


};


#endif //BRANDMELDER_INFRAREDSENSOR_H

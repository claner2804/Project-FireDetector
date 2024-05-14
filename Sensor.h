//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_SENSOR_H
#define BRANDMELDER_SENSOR_H

#include <stdexcept>
#include <string>
#include <iostream>
#include "Exceptions.h"
#include "Sensor.h"

/*
 *
Die Klasse Sensor ist die Basisklasse für alle Sensoren und definiert deren öffentliches Interface. Konkrete
Sensoren werden von Subklassen dieser Klasse repräsentiert.
Wenn ein Feuer oder ein Fehler entdeckt wurde, dann soll die Funktion checkSensor() eine entsprechende
Exception werfen.
 */

class Sensor {


public:

    virtual ~Sensor() = default;

    //Überprüft den Sensoren. Wenn ein Brand entdeckt wurde,
    //dann soll dies mittels einer geeigneten Exception mitgeteilt werden.
    virtual void checkSensor() = 0;

    //Gibt den Typ des Sensors zurück.
    virtual int getType() = 0;

    //Gibt zurück, ob ein Feuer entdeckt wurde.
    virtual bool isFire() = 0;

    //Gibt zurück, ob ein Fehler aufgetreten ist.
    virtual bool isDefect() = 0;

};


#endif //BRANDMELDER_SENSOR_H

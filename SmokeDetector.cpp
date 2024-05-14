//
// Created by Claudia Steiner on 14.05.24.
//

#include "SmokeDetector.h"

int SmokeDetector::getType() {
    return 1;
}

bool SmokeDetector::isFire() {
    //Entdeckt mit einer Wahrscheinlichkeit von 3% Feuer
    if (rand() % 100 < 3) {
        throw FireDetectedException();
    } else {
        return false;
    }
}

bool SmokeDetector::isDefect() {
    //Mit einer Wahrscheinlichkeit von 2% kann ein Fehler auftreten.
    if (rand() % 100 < 2) {
        return true;
    } else {
        return false;
    }
}

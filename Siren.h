//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_SIREN_H
#define BRANDMELDER_SIREN_H

/*
 * Die Klasse Siren repräsentiert eine Sirene.
• Objektfunktionen:
▪ virtual void switchOn(): Schaltet die Sirene ein (in unserem Fall Ausgabe auf der
Konsole).
▪ virtual void switchOff(): Schaltet die Sirene.
 */

class Siren {

public:
    virtual void switchOn();

    virtual void switchOff();

};


#endif //BRANDMELDER_SIREN_H

//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_BUILDING_H
#define BRANDMELDER_BUILDING_H

#include <map>
#include "Siren.h"
#include "Sensor.h"


/*
 * Die Klasse Building repräsentiert das Geäude selber und implementiert die zentrale Steuerung der
Brandmeldeanlage. Sie verwaltet die Sirenen und die Sensoren, d.h. sie übernimmt für diese die Object
Ownership. Es gibt genau eine Sirene pro Stockwerk und eine Aussensirene, diesen können Sie statisch zur
Klasse hinzufügen (als Objektvariable). Die Sensorkonfiguration hingegen ist ständigen Änderungen unterworfen, daher soll deren Verwaltung über einen dynamische Datencontainer erfolgen. Wählen Sie selbstständig einen passenden Datencontainer aus (kleiner Tipp: verwenden Sie am besten für jedes Stockwerk einen eigenen Datencontainer).


• Objektfunktionen:
▪ Building(int floors): Konstruktor, dem die Anzahl der Stockwerke übergeben wird.
▪ int addSensor(int floor, Sensor* sensor): Fügt einen neuen Sensor zum
angegebenen Stockwerk hinzu (Nummerierung startet bei 0). Der Rückgabewert ist eine ID, die
den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert (ID muss nur innerhalb eines
Stockwerks eindeutig sein, geeignete ID selbstständig wählen).
▪ Sensor* getSensor(int floor, int id): Gibt den Sensor im angegebenen Stockwerk mit
der angegebenen ID zurück.
▪ void deleteSensor(int floor, int id): Zerstört den Sensor im angegebenen Stockwerk
mit der angegebenen ID.
▪ void checkSensors(): Überprüft alle Sensoren in allen Stockwerken. Diese Funktion wird in
regelmäßigen Zeitabständen aufgerufen (z.B. alle Sekunden). Der Zweck dieser Funktion ist es,
Brände zu erkennen und darauf zu reagieren.
▪ void cancelAlarm(): Schaltet alle Sirenen wieder aus.
 */


class Building {

protected:
    // Datencontainer für Sensoren, doppelte map
    /*Die äußere std::map repräsentiert die Stockwerke
     * (mit der Stockwerksnummer als Schlüssel), und die innere std::map
     * repräsentiert die Sensoren innerhalb eines Stockwerks
     * (mit der Sensor-ID als Schlüssel). Diese Struktur ermöglicht es
     * Ihnen, für jedes Stockwerk einen eigenen Datencontainer zu haben,
     * wie in der Anforderung vorgeschlagen. Sie können Sensoren hinzufügen,
     * abrufen und löschen, indem Sie auf den entsprechenden Stockwerk-
     * und Sensor-Schlüssel zugreifen.*/
    std::map<int, std::map<int, Sensor*>> sensors;

    // Anzahl der Stockwerke
    int floors;


    // eine Sirene pro Stockwerk
    std::map<int, Siren> sirens;


public:
    //Aussensirene
    Siren AussenSirene;


    //Konstruktor, dem die Anzahl der Stockwerke übergeben wird.
    Building(int floors);


    //Fügt einen neuen Sensor zum
    //angegebenen Stockwerk hinzu (Nummerierung startet bei 0). Der Rückgabewert ist eine ID, die
    //den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert (ID muss nur innerhalb eines
    //Stockwerks eindeutig sein, geeignete ID selbstständig wählen).
    int addSensor(int floor, Sensor* sensor);


    //Gibt den Sensor im angegebenen Stockwerk mit der angegebenen ID zurück.
    Sensor* getSensor(int floor, int id);

    //Zerstört den Sensor im angegebenen Stockwerk
    //mit der angegebenen ID.
    void deleteSensor(int floor, int id);


    //Überprüft alle Sensoren in allen Stockwerken. Diese Funktion wird in
    //regelmäßigen Zeitabständen aufgerufen (z.B. alle Sekunden). Der Zweck dieser Funktion ist es,
    //Brände zu erkennen und darauf zu reagieren.
    void checkSensors();


    //Schaltet alle Sirenen wieder aus.
    void cancelAlarm();





};



#endif //BRANDMELDER_BUILDING_H

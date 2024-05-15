//
// Created by Claudia Steiner on 14.05.24.
//

#include "Building.h"
#include <unistd.h>




//Konstruktor, dem die Anzahl der Stockwerke übergeben wird.
Building::Building(int floors) {

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Ein wunderschönes Gebäude mit " << floors << " Stockwerken wird gebaut..." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    // Erstelle eine Sirene für jedes Stockwerk
    for(int i = 0; i < floors; i++) {
        sirens[i] = Siren();

        std::cout << "Sirene für Stockwerk " << i << " montiert" << std::endl;

        //Außensirene wird auch montiert
        AussenSirene = Siren();
        std::cout << "AussenSirene montiert" << std::endl;
    }
}


//Fügt einen neuen Sensor zum
//angegebenen Stockwerk hinzu (Nummerierung startet bei 0). Der Rückgabewert ist eine ID, die
//den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert (ID muss nur innerhalb eines
//Stockwerks eindeutig sein, geeignete ID selbstständig wählen).
int Building::addSensor(int floor, Sensor *sensor) {
    // Get the current number of sensors on the floor to use as the ID for the new sensor
    int id = sensors[floor].size();

    // Add the sensor to the map
    sensors[floor][id] = sensor;

    std::cout << "Sensor hinzugefügt: Stockwerk " << floor << ", ID " << id << std::endl;

    // Return the ID
    return id++;
}




//Gibt den Sensor im angegebenen Stockwerk mit
//der angegebenen ID zurück.
Sensor *Building::getSensor(int floor, int id) {
    // Check if the floor exists
    if(sensors.find(floor) == sensors.end()) {
        throw InvalidFloorException("Sensor *Building::getSensor Stockwerk existiert nicht");
    }

    // Check if the sensor exists
    if(sensors[floor].find(id) == sensors[floor].end()) {
        throw InvalidSensorException("Sensor *Building::getSensor Sensor existiert nicht");
    }

    std::cout << "Sensor gefunden: Stockwerk " << floor << ", ID " << id << std::endl;
    // Return the sensor
    return sensors[floor][id];
}


// Zerstört den Sensor im angegebenen Stockwerk
//mit der angegebenen ID.
void Building::deleteSensor(int floor, int id) {
    // Check if the floor exists
    if(sensors.find(floor) == sensors.end()) {
        throw InvalidFloorException("void Building::deleteSensor Stockwerk existiert nicht");
    }

    // Check if the sensor exists
    if(sensors[floor].find(id) == sensors[floor].end()) {
        throw InvalidSensorException("void Building::deleteSensor Sensor existiert nicht");
    }

    // Delete the sensor
    sensors[floor].erase(id);

    std::cout << "Sensor gelöscht: Stockwerk " << floor << ", ID " << id << std::endl;
}



//Überprüft alle Sensoren in allen Stockwerken. Diese Funktion wird in
//regelmäßigen Zeitabständen aufgerufen (z.B. alle Sekunden). Der Zweck dieser Funktion ist es,
//Brände zu erkennen und darauf zu reagieren.
void Building::checkSensors() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Sensoren überprüfen...." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    //für 30 interationen wird die Funktion aufgerufen
    for (int i = 0; i < 30; i++) {

        std::cout << "-----> Iteration " << i << std::endl;

        // Check if the sensor exists
if(!sensors.empty()) {
std::cout << "mindestens ein Sensor vorhanden - es wird checkt... " << std::endl;
        // Iterate through all floors
        for (auto &floor: sensors) {


            // Iterate through all sensors on the floor
            for (auto it = floor.second.begin(); it != floor.second.end(); /* no increment here */) {
                // Check the sensor
                try {
                    it->second->checkSensor();
                    ++it; // Only increment the iterator if no exception was thrown
                } catch (FireDetectedException &e) {
                    // If a fire is detected, trigger the alarm
                    std::cout << e.what() << std::endl;
                    sirens[floor.first].switchOn();
                    //außen sirene wird auch aktiviert
                    AussenSirene.switchOn();
                    std::cout << "AussenSirene wird aktiviert! BRANDALARM!" << std::endl;
                    ++it; // Increment the iterator even if an exception was thrown
                } catch (ErrorDetectedException &e) {
                    // If an error is detected, delete the sensor
                    std::cout << e.what() << std::endl;
                    delete it->second; // Delete the sensor object
                    it = floor.second.erase(it); // Erase the sensor from the map and update the iterator
                }
            }
        } // End of sensor check
        if (i == 29) {
            std::cout << "----------------------------------------------------" << std::endl;
            std::cout << "alle Brände gelöscht, alle Sirenen werden wieder ausgeschlaten..." << std::endl;
            cancelAlarm();
            std::cout << "----------------------------------------------------" << std::endl;
        }

        // Sleep for one second
        sleep(1);

    }
    else {
        std::cout << "Keine Sensoren mehr vorhanden" << std::endl;
        break;
    }
    }

}



//Schaltet alle Sirenen wieder aus.
void Building::cancelAlarm() {
    // Iterate through all sirens and turn them off
    for(auto siren : sirens) {
        siren.second.switchOff();
    }

}



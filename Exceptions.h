//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef BRANDMELDER_EXCEPTIONS_H
#define BRANDMELDER_EXCEPTIONS_H


#include <stdexcept>
#include <string>
#include <iostream>

//klasse FactoryException erbt von runtime_error und gibt die Fehlermeldung dessen Konstruktor
class FireException : public std::runtime_error {
public:
    explicit FireException(const std::string& message) : std::runtime_error(message) {}
};


class FireDetectedException : public FireException {
public:
    explicit FireDetectedException(const std::string& message) : FireException(message) {}

};


class ErrorDetectedException   : public FireException {
public:
    explicit ErrorDetectedException (const std::string& message) : FireException(message) {}

};

class InvalidFloorException : public FireException {
public:
    explicit InvalidFloorException(const std::string& message) : FireException(message) {}
};

class InvalidSensorException : public FireException {
public:
    explicit InvalidSensorException(const std::string& message) : FireException(message) {}
};




#endif //BRANDMELDER_EXCEPTIONS_H

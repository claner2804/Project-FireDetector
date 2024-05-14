cmake_minimum_required(VERSION 3.27)
project(Brandmelder)

set(CMAKE_CXX_STANDARD 17)

add_executable(Brandmelder main.cpp
        Exceptions.h
        Siren.h
        Siren.cpp
        Building.h
        Building.cpp
        Sensor.h
        Sensor.cpp
        SmokeDetector.h
        SmokeDetector.cpp
        InfraredSensor.h
        InfraredSensor.cpp)

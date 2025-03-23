// CubeSatInitializer.h

/******************************************************************************
    CubeSatInitializer Class Header

    Purpose: 
        Contains methods for initializing a CubeSat module. This allows us to
        read data from the SD card and properly initialize the module as
        either a regular CubeSat module or a hub, or handle pre-flight
        configuration errors.
    Methods:
        initializeCubeSat:
            Creates a new CubeSat module object using data stored
            on the SD card. 
******************************************************************************/

#ifndef CUBESAT_Initializer_H
#define CUBESAT_Initializer_H

#include <vector>
#include <ArduinoJson.h>
#include <memory>
#include "CubeSatDevice.h"

class CubeSatModule;

class CubeSatInitializer
{
    public:
        CubeSatInitializer();

        // Creates a new CubeSat module object using data stored
        // on the SD card.
        CubeSatModule* initializeCubeSat();
};

#endif
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
        initializeSDCard:
            Ensures SD card is connected and prepares it for read/write
        loadConfig:
            Loads an object from the configuration file stored on the SD card.
        errorBlink:
            Causes the primary LED to blink, indicating an unrecoverable
            error.
******************************************************************************/

#ifndef CUBESAT_Initializer_H
#define CUBESAT_Initializer_H

#include <vector>
#include <ArduinoJson.h>
#include <CubeSat.h>

class CubeSatInitializer
{
    public:
        CubeSatInitializer();

        void initializeCubeSat();
        bool initializeSdCard();

        JsonDocument loadConfig();

        void errorBlink();

    private:
        int id;
        bool isHub;
        std::vector<CubeSatDevice> devices;
};

#endif
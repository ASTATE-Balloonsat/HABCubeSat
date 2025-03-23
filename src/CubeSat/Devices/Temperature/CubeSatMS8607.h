// CubeSatMS8607.h

/******************************************************************************
    MS8607 Temperature/Pressure/Humidity Sensor Header File

    Purpose: 
        CubeSatDevice Subclass. Handles parsing data from a MS8607
        Temperature/Pressure/Humidity sensor.
    Attributes:
        humidityResolution: 
            ms8607_humidity_resolution_t - Resolution of humidity sensor
                                           reading.
        pressureResolution: 
            ms8607_pressure_resolution_t - Resolution of pressure sensor
                                           reading.
        device: Adafruit_MS8607          - Object representing the MS8607
                                           sensor.
    Methods:
        initializeDevice:
            Virtual method to set up device.
        readSensor:
            Virtual method to read data from the device and append it to
            the device's datastream.
******************************************************************************/

#ifndef CUBESAT_MS8607_H
#define CUBESAT_MS8607_H

#include <string>
#include <Adafruit_MS8607.h>
#include "../../CubeSatDevice.h"
#include "../../CubeSatDeviceTypes.h"

struct CubeSatMS8607Config 
{
    ms8607_humidity_resolution_t humidityResolution = MS8607_HUMIDITY_RESOLUTION_OSR_8b;
    ms8607_pressure_resolution_t pressureResolution = MS8607_PRESSURE_RESOLUTION_OSR_4096;
};

class CubeSatMS8607 : public CubeSatDevice
{
    public:
        CubeSatMS8607(int deviceId) 
            : CubeSatDevice(deviceId, CubeSatDeviceTypes::MS8607), 
            humidityResolution(MS8607_HUMIDITY_RESOLUTION_OSR_8b), 
            pressureResolution(MS8607_PRESSURE_RESOLUTION_OSR_4096) 
        {
            CubeSatMS8607Config defaultConfig;
            initializeDevice(&defaultConfig);
        }

        // Constructor with configuration
        CubeSatMS8607(int deviceId, CubeSatMS8607Config config)
            : CubeSatDevice(deviceId, CubeSatDeviceTypes::MS8607), 
            humidityResolution(config.humidityResolution), 
            pressureResolution(config.pressureResolution) 
        {
            initializeDevice(&config);
        }

        virtual void initializeDevice(void* config);
        virtual std::string readSensor();

    private:
        int humidityResolution;
        int pressureResolution;
        Adafruit_MS8607 device;
};

#endif
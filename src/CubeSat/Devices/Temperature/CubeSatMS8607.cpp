// CubeSatMS8607.cpp

/******************************************************************************
    MS8607 Temperature/Pressure/Humidity Sensor Implementation File

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

#include "CubeSatMS8607.h"
#include "../../CubeSatDataDiscriminators.h"
#include <Adafruit_MS8607.h>
#include <Arduino.h>

void CubeSatMS8607::initializeDevice(void* config)
{
    CubeSatMS8607Config* ms8607Config = static_cast<CubeSatMS8607Config*>(config);
    setStatus(device.begin());
    device.setHumidityResolution(ms8607Config->humidityResolution);
    device.setPressureResolution(ms8607Config->pressureResolution);
}

std::string CubeSatMS8607::readSensor()
{
    try
    {
        sensors_event_t temp, pressure, humidity;
        try
        {
        this->device.getEvent(&pressure, &temp, &humidity);

        }
        catch(...)
        {

        }

        double temperatureVal = temp.temperature;
        double pressureVal = pressure.pressure;
        double humidityVal = humidity.relative_humidity;

        return(
                std::to_string(temperatureVal) + 
                CubeSatDataDiscriminators::DATUM_DISCRIMINATOR +
                std::to_string(pressureVal) +
                CubeSatDataDiscriminators::DATUM_DISCRIMINATOR +
                std::to_string(humidityVal)
              );
    }
    catch(...)
    {
        setStatus(0);
    }
    return "";
}
// CubeSatDevice.h

/******************************************************************************
    CubeSatDevice Class Header

    Purpose: 
        Represents an individual device attached to a CubeSat module.
    Attributes:
        deviceId:   integer - The unique ID of the device. Assigned by the
                              CubeSat module.
        deviceType: char*   - A character array corresponding to the type of 
                              device. Used to determine the structure of 
                              device's data stream.
        status:     boolean - A boolean value representing whether or not the
                              device is online.
        dataStream: string  - Stream of data output by the device in a comma-
                              separated string.
    Methods:
        initializeDevice:
            Virtual method to set up the device for reading data.
        readSensor:
            Virtual method to read data from the device.
        refreshDataStream:
            Refreshes the datastream with new readings from the device
            using the readSensor function.
******************************************************************************/

#ifndef CUBESAT_DEVICE_H
#define CUBESAT_DEVICE_H

#include <string>

class CubeSatDevice
{
    public:
        // Constructor
        CubeSatDevice(int deviceId, const char* deviceType);

        // Virtual function to initialize a device.
        virtual void initializeDevice(void* config) = 0;

        // Virtual function to read a sensor device.
        virtual std::string readSensor() = 0;

        // Update the data stream
        void refreshDataStream();
        
        // Getters
        int getDeviceId();
        int getDeviceType();
        bool getStatus();
        std::string getDataStream();

        // Setters
        void setStatus(bool status);

    private:
        int deviceId;
        const char* deviceType;
        bool status = 0;
        std::string dataStream = "";
};

#endif
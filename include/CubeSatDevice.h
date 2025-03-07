// CubeSatDevice.h

/******************************************************************************
    CubeSatDevice Class Header

    Purpose: 
        Represents an individual device attached to a CubeSat module.
    Attributes:
        id:         integer - The unique ID of the device. Assigned by the
                              CubeSat module.

        deviceType: integer - An integer corresponding to the type of device.
                              Used to determine the structure of device's
                              data stream.

        dataStream: string  - Stream of data output by the device in a comma-
                              separated string.
******************************************************************************/

#ifndef CUBESAT_DEVICE_H
#define CUBESAT_DEVICE_H

#include <string>

class CubeSatDevice
{
    public:
        // Constructor
        CubeSatDevice(int id, int deviceType);

        // Update the data stream
        void setDataStream(std::string dataStream);
        
        // Getters
        int getId();
        int getDeviceType();
        std::string getDataStream();

    private:
        int id;
        int deviceType;
        std::string dataStream;
};

#endif
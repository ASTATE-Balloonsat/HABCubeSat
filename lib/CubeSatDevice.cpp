// CubeSatDevice.cpp

/******************************************************************************
    CubeSatDevice Class Implementation

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
    Methods:
        setDataStream:
            Reads the latest data stream from the device and stores it within
            the object for collation.
        getID:
            Returns the device ID
        getDataStream:
            Returns the data stream as it is currently stored in the object.
******************************************************************************/

#include <CubeSat.h>

// Constructor
CubeSatDevice::CubeSatDevice(int id, int deviceType)
{
    this->id = id;
    this->deviceType = deviceType;
};

// Update the data stream
void CubeSatDevice::setDataStream(std::string dataStream) 
{ 
    this->dataStream = dataStream; 
};

// getters
int CubeSatDevice::getId() { return this->id; };
std::string CubeSatDevice::getDataStream() { return this->dataStream; };


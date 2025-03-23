// CubeSatDevice.cpp

/******************************************************************************
    CubeSatDevice Class Implementation

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
        refreshDataStream:
            Refreshes the datastream with new readings from the device.
******************************************************************************/

#include "CubeSatDevice.h"
#include "CubeSatDataDiscriminators.h"

// Constructor
CubeSatDevice::CubeSatDevice(int deviceId, const char* deviceType)
{
    this->deviceId = deviceId;
    this->deviceType = deviceType;
    this->status = true;
};

// Set device status
void CubeSatDevice::setStatus(bool status)
{
    this->status = status;
}

// Update the data stream
void CubeSatDevice::refreshDataStream() 
{ 
    this->dataStream = this->readSensor() += CubeSatDataDiscriminators::DEVICE_DISCRIMINATOR;
};

// getters
int CubeSatDevice::getDeviceId() { return this->deviceId; };
bool CubeSatDevice::getStatus() { return this->status; };
std::string CubeSatDevice::getDataStream() { return this->dataStream; };


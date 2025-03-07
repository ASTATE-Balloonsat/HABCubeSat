// CubeSatModule.cpp

/******************************************************************************
    CubeSatModule Class Implementation

    Purpose: 
        Represents a CubeSat module. Receives data from its connected devices,
        packages the data into a combined datastream, and sends the collated
        datastream to the CubeSat acting as the hub. Optionally saves data
        to a database stored in on-board storage.
    Attributes:
        id:         integer - The unique ID of the CubeSat. Retreived from
                              local storage or assigned by the hub module.

        isHub:      bool    - Boolean value corresponding to whether or not
                              the module is a hub.

        dataStream: string  - Data stream containing the collated data streams
                              of the CubeSat's connected devices.
        
        devices:    vector<device> - Vector of CubeSatDevice objects.
    Methods:
        addDevice:
            Adds a new device object to the devices vector. Typically done
            on initialization by the CubeSatInitializer.
        getId:
            Returns the id of the module. 
        getDevices:
            Returns the devices vector.
        getDataStream:
            Returns a collation of data streams from all devices connected
            to the module.
        checkIsHub:
            Returns a boolean value corresponding to whether or not the
            module is a hub.
******************************************************************************/

#include <SD.h>
#include <CubeSat.h>

// Constructor
CubeSatModule::CubeSatModule(bool isHub, int id) : isHub(isHub), id(id) {};

// Devices should be loaded from device list on initialization
void CubeSatModule::addDevice(CubeSatDevice device)
{
    devices.push_back(device);
};

// Get unique device ID
int CubeSatModule::getId() { return this->id; };

// Returns a list of currently loaded devices
std::vector<CubeSatDevice> CubeSatModule::getDevices() { return this->devices; };

std::string CubeSatModule::getDataStream() { return this->dataStream; };
// Check if the module is a hub
bool CubeSatModule::checkIsHub() { return this->isHub; };


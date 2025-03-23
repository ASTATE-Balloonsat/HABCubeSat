// CubeSatModule.cpp

/******************************************************************************
    CubeSatModule Class Implementation

    Purpose: 
        Represents a CubeSat module. Receives data from its connected devices,
        packages the data into a combined datastream, and sends the collated
        datastream to the CubeSat acting as the hub. Optionally, saves data
        to a database stored in on-board storage.
    Attributes:
        moduleId:   integer        - The unique ID of the CubeSat. Retreived 
                                     from local storage or assigned by the hub 
                                     module.

        isHub:      bool           - Boolean value corresponding to whether or not
                                     the module is a hub.

        dataStream: string         - Data stream containing the collated data streams
                                     of the CubeSat's connected devices.

        devices:    vector<device> - Vector of CubeSatDevice objects.
    Methods:
        getModuleId:
            Returns the id of the module.

        getDevices:
            Returns the devices vector.

        getDataStream:
            Returns a collation of data streams from all devices connected
            to the module.

        checkIsHub:
            Returns a boolean value corresponding to whether or not the
            module is a hub.
        
        refreshDataStream:
            Iterates through devices vector and updates the module's
            dataStream with the collated device dataStreams. 
******************************************************************************/

#include <SD.h>
#include "CubeSatModule.h"
#include "CubeSatDataDiscriminators.h"

CubeSatModule::CubeSatModule
    (bool isHub, int moduleId, std::vector<CubeSatDevice*> devices): 
    isHub(isHub), moduleId(moduleId), devices(devices) {}


// Returns the id of the module.
int CubeSatModule::getModuleId() 
{ 
    return this->moduleId; 
}

// Returns the devices vector.
std::vector<CubeSatDevice*> CubeSatModule::getDevices()
{ 
    return this->devices; 
}

// Returns a collation of data streams from all devices connected
// to the module.
std::string CubeSatModule::getDataStream()
{ 
    return this->dataStream; 
}

// Returns a boolean value corresponding to whether or not the
// module is a hub.
bool CubeSatModule::checkIsHub()
{ 
    return this->isHub; 
}

// Iterates through devices vector and updates the module's
// dataStream with the collated device dataStreams. 
void CubeSatModule::refreshDataStream()
{
    // Cast the module Id as a string and tack it on to the beginning of
    // the datastream.
    dataStream = std::to_string(moduleId) 
        + CubeSatDataDiscriminators::DEVICE_DISCRIMINATOR;

    // Iterate through devices
    for (CubeSatDevice* device : devices)
    {
        // If device is collecting data
        if (device->getStatus())
        {
            try
            {
                // Append device's datastream
                device->refreshDataStream();
                dataStream += device->getDataStream();
            }
            catch(...){}
        }
    }

    // Append discriminator to signal end of module data
    dataStream += CubeSatDataDiscriminators::MODULE_DISCRIMINATOR;
}
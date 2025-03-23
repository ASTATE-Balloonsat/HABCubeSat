// CubeSatModule.h

/******************************************************************************
    CubeSatModule Class Header

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

#ifndef CUBESAT_MODULE_H
#define CUBESAT_MODULE_H

#include <string>
#include <vector>
#include <memory>
#include "CubeSatDevice.h"

class CubeSatModule
{
    public:
        CubeSatModule(bool isHub, int moduleId, std::vector<CubeSatDevice*> devices);

        // Returns the id of the module.
        int getModuleId();

        // Returns the devices vector.
        std::vector<CubeSatDevice*> getDevices();

        // Returns a collation of data streams from all devices connected 
        // to the module.
        std::string getDataStream();

        // Returns a boolean value corresponding to whether or not the
        // module is a hub.
        bool checkIsHub();

        // Iterates through devices vector and updates the module's
        // dataStream with the collated device dataStreams.
        void refreshDataStream();

    private:

        // The unique ID of the CubeSat. Retrieved from 
        // local storage or assigned by the hub module.
        int moduleId;

        // Boolean value corresponding to whether or not
        // the module is a hub.
        bool isHub;

        // Data stream containing the collated data streams
        // of the CubeSat's connected devices.
        std::string dataStream = "";

        // Vector of CubeSatDevice objects.
        std::vector<CubeSatDevice*> devices;
};

#endif
// CubeSatModule.cpp

/******************************************************************************
    CubeSatModule Class Header

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

#ifndef CUBESAT_MODULE_H
#define CUBESAT_MODULE_H

#include <string>
#include <vector>
#include <CubeSatDevice.h>

class CubeSatModule
{
    public:
        CubeSatModule(bool isHub, int id);

        void addDevice(CubeSatDevice device);

        int getId();
        std::vector<CubeSatDevice> getDevices();
        std::string getDataStream();

        bool checkIsHub();

    private:
        int id;
        bool isHub;
        std::string dataStream;
        std::vector<CubeSatDevice> devices;
};

#endif
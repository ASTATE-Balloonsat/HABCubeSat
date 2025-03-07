// CubeSatHub.h

/******************************************************************************
    CubeSatHub Class Header

    Purpose: 
        CubeSat subclass. Represents a CubeSat device acting as the hub. 
        A CubeSat hub should receive data from other CubeSat devices and 
        send data, including its own, to the ground-station transmission medium.
    Attributes:
        id:         integer - The unique ID of the device. Assigned by the
                              CubeSat module.
        deviceType: integer - An integer corresponding to the type of device.
                              Used to determine the structure of device's
                              data stream.
        dataStream: string  - Stream of data output by the device in a comma-
                              separated string.
******************************************************************************/

#ifndef CUBESAT_HUB_H
#define CUBESAT_HUB_H

#include <CubeSat.h>

class CubeSatHub : public CubeSatModule
{
    public:
        CubeSatHub::CubeSatHub(int id) : CubeSatModule(true, id) {}
};

#endif